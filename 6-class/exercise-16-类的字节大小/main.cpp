#include <iostream>

// class Tool {
//     private:
//         double tool;
//         int price;
// };

class Computer {
    private:
        int price;
        // static int size;
        // char rank[10];
        // Tool t;

    public:
        void echo() {};
        // virtual void show_size() {};
        // virtual void show_price() {};
};
// int Computer::size = 10;

int main() {
    
    Computer c;
    // Tool t;
    
    // std::cout << "Tool size: "     << sizeof(t) << std::endl;
    std::cout << "Computer size: " << sizeof(c) << std::endl;
}

// 运行代码 make run c=6 e=16

// 运行代码
// Computer 4 bytes ， 因为 price是 4 bytes，成员函数并不计算在内；

// 打开第12、21行代码，再运行
// Computer 4 bytes，  看来类变量并不计算在内；

// 打开第 18行 代码，再运行
// Computer 16 bytes， 因为有virtual方法，会产生一个virtual_table指针，指针占据 8 字节，
//                     而 price是 4字节，比 8 字节小，要按照 8 字节对齐，二者加起来12bytes，
//                     取邻近最小的8的整数，即16.

// 打开第 19 行代码，运行
// Computer 16bytes，  看来增加virtual函数并不会导致virtual_table指针变化

// 打开第 13行代码，运行
// Computer 24bytes，  尽管rank占据10字节，但是它的基础类型是char，1字节，没有 8大，依旧要按照
//                     8字节对齐，于是 price、rank、virtual_table指针加起来 4+10+8=22字节，
//                     按照8字节对齐，取邻近的最小8的整数24.

// 打开第 3～7行代码，26～28行代码，运行
// Computer 24bytes
// Tool 16bytes

// 打开第 14 行代码，再运行
// Computer 40bytes，  你可能会奇怪为什么不是64bytes，Tool是对齐之后占据16bytes，但是在Computer
//                     中Tool又会被打开成 double，int，double占据8字节，因此依旧要按照 8 字节对齐，
//                     于是 Computer_price、Computer_rank、Computer_virtual_table_ptr加起来
//                     占据 22字节，Tool_price、Tool_tool加起来占据12字节，总共22+12=34字节，由于
//                     要按照8字节对齐，所以取 40字节