#include <iostream>

extern int year;
extern const int age;

int main() {

    std::cout << "year: " << year << std::endl;

    std::cout << "age: "  << age << std::endl;
}

// 运行下吧 make run c=1 e=8

//  编译出错？

// 看看 variable.cpp 的注释建议 吧！