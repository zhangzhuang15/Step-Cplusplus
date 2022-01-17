#include <iostream>

// 这是全局变量
int age = 10;

void look_age() {
    std::cout << "look age: " << age << std::endl;
}

int main() {
   
   age = 5;

   // 这是局部变量
   int age = 15;

   std::cout << "age: " << age << std::endl;

   look_age();
}




// 第12行 和 第15行 代码会不会发生冲突呢？

// age: 后边是多少？
// look age： 后边是多少？

// 运行下代码看看吧
// make run c=1 e=4
