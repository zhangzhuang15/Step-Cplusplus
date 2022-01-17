#include <iostream>

#define println(item) std::cout<< item << std::endl

class Computer{

    public:
        void echo() { println("price"); }
};

class MacBook:  public Computer{};

class IntelMacbook: public MacBook,  public Computer  {
};


int main() {
    IntelMacbook book;

    book.echo();
}

// 运行代码 make run c=6 e=9

// 报错，说是echo方法 ambigous
// 分析一下确实如此，MacBook从Computer中继承了echo，
// IntelMacBook又同时继承 MacBook 和 Computer，
// 那么echo就被继承了两次，引发矛盾

// 第11行public前加入 virtual
// 第13行 逗号后边加入virtual
// 再运行，就没有问题啦
// 
// 这就是虚继承
// 虚继承的效果就是相同的东西只留一份