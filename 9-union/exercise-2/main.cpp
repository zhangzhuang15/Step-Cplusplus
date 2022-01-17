#include <iostream>

union Computer {
    int price;

    Computer(int _price): price(_price) {}

    virtual void echo(){}

    void show_price() { std::cout << "price: " << price << std::endl; }
};

union MacBook: Computer {};


int main() {

    MacBook book;

    Computer computer(7100);

    computer.show_price();
}

// 运行代码 make run c=9 e=2

// 第8行报错
// union不接受 virtual函数

// 第13行报错
// union不接受 继承

// 所以，注释掉第8、13、18行代码
