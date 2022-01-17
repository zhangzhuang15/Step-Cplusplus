#include <iostream>

class Computer {

    public:
        virtual void echo() { std::cout << "Computer" << std::endl; }

};

class MacBook {

    public:
        virtual void echo(int num) override { std::cout << "MacBook" << std::endl; }

};

int main() {

    MacBook book;
    book.echo();
}

// 运行代码 make run c=6 e=19

// 第13行报错
// override表明本函数是对父类函数的重写，一旦编译器发现这个函数并非重写，就会报错；

// 有了这个关键字就可以避免重写函数时，函数签名不匹配的错误