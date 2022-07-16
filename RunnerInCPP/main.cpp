#include <iostream>
// 使用 std::stringstream 必备
#include <sstream>
#include <regex>
#include <string>
#include <vector>
// 使用 std::chrono:high_resolution_clock std::chrono::duration 必备
#include <chrono>

// 使用 DIR dirent opendir readdir closedir 必备
#include <dirent.h>
// pid_t fork waitpid write close read execl exevp pipe dup2 必备
#include <unistd.h>
// 使用 stat 必备
#include <sys/stat.h>


std::string getDir(std::string key, std::string reg) {

    // 打开目录，返回目录描述符
    DIR* dir = opendir(key.c_str());
    if (dir == NULL) {
        std::cerr << "cannot open the directory: " << key << std::endl;
        exit(1);
    }
    
    // 创建正则表达式对象，用于后续文件夹名匹配；
    // c++的正则表达式好难用啊
    std::regex r(reg);

    // 每调用readdir，得到的entry将指向目录中下一个目录项，
    // 当整个目录读取完毕后，将返回NULL
    dirent* entry = readdir(dir);
    while(entry != NULL){
        // 当前目录项是文件夹
        if(entry->d_type == DT_DIR && std::regex_match(entry->d_name, r)) {
            std::string dirname(entry->d_name);
            return dirname;
        }
        entry = readdir(dir);
    };
    closedir(dir);
    return "";
}


std::string getCompileDir(uint16_t chapterId, uint16_t exerciseId) {
    // 构造正则表达式匹配规则
    std::stringstream s;
    s << chapterId << "-.*?$";
    
    // 在当前目录寻找chapter目录
    std::string chapterDir = getDir("./",s.str());
    if (chapterDir.empty()) {
        std::cerr << "cannot find the chapter directory " << std::endl;
        exit(1);
    }

    // 清空 s
    s.str("");

    // 重新设置正则表达式
    s << "exercise-" << exerciseId << "($|-.*?$)";

    // 在chapterDir目录下，获取exercise目录
    std::string exerciseDir = getDir(chapterDir, s.str());
    
    chapterDir.push_back('/');
    chapterDir.append(exerciseDir);
    return chapterDir;
}


void compile(std::string& compileDir) {
    std::stringstream s;
    s << compileDir << "/main";
    std::vector<std::string> args = { "g++", "-std=c++11", "-I", compileDir, "-o", s.str() };
    s.str("");

    DIR* dir = opendir(compileDir.c_str());
    dirent* entry = readdir(dir);
    std::regex r(".*?\\.cpp$");
    while(entry != NULL) {
        
        if(entry->d_type == DT_REG &&  std::regex_match(entry->d_name, r)) {
           s << compileDir << "/" << entry->d_name;
           args.push_back(s.str());
           s.str("");
        }
        entry = readdir(dir);
    }
    closedir(dir);

    pid_t child = fork();
    // 子进程
    if (child == 0) {
        const int size = args.size();
        char** arg=(char**)malloc(sizeof(const char*)*size);
        for (int i = 0; i < size; i++) {
            arg[i] = (char* )args[i].c_str();
        }
        
        // important👏
        // 注意： arg第一个元素也是 "g++".
        // 就像本文件编译之后得到二进制文件 main，在执行main送入参数的时候，执行 main --chapter 1 --exercise 1
        // 那么main函数中的 argv其实等于 { "main", "--chapter", "1", "--exercise", "1"}.
        // execvp的第二个参数就是 argv 表达的意思一致，因此execvp在第一个参数指明“g++”后，在argv[0]也要指明“g++”
        int result = execvp("g++", arg);
        if(result < 0) {
            std::cerr << "faile to compile .cpp files int " << compileDir << std::endl;
            free(arg);
            exit(1);
        }
    } 
     // 父进程
    else {
        waitpid(child, NULL, 0);
        // char buff[512];
        // char* cwd = getcwd(buff, 512);
        // if (cwd == NULL) {
        //     std::cerr << "读取当前进程工作文件夹发生错误" << std::endl;
        //     exit(1);
        // }
        
        s << "./" << compileDir << "/main";
        struct stat filestat;
        int result = stat(s.str().c_str(), &filestat);
        if (result < 0 || (filestat.st_mode & S_IFMT) != S_IFREG) {
            std::cerr << s.str() << " 不存在!" << std::endl;
            exit(1);
        }
    }

}

// 打印要编译的cpp文件
void echoCompileFile(std::string& compileDir) {
    DIR* dir = opendir(compileDir.c_str());
    dirent* entry = readdir(dir);
    std::regex r(".*?\\.cpp$");
   
    while(entry != NULL) {

        if(entry->d_type == DT_REG &&  std::regex_match(entry->d_name, r)) {
            std::cout << compileDir << "/" << entry->d_name << std::endl;
        }

        entry = readdir(dir);
    }
    closedir(dir);
    std::cout << "\n";
}

