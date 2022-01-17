#include <iostream>

int main() {
    
    // 字符串变量
    std::string name = "Jo Jo";

    // 整型变量
    int age = 20;

    // 浮点型变量
    float temperature = 36.4;

    // 布尔型变量 male: true   female: false
    bool sex = true;

    // 字符型变量
    char rank = 'B';

    // 指针类型变量
    char* rank_ptr = &rank;

    // 引用类型变量
    char& rank_ref = rank;

    // std::cout 输出结果，std::endl表示换行并且刷新缓存，见多了就熟悉了，用多了就学会啦
    std::cout << "name: "        << name        << std::endl;
    std::cout << "age: "         << age         << std::endl;
    std::cout << "temperature: " << temperature << std::endl; 
    std::cout << "male: "        << sex         << std::endl;
    std::cout << "rank: "        << rank        << std::endl;
    std::cout << "rank by ptr: " << *rank_ptr   << std::endl;
    std::cout << "rank by ref: " << rank_ref    << std::endl;

    std::cout << std::endl;
    
    // 来看看数据都占据多少字节吧
    std::cout << "name byte: "        << sizeof(name)        << std::endl;
    std::cout << "age byte: "         << sizeof(age)         << std::endl;
    std::cout << "temperature byte: " << sizeof(temperature) << std::endl; 
    std::cout << "male byte: "        << sizeof(sex)         << std::endl;
    std::cout << "rank byte: "        << sizeof(rank)        << std::endl;
    std::cout << "rank_ptr byte: "    << sizeof(rank_ptr)    << std::endl;
    std::cout << "rank_ref byte: "    << sizeof(rank_ref)    << std::endl;
}

// 一个简单的例子，先直观感受下
//
// 迫不及待跑一下？
// make run c=1 e=1 运行代码