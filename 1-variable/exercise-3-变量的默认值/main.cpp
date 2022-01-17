#include <iostream>

int main() {
    // 使用本行的变量 c，解决编译不通过的问题
    char c = 'C';

    std::string name;
    int age;
    float temperature;
    bool sex;
    char rank;
    char* rank_ptr;
    char& rank_ref;

    std::cout << "name: "        << name        << std::endl;
    std::cout << "age: "         << age         << std::endl;
    std::cout << "temperature: " << temperature << std::endl;
    std::cout << "sex: "         << sex         << std::endl;
    std::cout << "rank: "        << rank        << std::endl;
    std::cout << "rank by ptr: " << *rank_ptr   << std::endl;
    //std::cout << "rank ptr self: " << rank_ptr  << std::endl;
    std::cout << "rank by ref: " << rank_ref    << std::endl;
}

// 只声明而不定义，编译器会帮你定义，但是定义的值等于多少呢？是不是固定的值呢？探究下吧！

// 代码中有一行无法通过编译，猜猜是哪一行？

// 运行代码验证下你的猜想！

// 运行本代码：make run c=1 e=3

// 如果打开21行的代码，会发生什么呢？ 执行下看看吧。