// 文件读写
#include <iostream>
#include <fstream>
#include <sys/stat.h>

int main() {
    
    int okey = mkdir("23-file/file_demo", S_IXUSR | S_IRUSR | S_IWUSR);

    if (okey < 0) {
        std::cout<<"创建文件夹失败或者该文件夹已经存在"<< std::endl;
    }


    // 写入文件

    std::ofstream output_file("./file_demo/test.txt");

    // 不要写成30，应写成29， 写成30的时候，字符串末尾的 \0也会输入到文件中
    output_file.write("this is first line, I try it\n", 29) ;
    // 也可以这样写入
    output_file << "this is second line, I adopt another method\n"\
    "this is third line, I have nothing to tell you , this line is just for "\
    "giving more chars so that when we read, buff could be filled with chars\n"\
    "by the way, MacBook Pro 14.1 is coming, we can see it next early month\n"\
    "Actually, it might appear in the special event on 2021.10.12\n"\
    "I am really expecting." << std::endl;

    if (output_file.is_open()) {
        std::cout << "output_file 还是打开着的" << std::endl;
        output_file.close();
    } else {
        std::cout<< "output_file 已经关闭了" << std::endl;
    }





    // 读取文件

    char buff[128] = {};

    std::ifstream input_file("./file_demo/test.txt");
    // read 方法是将文件中的内容读入到缓存中，之后将缓存中的
    // 127个字符写入到buff中
    input_file.read(buff, 127);
    buff[127] = '\0';
    std::cout<<"we just read 127 char:\n '" << buff << "'\n"<< std::endl;
    // readsome是将缓存中10个字符写入到buff中, 如果缓存中没有数据，那么就
    // 读不到任何东西啦
    input_file.readsome(buff, 10);
    buff[10] = '\0';
    std::cout<<"we just read 10 char:\n '" << buff << "'\n"<< std::endl;

    // 其实 buff[11]～buff[127]的内容没有删除
    std::cout << "char begin from buff[11]: '" << (buff+11) << "'\n" << std::endl;
    input_file.close();
}

// 运行代码 make run c=23