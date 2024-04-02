#include <iostream>

class Computer {
    private:
     int count;
    public:
        Computer() {
            std::cout << "Computer init!" << std::endl;
        }
        Computer(Computer& computer) {
            std::cout << "copy Computer init" << std::endl;
        }
        Computer(Computer&& computer) {
            std::cout << "move Computer init" << std::endl;
        }
        ~Computer() {
            std::cout << "delete Computer" << std::endl;
        }
        Computer(int _count): count(_count) {
            std::cout << "Computer init with one param" << std::endl;
        }
};


int main() {
    std::cout << "1\t" << std::endl;
    Computer computer_1;   // 调用了 Computer()

    std::cout << "2\t" << std::endl;
    Computer computer_2{}; // 调用了 Computer()

    std::cout << "3\t" << std::endl;
    Computer computer_3(); // 什么都没发生!

    std::cout << "4\t" << std::endl;
    Computer computer_4 = {}; // 调用了 Computer()

    std::cout << "5\t" << std::endl;
    Computer computer_5 = computer_1; // 调用了 Computer(Computer&)

    std::cout << "6\t" << std::endl;
    Computer *computer_6;  // 什么都没发生

    std::cout << "7\t" << std::endl;
    computer_6 = new Computer(); // 调用了 Computer()

    std::cout << "8\t" << std::endl;
    Computer computer_8 = std::move(computer_1); // 调用了 Computer(Computer&&)

    std::cout << "9\t" << std::endl;
    // 报错！ 因为我们定义了移动构造函数 Computer(Computer&&),
    // 编译器于是没有为我们添加赋值操作符的重载。
    // 这需要我们显式地定义赋值操作符运算。
    // computer_1 = computer_2; 

    // std::cout << "8\t" << std::endl;
    // delete computer_6;  // 新增一次输出 delete Computer

    std::cout << "10\t" << std::endl;
    Computer computer_10 = { 4 }; // 调用了 Computer(int _count)

}
// 
// 进入本文件所在的目录中，
// 执行 g++ demo1.cpp -o main -std=C++11 && ./main 运行代码
// 
// 会在第49行报错，相应的错误，第46行开始已经交代了，
//
// 注释第45行到第49行。
//
// 再次执行代码，
// 会发现构造函数调用了6次，但是析构函数调用了5次！
//
// 打开第45、46行的注释，重新运行，
// 析构函数调用了6次。
// 
// 所以，要注意 new 关键字创建的对象，要记得主动 delete掉，
// 否则会造成 内存泄漏