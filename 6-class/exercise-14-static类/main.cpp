#include <iostream>

class Computer {

    public:
        Computer() { std::cout << "I am just Computer" << std::endl; }
        ~Computer() { std::cout << "Goodbye, remember me still a Computer, your loyal servent! " << std::endl; }

};

int main() {

    {
       static  Computer c;
    }

    std::cout << "exit from main process" << std::endl;
}

// 运行代码 make run c=6 e=14

// 先运行代码，
// 再去掉 第 14行的 static运行一次
//
// 比较两次输出的顺序