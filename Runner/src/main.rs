use std::env;
use std::collections::HashMap;
use std::fs::{self, DirEntry};
use std::process::{self, Command, Stdio};

use regex::Regex;


#[derive(Debug)]
struct RunnerArgs {
    chapter_id: usize,
    exercise_id: usize,
}

impl RunnerArgs {
    fn new(chapter_id: usize, exercise_id: usize) -> Self{
        let runner_args = RunnerArgs {
            chapter_id:  chapter_id,
            exercise_id: exercise_id,
        };

        runner_args
    }

    fn from_env() -> Result<Self, String> {
        let mut i: usize = 0;
        let mut map = HashMap::new();

        let args: Vec<String> = env::args().collect();
        let args = &args[1..];

        while i < args.len() {
            match &args[i]  as &str {
                "--chapter" | "-c" => {
                    i += 1;
                    if i >= args.len() {
                        return Err(String::from("we don't find the value of --chapter or -c"));
                    }
                    let v = match args[i].parse::<usize>() {
                            Ok(value) => value,
                            Err(_) => return Err(String::from("chapter cannot transfer to the number ≥ 0"))
                    };
                    map.insert("chapter_id", v);

                },
                "--exercise" | "-e" => {
                    i += 1;
                    if i>= args.len() {
                        return Err(String::from("we don't find the value of --exercise or -e"));
                    }
                    let v = match args[i].parse::<usize>(){
                            Ok(value) => value,
                            Err(_) => return Err(String::from("exercise cannot transfer to the number ≥ 0"))
                    };
                    map.insert("exercise_id", v);
                },
                _ => {
                    let v = match args[i].parse::<usize>() {
                        Ok(value) => value,
                        Err(_) => return Err(
                            String::from("check out your command line arguments!")
                        ),
                    };

                    for key in ["chapter_id", "exercise_id"] {
                        if !map.contains_key(key) {
                            map.insert(key, v);
                            break;
                        }
                    }
                }
            }
            i += 1;
        }

        Ok(
            RunnerArgs::new( 
                *map.get(&"chapter_id").unwrap(), 
                *map.get(&"exercise_id").unwrap()
            )
        )
    }
}

