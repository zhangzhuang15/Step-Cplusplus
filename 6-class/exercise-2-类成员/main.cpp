#include <iostream>
#include <string>

class Computer {

   // 默认的成员变量 private
    std::string name;

    // 类变量 默认也是 private
    static int id = 0;
    static const std::string version = "version";

    // 成员变量
    private:
      int price;
      const int year;
      
      void tell_version() {
          std::cout << "version: " << version << std::endl;
      }

    public:
      Computer():price(5000),year(2022) {
          name = "默认者-1";
          this->id++;
      }
      
      // 类函数
      // 打印 computer 总数
      static void tell_me_computers() {
          std::cout << "there are " << Computer::id << " computers" << std::endl;
      }

      // 成员函数
      // 打印价格
      void tell_me_price() {
          std::cout << "I am " << price << "RMB" << std::endl;
      }

      // 打印生产年限
      void tell_me_birth() {
          std::cout << "My birth is in " << year << std::endl;
      }

      // 打印生产年限
      static void tell_me_birth(Computer& computer) {
          std::cout << "My birth is in " << computer.year << std::endl;
      }

      static void tell_me_version() {
          tell_version();
      }
      
};
// Computer::id = 0;
// const Computer::version = "1.4.0";

int main() {
    Computer computer;

    // 报错，无法访问 name，因为它是private
    std::cout << "computer name: " << computer.name << std::endl;

    computer.tell_me_computers();

    Computer::tell_me_computers();

    // 报错，id 是 private的
    std::cout << "computer id: " << Computer::id << std::endl;

    computer.tell_me_price();
    
    // 报错，因为它不是 类函数
    Computer::tell_me_price();

    computer.tell_me_birth();

    Computer::tell_me_birth(computer);

    computer.tell_me_version();
}

//  运行代码 make run c=6 e=2

//  本例子可能有点乱，不过跟着错误走，永远不会迷失方向
//  
//  你依次会遇到：
//
//  * 第 10、11行代码报错
//    you know： 类变量声明在类的内部，类变量的初始化要在类的外部
//    TO DO:
//       * 去掉第10行 = 0， 去掉第11行 = “version”
//       * 打开第 55、56行注释
//       * 运行代码
//
//
//  * 第55、56行代码
//    you know： 类变量在初始化时，不能丢掉类变量的数据类型
//    TO DO：
//       * 第55行改为 int Computer::id = 0;
//       * 第56行改为 const std::string Computer::version = "1.4.0";
//       * 运行代码
//
//
//  * 第 62 行报错
//    you know：默认的成员变量是private的，private成员变量无法在类外部访问，比如用 .运算 或者 -> 运算
//    TO DO:
//       * 注释第62行
//       * 运行代码
//
//
//  * 第 69 行报错
//    you know: 默认的类变量也是private的，也无法在类外访问，比如用 :: 运算
//    TO DO：
//       * 注释第69行
//       * 运行代码
//
//
//  * 第 74 行报错
//    you know: :: 无法引用成员函数
//    TO DO：
//       * 注释第74行
//       * 运行代码
//
//
//  * 第 78 行执行通过
//    第 47 行出现 computer.year，year是 private的，不过第 47 行位于 class Computer内部，可访问year
//
//
//  * 第 80 行报错
//    you konow: 原来实例可以调用类函数和成员函数, 类函数中无法调用成员函数
//    TO DO：
//       * 第18行 void前边加上 static
//       * 运行代码
//    
// 
//  
//    
//  yes🎉，顺利执行！


// 试试在第 16行 直接给year赋值，看看行不行？