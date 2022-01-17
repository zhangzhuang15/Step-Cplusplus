#include <iostream>

class Computer {

    public:
        Computer(){ std::cout << "1.Computer is init" << std::endl; }
        ~Computer(){ std::cout << "2.Computer is destroying" << std::endl; }

};

class Tool {

    public:
        Tool() { std::cout << "3.Tool is init" << std::endl; }
        ~Tool() { std::cout << "4.Tool is destroyed " << std::endl; }

};

class MacBook:  Computer, Tool {

    public:
        MacBook(): Tool(), Computer() {
            std::cout << "5.MacBook is init" << std::endl;
        }

        ~MacBook() { std::cout << "6.MacBook is destroyed " << std::endl; }

        MacBook(MacBook& book) { std::cout << "7.MacBook copy constructor is invoked" << std::endl; }
};

int main() {
    MacBook m;

    MacBook n = m;
}

// 运行代码 make run c=6 e=15

// 先运行代码，看看输出的顺序

// 将第 22 行的 Tool() Computer() 交换下顺序，再运行，看看输出的顺序有没有变化

// 将第 19 行的 Computer Tool 交换下顺序，再运行，看看输出的顺序有没有变化

// 同时可以看到第 34 行发生拷贝时，会调用 Computer 和 Tool 的构造函数，之后执行 拷贝构造函数；
// 所以，在后续自定义拷贝构造函数时，不要忘了写 父类构造函数列表。