fn run(args: &RunnerArgs) -> Result<&'static str, String> {
    let chapter_id: usize = args.chapter_id;
    let exercise_id: usize = args.exercise_id;

    let mut dirname: String = String::from("");
    let mut exercise_name: String = String::from("");

    let reg = Regex::new(format!("^{}-", chapter_id).as_str()).unwrap();

    for result_direntry_entry in fs::read_dir(".").unwrap() {
        match result_direntry_entry {
            Ok(direntry) => {
                if direntry.file_type()
                        .unwrap()
                        .is_dir() && 
                   reg.is_match(
                        direntry.file_name()
                                .into_string()
                                .unwrap()
                                .as_str()
                    ) {
                    dirname.push_str(direntry.file_name().to_str().unwrap());
                    break;
                }
            },
            _ => {},
        }
    }
    if dirname.is_empty() {
        println!("cannot make sure which chapter you want to run!");
        process::exit(100);
    }
    println!("本次执行涉及到的文件: ");
    match exercise_id {
        0 => {
            let cpps: Vec<String> = fs::read_dir(&dirname)
                .expect(format!("cannot read directory {}", dirname).as_str())
                .filter(|x| x.as_ref()
                // look ! 
                //  
                // m.expect方法会将 m 的所有权夺走！
                // x 是 &Result，表明Result的所有权存在于函数外
                // 一旦执行 x.expect ，所有权就会被夺去，函数外失去所有权，不安全了;
                //
                // x.as_ref方法不会夺去x的所有权，会返回一个新的 Result数据
                             .expect(format!("fail to read the file in {}", dirname).as_str())
                             .file_type()
                            .unwrap()
                            .is_file() && 
                            (x.as_ref()
                                .expect(format!("fail to read the file in {}", dirname).as_str())
                                .file_name()
                                .into_string()
                                .unwrap()
                                .ends_with(".cpp") || 
                            x.as_ref()
                                .expect(format!("fail to read the file in {}", dirname).as_str())
                                .file_name()
                                .into_string()
                                .unwrap()
                                .ends_with(".h")
                            )
                )
                .map(|x| {
                            let filename = x.expect(format!("fail to read the file in {}", dirname).as_str())
                                            .file_name()
                                            .into_string()
                                            .unwrap();
                            let filename = format!("{}/{}", dirname, filename);
                            println!("{}", filename);
                            filename
                        }
                ).collect();
            // Notice!
            // format!返回 String，
            // 但是 args中接受的类型是 &str，
            // 要 使用 String 的 as_str() 方法转化一下
            // “g++”  这种直白的字符串就是 &sr 类型
            println!("");
            println!("运行结果: ");
            
            let output_file: String = format!("{}/main", dirname);
            let include_dir: String = format!("{}/", dirname);

            // 建立一个 g++ 进程对象
            let mut command = Command::new("g++");

            // 添加g++ 中 -o -I -std 等参数
            command.args(&["-o", output_file.as_str(), "-std=c++11"]);
            command.args(&["-I", include_dir.as_str()]);

            // 添加要编译的cpp文件
            // 这里不能使用 command.args(cpps) or command.args(cpps.into_inter())；
            // 尽管这不会报错，但是也得不到任何结果，根据实际执行情况来看，这种方式根本没有
            // 将参数添加进去。
            for filename in cpps.into_iter() {
                if filename.ends_with(".cpp") {
                    command.arg(filename.as_str());
                }
            }     

            // 1、使用output方法执行子进程时，会阻塞主进程直到子进程执行完毕；
            // 2、这种方式下，子进程的标准输出并没有链接到主进程，因此子进程的结果，主进程终端看不到；
            // 
            // 因此，使用stdout方法将子进程的标准输出和父进程链接在一起，
            // 如果子进程执行成功，那么输出将打印在父进程终端，失败则主进程终止，终端会
            // 抛出 fail to run g++ to compile with files
            let mut result = command.stdout(Stdio::inherit())
                                .stderr(Stdio::inherit())
                                .output();
            match result {
                Ok(_) => {},
                Err(_) => return Err("fail to run g++ to compile with files".to_string()),
            }
        
            result = Command::new(format!("./{}/main", dirname).as_str())
                            .stdout(Stdio::inherit())
                            .stderr(Stdio::inherit())
                            .output();
            match result {
                Ok(_) => {},
                Err(_) => return Err("fail to run executable file created by g++ just now".to_string()),
            }
           

            result = Command::new("rm")
                            .args(["-f", format!("./{}/main", dirname).as_str()])
                            .output();
            match result {
                Ok(_) => return Ok(""),
                Err(_) => return Err("fail to remove the executable file".to_string()),
            }
        },
        _ => {
            let reg = Regex::new(format!("(?:-{}$|-{}-)", exercise_id, exercise_id).as_str()).unwrap();
           
            
            fs::read_dir(format!("{}", dirname))
                   .expect(format!("cannot read directory {}", dirname).as_str())
                   .filter(|x| -> bool {
                                        let dir_entry: &DirEntry =  
                                                            x.as_ref()
                                                             .expect(format!("fail to read the file in {}", dirname).as_str());
                                        
                                        dir_entry.file_type()
                                                 .unwrap()
                                                 .is_dir()
                                         &&
                                        reg.is_match(
                                                 dir_entry.file_name()
                                                          .into_string()
                                                          .unwrap()
                                                          .as_str()
                                        )
                                    }
                   )
                   .for_each(|x| {
                       if exercise_name.is_empty() {
                            let name: String = x.unwrap()
                                                .file_name()
                                                .into_string()
                                                .unwrap();
                            exercise_name.push_str(name.as_str());
                       }        
                   });    
            if exercise_name.is_empty() {
                return Err("cannot find the exercise directory".to_string());
            }          

            let cpps: Vec<String> = fs::read_dir(format!("{}/{}", dirname, exercise_name))
                                        .expect(format!("cannot read {}/{}", dirname, exercise_name).as_str())
                                        .map(|x| {
                                            
                                            let dir_entry: &DirEntry = x.as_ref().unwrap();
                                            if dir_entry.file_type().unwrap().is_file() {
                                                let filename = dir_entry.file_name().into_string().unwrap();
                                                if filename.ends_with(".h") {
                                                    println!("{}/{}/{}", dirname, exercise_name, filename); 
                                                }
                                                if filename.ends_with(".cpp") {
                                                    println!("{}/{}/{}", dirname, exercise_name, filename); 
                                                    return format!("{}/{}/{}", dirname, exercise_name, filename);
                                                }
                                            }
                                            return "".to_string();
                                        })
                                        .collect();

            println!("");
            println!("运行结果: ");
            
            let mut command = Command::new("g++");

            let output_file: String = format!("./{}/{}/main", dirname, exercise_name);
            let include_dir: String = format!("{}/{}/", dirname, exercise_name);
                    
            command.args(&["-o", output_file.as_str(), "-std=c++11"]);
            command.args(&["-I", include_dir.as_str()]);
    
            for file in cpps.into_iter() {
                if file.ends_with(".cpp") {
                    command.arg(file.as_str());
                }
            }

            let result = command.stdout(Stdio::inherit())
                                .stderr(Stdio::inherit())
                                .output();
            
            match result {
                Ok(_) => {},
                Err(_) =>  return Err(format!("fail to g++ compile files in {}/{}", dirname, exercise_name)),
            }
            
            let result = Command::new(format!("./{}/{}/main", dirname, exercise_name).as_str())
                                .stdout(Stdio::inherit())
                                .stderr(Stdio::inherit())
                                .output();
            match result {
                Ok(_) => {},
                Err(_) => return Err("fail to run the compiled executable file".to_string()),
            }

            let result = Command::new("rm")
                                 .args(["-f", format!("./{}/{}/main", dirname, exercise_name).as_str()])
                                 .output();
            match result {
                Ok(_) => return Ok(""),
                Err(_) => return Err("fail to remove the executable file".to_string()),
            }
        },    
    }
}

fn main() {
    let runner_args = RunnerArgs::from_env().expect("get wrong values of command line arguments");
    let result = run(&runner_args);
    match result {
        Ok(_) => {},
        Err(message) => {
            println!("{}", message)
        }
    }
}