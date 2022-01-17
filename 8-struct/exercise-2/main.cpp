#include <iostream>

struct Computer {
    
    int price;

    Computer(int _price): price(_price) {}
};

struct MacBook: Computer {

    MacBook(int _price): Computer(_price) {}
};

struct Tool {};

int main() {

    MacBook book(6000);

    std::cout << "MacBook price: " << book.price << std::endl;

    Tool t;
    std::cout << "Tool size: " << sizeof(t) << std::endl;
}

// 运行代码 make run c=8 e=2

// 运行成功🎉

// 可见默认继承方式是 public的；

// 第10行 改成private继承，再运行下代码，体验下吧