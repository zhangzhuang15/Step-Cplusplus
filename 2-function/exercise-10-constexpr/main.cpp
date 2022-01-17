#include <iostream>

constexpr int add(int a, int b) {
    if ( a == 1) return a + b;
    else return a + b + 1;
}

int main() {

    int a = add(1, 2);

    int b = add(a, 3);

    std::cout << "a: " << a << std::endl;

    std::cout << "b: " << b << std::endl;
}

// 运行代码 make run c=2 e=10

// constexpr修饰的函数，如果入参不是变量，而是字面值，则函数的返回值将在编译期间确定，
// 否则就像普通函数那样在执行期间确定