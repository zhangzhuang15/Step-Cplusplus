#include <iostream>
#include <string>

class Computer {

    private:
      int price;
      std::string name;

    public:
      Computer(): price(4000), name("") {}

      Computer(int p_price): price(p_price), name("") {}

      Computer(int p_price, std::string p_name): price(p_price), name(p_name) {
        std::cout << "构造函数被调用" << std::endl;
      }

      Computer(Computer& computer): price(computer.price), name(computer.name) {
        std::cout << "拷贝构造函数被调用" << std::endl;
      }

      void echo() {
          std::cout << "name: " << name << "\tprice: " << price << std::endl;
      }

};


int main() {
    Computer computer_none;
    Computer computer_none_2 = {};
    Computer computer_none_3{};
    Computer computer_none_4();
    Computer computer_expensive(11000);
    Computer computer_normal{5000};
    Computer computer_black_expensive = { 12000, "black" };

    computer_none.echo();
    computer_expensive.echo();
    computer_normal.echo();
    computer_black_expensive.echo();
}

// 执行代码 make run c=6 e=3

// 众多实例的初始化形式，你值得拥有🥳

// 第 28 行，会跑出来一个 warning，建议你去掉多余的 ()

//
// 