#include <time.h>
#include <iostream>

inline int add(int a, int b) {
    return a+b;
}

int main() {
    clock_t start = clock();
    
    int p = 0;

    for(int i = 0; i < 90000; i++) {
        p = add(p,i);
    }

   clock_t end = clock();

   std::cout << " time: " << (end - start) << std::endl;
}

// 运行代码 make run c=2 e=11

// 运行代码记录输出
// 将第4行inline去掉，再次执行代码，查看输出

//
// inline函数（内联函数），将不会跳入函数栈执行代码，而是将函数体的代码
// 直接在调用处展开，不存在转移到函数栈的过程