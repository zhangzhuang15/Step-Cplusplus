#include <iostream>

class Computer {

    public:
    enum Status {
        Healthy = 1,
        Bad = 2
    };
};

int main() {

    if(Computer::Healthy == 1) std::cout << "this Computer is healthy" << std::endl;
}

// 运行代码 make run c=7 e=4

// 运行成功
// 将枚举放进类内部，通过public、private、protected的修饰符，我们
// 可以限制枚举的作用域范围，也不会像枚举类的类型检测引发错误。