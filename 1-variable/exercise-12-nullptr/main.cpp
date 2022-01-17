#include <iostream>

void echo(int n) { std::cout << "is int" << std::endl; }

void echo(void* n) { std::cout << "is *" << std::endl; }

int main() {
    echo(nullptr);

    nullptr_t m;
    echo(m);

    if(m == 0) std::cout << "yes" << std::endl;
    if(m == nullptr) std::cout << "equal" << std::endl;

    free(m);
    delete m;
}

// 运行代码 make run c=1 e=12

// nullptr是整数还是指针呢？ 运行下验证验证

// 16行不报错，但是 17行报错
// 这告诉我们，一旦将某个指针赋值为 nullptr， 用delete会引发错误，
// 特别是在移动构造函数中执行（6-class exercise-1 exercise-6涉及到移动构造函数）