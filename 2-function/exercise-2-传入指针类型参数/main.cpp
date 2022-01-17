#include <iostream>

// 1

// void add_and_print(int num) {
//     num++;
//     std::cout << "number: " << num << std::endl;
// }

void add_and_print(int* num) {
    (*num)++;
    std::cout << "number: " << *num << std::endl;
}

// 2

// void add_and_print(int& num) {
//     num++;
//     std::cout << "number: " << num << std::endl;
// }

int main() {
    int num = 10;

    add_and_print(num);
    std::cout << "1  num: " << num << std::endl;

    add_and_print(&num);
    std::cout << "2  num: " << num << std::endl;

}


// 运行本代码 make run c=2 e=2

// 打开注释1，运行一下，看看 函数传入指针 和 传入普通变量 的区别

// 关闭注释1，打开注释2，运行一下，看看 函数传入变量的引用 是什么效果
// 在第30行后边加入 add_and_print(19) 看看会不会报错

// 
// 如果报错的话，将第 17行入参类型改为 const int&，再将第18行注释，运行一下，看看还会不会报错呢？
//
//



// 总结：
// 1、当想把函数结果带回去时，除了return一个值，还可以使用 指针或者引用 修改变量，达到将函数结果带回的效果；
// 2、当想提高函数的入参效率时，考虑传入 指针 或 引用，而不是变量本身。对于基本数据来说，提升不大，但是对于
//    class 和 struct 来说，效率提升很大。