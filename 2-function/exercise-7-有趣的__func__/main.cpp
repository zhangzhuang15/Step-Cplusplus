#include <iostream>

void print() {
    std::cout << "function name: " << __func__ << std::endl;
}

int main() {
    print();
}

// 运行代码 make run c=2 e=7

// __func__是不是很有趣？