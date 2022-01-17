#include <iostream>

class Computer {
    private:
        int price;
    public:
        virtual Computer(int _price): price(_price) {}
        virtual ~Computer() {}
};

int main() {

    Computer computer(1000);
}

// 运行代码 make run c=6 e=11

// 第 7 行 代码报错
// 构造函数不能是 virtual，但是析构函数可以是 virtual
// 
// 去掉 第 7 行的virtual，再运行代码