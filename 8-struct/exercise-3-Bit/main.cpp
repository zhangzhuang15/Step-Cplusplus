#include <iostream>

struct Computer {
    unsigned int id: 15;
    //unsigned int : 17;
    //unsigned int : 0;
    unsigned int price: 13;
};

int main() {
    Computer computer;
    computer.id = 20;
    computer.price = 5000;
    std::cout << "computer size: " << sizeof(computer) << std::endl;
}

// 运行代码 make run c=8 e=3

// Computer这种数据结构被称之为 位域。
// unsigned int id: 15 的含义是 id 占据 15bit。
//
// 当然啦，unsigned int 是4bytes，也就是 32bits，所以我们不能写成 unsigned int id: 33;
// 这样做的话，对出来的1bit就会被截断，你访问id时其实是缺少1个bit的！
//

// 运行后
// computer 4bytes 为什么是4呢？id占据 15bit，price占据13bit，总共28bit，
//                 没有超过32bit，于是就开辟32bit空间啦，也就是4bytes
//   

// 打开第5行注释，运行
// computer 8bytes 这回你应该会分析啦，15+17=32刚好占据4bytes， 剩下的13bit
//                 放入下一个 4bytes中，总共8bytes


// 把第5行的17改成20，再运行
// computer 12 bytes 15+20=35，超过32啦，所以15bit放入当前的4bytes中，
//                   20bit要放入下一个4bytes中，而且20+13=33，超过32bit，
//                   所以13bit又要放入下一个4bytes，总共3*4=12


// 第5行20改成2，打开第6行注释，运行
// computer 8 bytes  哎呀？15+2+0+13=30<32，为什么不是4bytes呢？
//                   注意，第6行的写法有特殊的含义，它会强制后边的price
//                   占据下一个4bytes，因此就有了8bytes


// 补充下一下： 位域中的数据类型必须是 int 、unsigned int 、signed int，其他的可不行哦