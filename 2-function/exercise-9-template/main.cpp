#include <iostream>


template<typename T>
void print(T value) {
    std::cout << value << std::endl;
}

void printN() {}

template<typename T, typename... G>
void printN(T value, G ...args) {
    std::cout << value << std::endl;
    printN(args...);
}

int main() {
    print("jack");

    printN(1,"jack", 'c', 24.5, false);
}

// 运行代码 make run c=2 e=9

// 重点解释下 printN
// 执行 printN(1,"jack", 'c', 24.5, false);          T value = 1 剩余参数由 args接收
// 打印完 1 后， 执行 printN(args...), args 被拆解，
// 就会调用 printN("jack", 'c', 24.5, false),   这时 T value = "jack"， 剩余参数再由 args接收
// 以此类推，到执行 print(false)时，args变成空值，在 打印出 0（false在打印时会被作为 0 输出）后，
// 调用 printN()
// 结束整个函数