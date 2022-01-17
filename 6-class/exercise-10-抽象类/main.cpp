#include <iostream>
#include <string>

#define println(item) std::cout<< item << std::endl

class Computer {
    public:
        virtual void do_program(std::string name)=0;
        virtual void watch_movie()=0;
        void listen_music() {};
};

class MacBook: public Computer{
    public:
        void do_program(std::string name) {
            println("write a program with name " << name);
        }

        void watch_movie() {
            println("watch movie is optional");
        }

        void write_paper() {}
};

int main() {

    Computer _computer;

    MacBook book;

    Computer* computer = &book;

    computer->do_program("Junk");

    computer->watch_movie();

    computer->write_paper();
    
}

// 运行代码 make run c=6 e=10

// 第28行 报错
// 形如 virtual return_type funcname(<arguments>)=0 这样的成员函数是抽象函数，含有抽象函数的类就是抽象类;
// 抽象类无法初始化为实例，抽象类中允许有非抽象函数。
// 所以，Computer是一个抽象类，然后无法初始化
//
// 注释第28行, 再运行

// 第38行报错
// computer指针是 Computer* 类型，而Computer中没有声明 write_paper方法，无法访问
//
// 注释第38行代码，运行，🎉

// 注释掉第19～21行代码，也就是说 MacBook 只实现一个抽象函数
// 运行下，失败啦
//
// 这表明，要给出所有抽象函数实现后，这个类才能实例化，否则它仍旧是抽象类！

// C++没有interface关键字，因此要用抽象类去完成。
// 引入了抽象类，API就不怕乱套了，而且类的表述能力增加，可以玩转设计模式喽