#include "computer.h"

int main() {

    Computer* computer = new Computer();
    // Computer 初始化中
    // id: 0   price: 4000

    computer->tell_me_price();
    // 当前价格: 4000

    computer->more_expensive(400);


    computer->tell_me_price();
    // 当前价格: 4400

  /*
    delete computer;
    Computer 销毁中 { id: 0 price: 4400 }
   */

    computer = new Computer();
    // Computer 初始化中
    // id: 0   price: 4000

    Computer mycomputer = *computer;
    // 拷贝构造函数执行


    Computer mysecondcomputer = std::move(*computer);
    // 移动构造函数执行


    delete computer;
    // Computer 销毁中 { id: -1 price: -1 }

    // Computer 销毁中 { id: 10 price: 4200 }    
    // Computer 销毁中 { id: 10 price: 4100 }
}

//
// 运行代码 make run c=6 e=1
//
// 本代码中总共创建了多少个Computer对象呢？    4个 ？
// 
// 析构函数执行了几次呢？  4次 ？
//
//
//
// 
// 析构函数执行次数和对象个数不匹配表明：
// 1、 第31行 完成移动后，computer指代的对象不会自动调用析构函数；
// 2、 第5行 创建的对象在进程结束前，也不会自动调用析构函数。
// 
// 因此，当使用 new 将对象建立在堆上时，一定要记住内存释放，否则会发生内存泄漏啦


// 把 31行 Computer mysecondcomputer 改为 mycomputer 看看会发生什么吧


// 这反映了对象赋值时，等于号 作为运算符被执行，还是作为拷贝构造函数、移动构造函数 被执行;
// 1) 当 加上 Computer 时，其实是定义一个对象，此时构造函数就会被执行；
// 2) 当 去掉 Computer 时，其实是变量赋值，此时 = 号被作为运算符执行，如果没有定义该运算符，就会发生错误


//
// 类声明一般写在 .h 文件中，具体的定义写在 .cpp 文件中。
// 正如本例，Computer声明写在 computer.h 中， Computer定义写在 computer.cpp中。
//
// computer.h computer.cpp 中有一些重要的信息，请查阅。

// 你可能会好奇，main.cpp中 #include "computer.h"， computer.cpp 也有这个操作，
// 在编译代码的时候，执行的是 g++ -o main main.cpp computer.cpp， include发生了
// 2次，不会冲突么？
//
// 实际上会发生冲突，但考虑到了这一点，我们在 computer.h 加入 #ifndef来解决冲突。
// 第一次 include的时候，没有 __COMPUTER_，于是定义了它；第二次include，发现已经定义
// __COMPUTER_了，因此不再重复声明 Computer啦。
//
// 不信的话，删除 computer.h的 第1、2、56行再运行下！


//
// 好啦，恭喜你🎉
//
// 已经知道一个基本的class长啥样啦

//
// 接下来，我们将探索更细致、更容易混淆的class内容啦
//
// 请继续坚持✊