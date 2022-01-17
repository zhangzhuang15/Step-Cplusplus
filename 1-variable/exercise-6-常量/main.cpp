#include <iostream>

int main() {

    const int age;
    age = 10;

    const float temperature = 36.7;

    const char c = 'C';

    const bool sex = true;

    const std::string name("jakck");
}

// 上边会操错，猜猜是哪一行？

// 运行下吧 make run c=1 e=6


//
// const修饰的变量是常量，无法被修改，也不能先声明再定义，而是要声明定义一步到位