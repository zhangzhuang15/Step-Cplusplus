#include <iostream>

class Computer {

    private:
        int price;

    public:
        Computer(int _price): price(_price) {}

    friend class ComputerStore;
};

class ComputerStore {

    public:
        // 在 ComputerStore内部可以访问 Computer的私有变量，
        // 不仅限于 本函数
        void show_me_price(Computer& computer) {
            std::cout << "computer price: " << computer.price << std::endl;
        }
};

int main() {
    
    ComputerStore computerstore;

    Computer computer(6000);

    computerstore.show_me_price(computer);
}

// 运行代码 make run c=6 e=13

//
// 不论是 friend函数 还是 friend类，都是对封装的破坏，
// 要谨慎使用

