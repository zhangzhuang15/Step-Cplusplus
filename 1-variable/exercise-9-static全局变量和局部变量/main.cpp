#include <iostream>

extern int age;

void print_year(){
    // 这是 静态局部变量
    static int year = 2000;
    std::cout << "year: " << year << std::endl;
    year++;
}

int main() {

    print_year();

    print_year();

    std::cout << "age: " << age << std::endl;

}

// 运行代码看看吧  make run c=1 e=9

// 没跑起来？ 看看 variable.cpp 中的注释吧！

//
// 总结：
// 1、static将全局变量局限在本 .cpp文件中，其他 .cpp文件不可见；
// 2、static静态变量在函数执行完毕后不会被释放，而是继续保留，直到进程结束；