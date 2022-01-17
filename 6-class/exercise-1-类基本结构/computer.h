#ifndef __COMPUTER_
#define __COMPUTER_

#include <string>

class Computer {
    
    // 默认情况下，是 private protected public 哪一个呢？
    std::string name;

    // 私有成员变量、私有成员函数 在此⬇️
    //
    // 实例 . 运算 或者 -> 运算 无法访问！
    // 子类 无法访问！
    private:
       int id;

    // 受保护的成员变量、成员函数 在此⬇️
    //
    // 实例 . 运算 或者 -> 运算 无法访问！
    // 子类 可以访问！
    protected:
       int price;

    // 公共的成员变量、成员函数 在此⬇️
    //
    // 实例 . 运算 或者 -> 运算 可以访问！
    // 子类 可以访问！
    public:
       // 构造函数
       // 创建一个实例时会调用
       Computer();

       // 析构函数
       // 释放一个实例时会调用
       ~Computer();

       // 拷贝构造函数
       //
       // Computer a(); 
       // Computer b = a; 此时就会执行该函数
       Computer(Computer&);

       // 移动构造函数
       // &&表示右值引用
       // Computer computer = std::move(another_computer) 此时会调用该函数
       Computer(Computer&&);

       // 涨价 delta 元
       void more_expensive(int delta);

       // 打印价格
       // 末尾声明const，表示这个函数内部不会修改任何成员变量的值
       void tell_me_price() const;
};   // 这个分号不要忘了！！
#endif