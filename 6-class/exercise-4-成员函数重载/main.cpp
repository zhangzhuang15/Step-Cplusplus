#include <iostream>

#define println(item) std::cout<< item << std::endl

class Computer {
    
    private:
       int kind;
    public:
       Computer(): kind(1) {}

       void start_movie() { println("1.only support MP4"); }

       int start_movie() { 
           println("2.only support MP4 and change kind");
           kind = 5; 
           return 20 ; 
        }

       int start_movie() const { 
           println("3.only support MP4");
           return 15; 
        }

       void start_movie(int kind) {
           if(kind > 5) println("4.Sorry, we don't support above 5 kinds of movie");
           else println("4.Begin to search movie");
       }

       void start_movie(bool interest) {
           if(interest) println("5.Ok, funny movie will be shown");
           else println("5.Oh, tragic movie will be your choice");
       }

       void start() const {
           start_movie();
       }
};

int main() {
    Computer computer;

    computer.start();

    computer.start_movie(6);

    computer.start_movie(false);

    computer.start_movie("fdaf");

    computer.start_movie();

}


//
// 运行代码 make run c=6 e=4
// 
// 你会遇到:
//
// * 第 12 行报错
//   you know: 成员函数的返回类型不同，并不能构成重载
//   TO DO： 
//      * 注释第12行代码
//      * 运行代码
//
// * 第 49 行竟然可以执行，且执行的是第30行代码
//   you know： 编译器将参数隐式转换为bool型
//   
//
// * 第51行执行的是第 20行
// you know: const可以用于重载，且优先级比 没有const、参数列表相同的版本 高