// 运行编译好的二进制文件，并删除该二进制文件
void run(std::string& compileDir) {
    std::cout << "编译文件..." << std::endl;
    echoCompileFile(compileDir);
    compile(compileDir);
    std::cout << "编译成功!\n" << std::endl;
    
    std::cout << "执行结果:" << std::endl;
    
    // 创建管道；
    // 将子进程标准输出传送到当前进程；
    int fd[2];
    if(pipe(fd) < 0) {
        std::cerr << "运行二进制文件时，创建管道失败" << std::endl;
        exit(1);
    };

    // 存储编译好的二进制文件路径，子进程执行时需要它，
    // 当前进程删除该二进制文件也需要它！
    std::stringstream s;
    s << "./" << compileDir << "/main";

    pid_t child = fork();
    // 子进程
    if(child == 0) {
        // 关闭输入端，保留输出端
        close(fd[0]);

        // 将子进程标准输出端映射到管道写入端
        if (fd[1] != STDOUT_FILENO) {
            if(dup2(fd[1], STDOUT_FILENO) != STDOUT_FILENO) {
                std::cerr << "运行二进制文件时，子进程标准输出映射失败" << std::endl;
                exit(1);
            }
        }
       
       // 调用execl方法成功后，代码段、数据段将被替换，后边的 if语句将不会执行；
       // 如果execl方法发生错误，后边的 if语句会执行；
        int result = execl(s.str().c_str(), NULL);
        if (result < 0) {
            std::cerr << "cannot run the executable file : " << compileDir << "/main" << std::endl;
            close(fd[1]);
            exit(1);
        }
    }
    // 父进程， 也就是当前进程
    else {
        // 关闭管道写入端，保留读取端；
        close(fd[1]);
        // 等待子进程结束
        waitpid(child, NULL, 0);
        // 子进程结束后，可以从 fd[0]中读取数据啦
        char buff[256];
        int size = 0;
        while((size = read(fd[0], buff, 255) ) > 0) {
            buff[size] = '\0';
            // 输出到父进程的标准输出
            write(STDOUT_FILENO, buff, size);
        }
        close(fd[0]);

        if (remove(s.str().c_str()) < 0) {
            std::cerr << "删除二进制文件 " << s.str() << "失败" << std::endl;
            exit(1);
        }
    }
}

// 打印命令行帮助信息
void showHelpTips() {

    std::cout << "Tips:\n" << std::endl;
    std::cout << "--help    \t\t" << "show this tip message\n" << std::endl;
    std::cout << "--chapter \t\t" << "指定要执行代码的章节编号\n\r         \t\texample: --chapter 3 or --chapter=3  默认值0\n" << std::endl;
    std::cout << "--exercise\t\t" << "指定要执行代码的exercise编号\n\r         \t\texample: --exercise 3 or --exercise=3 默认值0\n" << std::endl;
    std::cout << "--showtime\t\t" << "显示执行代码花费的时间" << std::endl;
    std::cout << std::endl;
    std::cout << "For Example: \n"\
    "如果我想执行1-variable exercise-1-基本变量的cpp代码， run-executable --chapter 1 --exercise 1\n"\
    "如果我想在上一个的基础上，再显示一下编译、运行cpp代码总共花费多少时间， run-executable --chapter 1 --exercise 1 --showtime\n"\
    << std::endl;

} 

int main(const int argc, const char** argv) {
    uint16_t chapterId=0, exerciseId=0;
    bool showtime = false;
    if ( argc < 2) std::cerr << "Sorry, arguments are too few, please append --help and get tips" << std::endl;
    else {
        int i = 1;
        while(i < argc) {
            if(strcmp("--help", argv[i]) == 0) {
                showHelpTips();
                return 0;
            }
            else if (strcmp("--chapter", argv[i]) == 0) {
                i++;
                chapterId = (uint16_t)atoi(argv[i]);
            }
            else if (strncmp("--chapter=", argv[i], 10) == 0) {
                chapterId = (uint16_t)atoi(argv[i] + 10);
            }
            else if (strcmp("--exercise", argv[i]) == 0) {
                i++;
                exerciseId = (uint16_t)atoi(argv[i]);
            }
            else if (strncmp("--exercise=", argv[i], 11) == 0) {
                exerciseId = (uint16_t)atoi(argv[i] + 11);
            }
            else if (strcmp("--showtime", argv[i]) == 0) {
                showtime = true;
            }
            else {}
            i++;
        }
        auto start = std::chrono::high_resolution_clock::now();
        std::string compileDir = getCompileDir(chapterId, exerciseId);
        run(compileDir);
        auto end = std::chrono::high_resolution_clock::now();
        if(showtime) {
            std::cout << std::endl;
            std::cout << "cost time: " << std::chrono::duration<double, std::milli>(end - start).count() << "ms" << std::endl;
        }
        return 0;
    }
}