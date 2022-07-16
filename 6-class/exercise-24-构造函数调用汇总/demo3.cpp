#include <iostream>

class Computer {
    public:
        std::string name;

    public:
        Computer(std::string _name): name(_name) {
            std::cout << "Computer[" << name << "] init" << std::endl;
        }

        Computer(Computer& computer) {
            name = computer.name + "copy";
            std::cout << "Computer[" 
                      << name 
                      << "] copy Computer[" 
                      << computer.name 
                      << "]"
                      << std::endl;
        }

        Computer(Computer&& computer) {
            name = computer.name + "move";
            std::cout << "Computer["
                      << name
                      << "] move"
                      << std::endl;
        }

        ~Computer() {
            std::cout << "Computer[" << name << "] delete" << std::endl;
        }
};

Computer get() {
    Computer computer("Jack");
    return computer;
}

Computer&& offer() {
    Computer computer("Jack");
    return std::move(computer);
}

Computer& give() {
    Computer computer("Jack");
    return computer;
}

Computer* letout() {
    Computer computer("Jack");
    return &computer;
}

int main() {

    std::cout << "1\t" << std::endl;
    Computer computer_1 = get(); // 只调用了 Computer构造函数

    std::cout << "2\t" << std::endl;
    Computer computer_2 = offer(); // 调用了 Computer 构造函数，析构函数, 移动构造函数

    std::cout << "3\t" << std::endl;
    Computer computer_3 = give(); // 调用了Computer 构造函数，析构函数, 拷贝构造函数

    std::cout << "4\t" << std::endl;
    Computer *computer_4 = letout(); // 调用了 Computer 构造函数，析构函数

    std::cout << "5\t" << std::endl;
    std::cout << computer_3.name << std::endl;
    std::cout << computer_4->name << std::endl;

    std::cout << "6\t" << std::endl;

    return 0;
}

// 进入本文件所在的目录中，
// 执行  g++ demo3.cpp -o main --std=c++11 && ./main 运行代码
// 观察输出。
//
// 第58行现象：按理说在 get方法内应该执行一次构造函数和析构函数，computer_1处应该调用一次
//           复制构造函数，可实际上只是调用了一次构造函数，有点神奇，不知道为什么会这样。
//
// 第61行现象：这个现象还算正常，offer方法内调用一次构造函数和析构函数，返回一个右值引用，
//           不过由于函数返回后，右值引用所指向的内存已经释放，name也变成了空字符串，
//           在 computer_2 处，右值是 Computer&& ，于是调用了移动构造函数。
//    
// 第64行现象：和第61行很相似，区别在于 computer_3处 右值是 Computer& , 于是调用复制构造函数。
//
// 第67行现象： 尽管在这里没有引发什么大问题，但确实是个大问题，返回悬空指针死及其不对的。