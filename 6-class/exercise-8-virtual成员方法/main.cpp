#include <iostream>

#define println(item) std::cout<< item << std::endl

class Computer {
    public:
        virtual void echo() { println("Computer{}"); }
        void how_much() { println("Computer is 4000 RMB"); }
};

class MacBook: public Computer {
    public:
        virtual void echo() { println("MacBook{}"); }
        void how_much() { println("MacBook is 14000 RMB"); }
};

int main() {

    Computer* computer = new MacBook();

    computer->echo();

    computer->how_much();
}

// 运行代码 make run c=6 e=8

// echo执行的是MacBook版本，how_much执行的是Computer版本
// 被 virtual修饰的成员函数在执行时确定，看 computer指针指向的具体是哪种对象；

// 然而，没有加入 virtual修饰的成员函数将在编译阶段确定，因为computer指针定义时是 Computer*，
// 因此编译器也会选择Computer版本的how_much方法