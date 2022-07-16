#include <iostream>

typedef
struct Man {
    int age;
} Man;

class Woman {
    public:
        int age;

        Woman(int age): age(age) {}
      //  Woman(Woman&) = delete;
};

int main() {
    Man peter = { 18 };
    Man p = peter;
    p.age = 20;
    std::cout << "peter: " << peter.age << std::endl;
    std::cout << "p: "     << p.age << std::endl;


    Woman lucy(17);
    // C++ 在这里采用了复制拷贝函数的策略，避免了浅拷贝的问题；
    // 在 Swift 、 Javascript 、 Java 中传的是饮用，
    // 会带来数据共享的问题
    Woman w = lucy;
    lucy.age = 23;
    std::cout << "lucy: " << lucy.age << std::endl;
    std::cout << "w: "   << w.age    << std::endl;
}


// 执行代码 make run c=6 e=25
//
// 发现在第28行报错，这是因为第13行禁止了复制拷贝函数，
// 请将第13行注释掉再次执行吧。
//
// 你会发现 p 将  Peter 的成员数据完整拷贝了一份，
// 如果成员数据里不涉及到指针，那么 p 其实是对 Peter 的深拷贝，
// 不会代码数据共享的问题。
//
// 而对于 class， 由于复制拷贝构造函数， 程序员可以自定义赋值的行为，
// 从而避免数据共享的问题。默认情况下，编译器会在拷贝构造函数中采取
// 数据的完整拷贝，如果数据中存在指针，那么就会带来数据共享问题。