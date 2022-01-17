#include <iostream>

class Computer final {

};

class MacBook: public Computer {};

int main() {
    MacBook book;
}

// 运行代码 make run c=6 e=20

// 第7行报错
// Computer被声明为 final， 表示它不能被任何类继承啦