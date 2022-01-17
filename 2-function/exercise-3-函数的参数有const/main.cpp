#include <iostream>

void do_something(const int* num) {
    (*num)++;
    
    int age = 12;
    num = &age;

    std::cout << "number with ptr: " << *num << std::endl;
}

void do_something(const int& num) {
    num++;
    std::cout << "number with ref: " << num << std::endl;
}

int main() {
    int number = 0;

    do_something(&number);

    do_something(number);
}

// 运行代码 make run c=2 e=3

// 编译出错了？
// 注释第4行、第13行，再运行看看

// 将第3行的 const int* num 改为 const int* const num ，
// 再运行看看结果

//
//
// 总结:
//    函数参数传入的是指针，虽然可以提升入参效率，但是敲代码时可能无意中会修改原变量，
//    为了防止入参污染变量，可使用 const int*；
//    
//    同理，引用也是如此。