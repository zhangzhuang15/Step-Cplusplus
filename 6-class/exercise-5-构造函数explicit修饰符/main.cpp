#include <iostream>

class Computer {

    private:
       int kind;

    public:

       explicit Computer(bool sort) {
           if(sort) this->kind = 10;
           else this->kind = 20;
       }

       void echo() {
           std::cout << "kind: " << kind << std::endl;
       }

};

int main() {
    Computer computer(false);
    computer.echo();

    Computer computer_("this is");
    computer_.echo();

    Computer computer__{false};
    computer__.echo();

    Computer computer___ = {false};
    computer___.echo();
}

//
// 运行代码 make run c=6 e=5

// 第31行报错
// 第31行会调用 第10行构造函数，但它被声明了 explicit
// 这表明必须显示明确地调用构造函数，而不能通过编译器隐式转换
// 像22、25、28的调用，就是明确的。

// explicit只能用于构造函数及重载运算符函数
// 
// 前者你已经看到，后者你也即将会看到