#include <iostream>

int main() {
    int m = 10;

    decltype(m) n = m;

    std::cout << "n: " << n << std::endl;
}

// 运行代码 make run c=1 e=10