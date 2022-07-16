#include <iostream>
#include <chrono>
#include <thread>

// C++处理时间采用 chrono 标准库，
// 尽管使用起来语法很别扭，不如Go语言、Js语言直观
int main() {
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(300));
    auto end = std::chrono::high_resolution_clock::now();
    std::cout << "cost: " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << "ms" << std::endl;
    return 0;
}