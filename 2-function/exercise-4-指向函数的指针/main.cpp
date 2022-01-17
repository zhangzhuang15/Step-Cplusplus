#include <iostream>
#include <stdio.h>

void (* fn)(int num);

// 还可以定义为
typedef void (* Fn)(int num);

// 还可以用C++的方式定义为
using Func=void (*)(int num);

void print(int num) {
    std::cout << "number: " << num << std::endl;
}

int main() {
    fn = print;
    fn(20);
    
    // (void *)(print) 表示将 print 转为指向任意类型的一个指针，这将得到一个地址值；
    printf("print address: %p\n",(void *)(print));

    Fn f = print;
    f(30);

    Func func = print;
    func(40);
}



// 运行代码 make run c=2 e=4

//
// 函数可以使用 指针调用
// 
// 定义指向函数的指针时，注意是 (* fn) ，不要写成 *fn
//
// 为什么呢?
//
// 对比下声明就知道了
//
// void *fn(int num)
// void (* fn)(int num)
//
// 函数名，其实就是一个符号，表示一个虚拟地址
// 指针是存储什么的呢？地址啊！