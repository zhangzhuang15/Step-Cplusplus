#include <iostream>

extern std::string name;
extern int age;
extern float temperature;
extern bool sex;
extern char rank;
extern char* rank_ptr;
extern char& rank_ref;


int main() {

    std::cout << "name: "        << name        << std::endl;
    std::cout << "age: "         << age         << std::endl;
    std::cout << "temperature: " << temperature << std::endl;
    std::cout << "sex: "         << sex         << std::endl;
    std::cout << "rank: "        << rank        << std::endl;
    std::cout << "rank by ptr: " << *rank_ptr   << std::endl;
    std::cout << "rank ptr self: " << rank_ptr  << std::endl;
    std::cout << "rank by ref: " << rank_ref    << std::endl;

}

// WTF! extern是什么鬼？

// extern 声明的变量，它们是在另外一个.cpp文件中定义的，本文件可以直接使用。

// 不信？ 看看 variable.cpp 都写了什么吧

// 运行代码看看
// make run c=1 e=5

// 把第四行代码改为 extern int age = 24；会发生什么？