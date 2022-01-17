#include <iostream>

//namespace protocol { 
    enum Protocol {
        TCP = 5,
        UDP = 10
    };
//};


enum TransportProtocol {
    TCP = 5,
    UDP = 10
};

int main() {

    Protocol t = TCP;

    // TransportProtocol t = TCP;
    // protocol::Protocol tt = TCP;
}

// 运行代码 make run c=7 e=2

// 第 18 行报错啦
// 因为在 TransportProtocol 和 Protocol都定义了TCP，编译器不知道 TCP 指的是哪一个
//

// 注释掉第 18 行代码，打开第3、8、20行代码，运行，成功啦
// 因为Protocol被 namespace protocol包裹起来啦，此时 TCP指的就是 TransportProtocol中的TCP
// 

// 打开第21行代码，再运行下，报错
// 因为 TCP 的类型 和 protocol::Protocol不匹配
//
// 改为 protocol::TCP 再运行下，
// yes🎉

// 从中你可以发现枚举作用域带来的问题