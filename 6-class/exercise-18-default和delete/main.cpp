#include <iostream>

class Computer {

    public:
        Computer()=default;
        Computer(Computer&)=delete;

        void echo() { std::cout << "Computer" << std::endl; }
        void watch_movie() { std::cout << "Many movies you can get" << std::endl; }
};

class MacBook: public Computer {

    public:
        void echo()=delete;

};

int main() {

    Computer c;

    Computer d = c;

    MacBook book;

    book.echo();

    book.watch_movie();
}


// 运行代码 make run c=6 e=18

// 第24行报错
// 因为第 7 行的拷贝构造函数已经被删除啦
//
// 注释第24行吧

// 第 28 行报错
// 因为第 16行 echo已经被 delete啦
//
// 注释第28行吧


// PS：default 不能用于成员函数哦