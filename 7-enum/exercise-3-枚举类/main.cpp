#include <iostream>

enum class Protocol {
    TCP = 5,
    UDP
};

enum class CharProtocol: char {
    TCP = 't',
    UDP 
};

int main() {

    Protocol t = Protocol::TCP;

    if(t == 5) std::cout << "Protocol::TCP==5" << std::endl;

    if((int)t == 5) std::cout << "after static cast, Protocol::TCP==5" << std::endl;

    if((char)CharProtocol::UDP == 'u') std::cout << "after static cast, CharProtocol:UDP == 'u'" << std::endl;

}

// 运行代码 make run c=7 e=3

// 在 第17行 报错
// 这表明Protocol::TCP非但不等同于5，而且还会因为类型检查而报错
// 不过我们可以强制转换类型
//
// 注释第17行，运行代码，通过✅

// 从第21行代码的执行来看，CharProtocol::TCP = 't', 而 UDP就会自增1，赋值为'u'

// 补充一点，枚举中的数值只能是整数，无法赋值浮点数