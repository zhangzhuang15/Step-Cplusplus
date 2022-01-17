#include <iostream>

struct Computer {

    int price;
    static int id;

    Computer();
    ~Computer() { std::cout << "Goodbye" << std::endl; }

    public:
        void echo() { std::cout << "Hello I am Computer" << std::endl; }
};
int Computer::id = 100;
Computer::Computer(): price(5000) { std::cout << "Computer init" << std::endl; }

int main() {
    Computer computer;

    computer.echo();

    std::cout << "id: " << computer.id << "\tprice: " << computer.price << std::endl;
}

// 运行代码 make run c=8 e=1

// 运行成功🎉

// 可见：
// C++的 struct 和 class 大体相同的，区别在于默认情况下，struct是 public的， class是 private的；