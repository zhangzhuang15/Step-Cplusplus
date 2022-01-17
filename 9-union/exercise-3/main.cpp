#include <iostream>

typedef union {
    int price;
} Computer;

union {
    int rank;
};

int main() {

    Computer computer;
    computer.price = 6300;
    std::cout << "price: " << computer.price << std::endl;

    union {
        char rank;
    };

    rank = 20; 
    ::rank = 'B'; // 十进制是 66
    std::cout << "rank: " << ::rank << std::endl;
    
}

// 运行代码 make run c=9 e=3

// 第 7 行报错
// 在namespace中或者全局中的匿名union必须是static的；
// 所以，加上 static

// 第21行的rank是指第8行的rank；
// 第22行的 ::rank是指第18行的rank