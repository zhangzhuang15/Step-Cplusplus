#include <iostream>

class Computer {

    private:
        char id;

    // protected:
    //     int price;

    // public:
    //     virtual void echo(){}
};

// class Tool {

//     public:
//         virtual void echo() {};
// };


class MacBook: public Computer{

    // public:
    //     virtual void write_paper(){}
};


int main() {

    MacBook book;

    std::cout << "MacBook size: " << sizeof(book) << std::endl;

    // Tool t;
    // std::cout << "Tool size: " << sizeof(t) << std::endl;
}



// 运行代码 make run c=6 e=17

// 运行代码
// MacBook 1 bytes,  id虽然是private的，但仍旧被MacBook继承，表明private只是强调访问权私有，而非继承权私有；

// 打开第8、9行代码，运行代码
// MacBook 8bytes

// 打开第11、12行代码，运行
// MacBook 16bytes

// 打开第24、25行代码，运行
// MacBook 16bytes， 看来virtual_table指针只有一份，而不是 MacBook自己有一份，从Computer又继承一份


// 打开第35、36行代码，运行
// Tool 1byte， 当一个类什么成员都没有时，会占据1byte

// 在第 22 行Computer后边加上 , public Tool   运行代码
// MacBook 16bytes

// 打开第17、18行代码，运行
// MacBook 24bytes， 看来 MacBook 继承了两个 virtual_table，一个来Computer，一个来自Tool
// Tool 8bytes