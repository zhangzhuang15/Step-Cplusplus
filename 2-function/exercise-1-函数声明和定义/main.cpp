#include <iostream>


// void print(std::string s);
// void print(int number);
// void print(bool sex);

int main() {

    print(20);

    
    print("hello world");

    print(false);
}


void print(std::string s) {
    std::cout << s << std::endl;
}


void print(int number) {
    std::cout << "number: " << number << std::endl;
}


void print(bool sex) {
    std::string expression = sex? "男":"女";
    std::cout << "性别: " << expression << std::endl;
}


// 运行本代码 make run c=2 e=1

// 报错了？
// 那是肯定的啦，函数也要遵从 先声明、后使用

// 比着急把注释全部打开呢！

// 打开第6行代码，运行一下，看看结果

// 再打开第5行代码，运行一下，看看结果

// 再打开第4行代码，运行一下，看看结果

// 得到的结果可能会令你很吃惊

// 将第15、16行代码改为
//
// std::string message("hello world");
// print(message);
//
// 运行一下，看看结果

//
// 定义函数的时候一定要心啊