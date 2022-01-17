#include <iostream>

int main() {

    int age[5] = {18, 20, 14, 10, 5};

    for(int i = 0; i < 5; i++) std::cout << age[i] << "\t";

    std::cout << std::endl;

    for(auto i : age) std::cout << i << "\t";

    std::cout << std::endl;
}

// 运行代码 make run c=3 e=1

// 数组的定义和 for each 的循环访问方式你已经知道啦🎉