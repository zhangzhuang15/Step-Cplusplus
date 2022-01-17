#include <iostream>

enum Protocol {
    TCP = 5,
    UDP = 10
};

int main() {

    Protocol t = TCP;

    if(t == 5) std::cout << "is TCP" << std::endl;

    if(t == TCP) std::cout << "is TCP too" << std::endl;
}

// 运行代码 make run c=7 e=1

// 运行成功