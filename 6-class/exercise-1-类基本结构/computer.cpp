#include "computer.h"
#include <iostream>

// 使用初始化列表 初始化 id 和 price
Computer::Computer(): id(0), price(4000){

    std::cout << "Computer 初始化中" << std::endl;
    std::cout << "id: " << id << "\tprice: " << price << std::endl;

}

Computer::~Computer() {
    std::cout << "Computer 销毁中 { id: " << id << " price: " << price << " }" << std::endl;
}

Computer::Computer(Computer& computer) {

    std::cout << "拷贝构造函数执行" << std::endl;
    this->id = computer.id + 10;
    this->price = computer.price + 100;

}

Computer::Computer(Computer&& computer) {

    std::cout << "移动构造函数执行" << std::endl;
    this->id = computer.id + 10;
    this->price = computer.price + 200;

    // computer中的数据已经被移动，computer不能
    // 再持有这些数据的所有权，因此需要标记为 -1；
    // 对于指针类型的变量，应赋值为 nullptr
    computer.id = computer.price = -1;

}

void Computer::tell_me_price() const {

    std::cout << "当前价格: " << price << std::endl;

}

void Computer::more_expensive(int delta) { price += delta; }


