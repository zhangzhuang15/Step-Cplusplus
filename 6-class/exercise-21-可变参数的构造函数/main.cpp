#include <iostream>
#include <initializer_list>

class Computer {

    private: 
        int* price;

    public:

        Computer(int i, int j, int k) {
            price = new int[3];

            price[0] = i;
            price[1] = j;
            price[2] = k;

            std::cout << "Computer init by 3" << std::endl;
        }


        // Computer(std::initializer_list<int> args) {
        //     int size = args.size();
        //     price = new int[size];

        //      int i = 0;
        //     for(auto start = args.begin(); start != args.end(); start += 1, i++) {
        //         price[i] = *start;
        //     } 

        //     std::cout << "Computer init by list" << std::endl;
        // }


        ~Computer() { 
            std::cout << "delete space of price " << std::endl;
            delete price; 
        }
};

int main() {

    Computer c{1,2,3};
}

// 运行代码 make run c=6 e=21

// 运行代码发现调用的是第11行的构造函数
//
// 打开第22 到 32 行的代码，再运行
// 发现调用的是第22行的构造函数

// 从中可见其优先级