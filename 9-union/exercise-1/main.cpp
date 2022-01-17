#include <iostream>

union Computer {
    int price;
    char rank;
};


int main() {
    Computer computer;
    computer.price = 0x002000; // 8192
    computer.rank = 'A';

    std::cout << "price: " << computer.price << std::endl;

    std::cout << "rank: " << computer.rank << std::endl;

    std::cout << "computer size: " << sizeof(computer) << std::endl;
}

// 运行代码 make run c=9 e=1
//

// 由输出的结果可得到如下的模型

// computer占据4bytes
// computer.price = 0x002000得到：
//
// 高字节    00
//          00
//          20
// 低字节    00
//
// computer.rank = 'A' ， ‘A’的十六进制表示为0x41 ,得到：
//
// 高字节    00
//          00
//          20
// 低字节    41
//
// 0x002041 刚好就是 8257