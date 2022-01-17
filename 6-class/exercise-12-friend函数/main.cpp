#include <iostream>

class Computer {

    // friend函数不是类的成员函数，不受 private public protected限制
    friend void show_me_price(Computer&);

    private:
        int price;
    
    public:
        Computer(int _price): price(_price) {}
        
};

void show_me_price(Computer& computer) {
    // 在friend函数中，可以直接访问 私有成员
    std::cout << "computer price: " << computer.price << std::endl;
}

int main() {
    
    Computer computer(5000);

    show_me_price(computer);
}

// 运行代码 make run c=6 e=12

// 去掉第 6 行的 friend，运行会报错