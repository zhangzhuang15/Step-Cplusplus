#include <iostream>

int* add(int* src, int delta) {
    *src += delta;

    return src;
}

const int* sub(int* src, int delta) {
    *src -= delta;
    
    // 尽管入参时，src是 int* 类型
    // 但是返回时，src会被赋值给一个 const int* 临时变量给带出去
    // 这种赋值方式正如第22行代码所述，是合法的
    return src;
}

int main() {
    int age = 10;

    // add返回的是 int* 类型指针，但你仍旧可以用 const int* 类型指针接收
    const int* result_add = add(&age, 10);
    std::cout << "age: " << *result_add << std::endl;

   // 此时你必须加上const了，去掉就会报错, 不信你就试试😭
    const int* result_sub = sub(&age, 10);
    std::cout << "age: " << *result_sub << std::endl;
}


//
// 运行代码 make run c=2 e=5
