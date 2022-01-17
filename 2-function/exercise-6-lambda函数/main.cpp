#include <iostream>


int main() {
    int alpha = 20;
    int beta = 10;

    // 不捕捉任何外界的变量
    auto add = [](int a, int b) -> int { 
        std::cout<< "add lambda is invoked: "<< a << "+" << b << "=" << (a+b) << std::endl;
        return a+b;
    };

    // = 表示 alpha和beta两个变量以值传递的方式，传入使用
    auto sub = [=]()  -> int {
        std::cout<< "sub lambda is invoked: " << (alpha-beta) << std::endl;
        // 报错，不能被修改， 在[=]()后加入 mutable，打开下边的注释再试一试，就不会报错了
        alpha = 10;  
        return alpha-beta;
    };

    // & 表示 alpha 和 beta 两个变量以引用传递的方式，传入使用
    auto mul = [&]() -> int {
        std::cout<< "mul lambda is invoked" << std::endl;
        alpha = 10; // 成功，可以被修改
        return alpha*beta;
    };

    // =， &alpha 表示alpha变量按照引用传递，其余外边的变量按照值传递，
    // alpha可修改
    // 没返回值的话, -> int 可省略
    auto change = [=, &alpha](int n) mutable {
        std::cout<< "change is invoked and alpha will be mode" << std::endl;
        alpha = n; // 成功，可以被修改
    }; 


    add(10, 20);

    sub();

    mul();

    std::cout<< "alpha: " << alpha << std::endl;

    change(40);

    std::cout<<"alpha: " << alpha << std::endl;
}

//
// 运行代码 make run c=2 e=6
//
//
// 没啥太多要总结的，[]中的= & 别搞混了就行😭