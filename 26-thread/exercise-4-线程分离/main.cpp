#include <iostream>
#include <thread>
#include <chrono>


int num = 0;

void increase_num(int limiter, int delta) {

    for(; num < limiter; num += delta) {}

    std::this_thread::sleep_for(std::chrono::seconds(5));

    std::cout << "child thread is dead" << std::endl;
}

int main() {

    std::thread p(increase_num, 120, 5);

    p.detach();

    std::cout << "main thread visit num: " << num << std::endl;

    std::this_thread::yield();

    std::cout << "main thread visit num: " << num << std::endl;

    std::cout << "main thread leave" << std::endl;
}

// 运行代码 make run c=26 e=4

// 尽管没有报错，但似乎看不出来detach方法有啥效果😂