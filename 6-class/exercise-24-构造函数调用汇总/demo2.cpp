#include <iostream>

class Computer {
    public:
        std::string name;

    public:
        Computer(std::string _name): name(_name) {
            std::cout << "Computer[" << name << "] init" << std::endl;
        }

        Computer(Computer& computer) {
            name = computer.name + "copy";
            std::cout << "Computer[" 
                      << name 
                      << "] copy Computer[" 
                      << computer.name 
                      << "]"
                      << std::endl;
        }

        Computer(Computer&& computer) {
            std::cout << "Computer["
                      << name
                      << "] move"
                      << std::endl;
        }

        ~Computer() {
            std::cout << "Computer[" << name << "] delete" << std::endl;
        }
};

void show(Computer computer) {}

void letout(Computer &computer) {}

void offer(Computer* computer) {}

void give(Computer&& computer) {
    std::cout << computer.name << std::endl;
}


int main() {

    Computer computer("Jack");

    std::cout << "1\t" << std::endl;
    show(computer); // 执行 Computer(Computer&) 和 ~Computer()
    show(std::move(computer)); // 执行 Computer(Computer&&) 和 ～Computer()

    std::cout << "2\t" << std::endl;
    letout(computer);  // 什么都没发生

    std::cout << "3\t" << std::endl;
    offer(&computer); // 什么都没发生

    std::cout << "4\t" << std::endl;
    // 没执行 Computer(Computer&& ), 
    // 没执行 ~Computer(),
    // 只输出了Jack
    give(std::move(computer)); 
    give(computer); // 报错

}

// 进入本文件所在目录中，
// 执行 g++ demo2.cpp -o main --std=c++11 && ./main 运行代码，
// 
// 第64行代码报错，想想这是为啥？
// 注释掉第64行代码，重新运行代码，成功🎉
//
// 根据注释和输出结果，好好品味一下吧🍻