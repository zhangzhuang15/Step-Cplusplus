#include <iostream>
#include <thread>

/**
 * C++ 标准库的线程是封装操作系统的
 * 线程库<pthread.h>完成的；为什么
 * 要封装一层呢？还不是因为简化嘛，pthread
 * 是C版本的API，为了更细致地控制线程，
 * 里边有更多的参数，增加了使用负担。
 */


int num = 0;


void increase_num(int limiter) {

    std::cout << "num is increasing by 2 until ≥  "\
     << limiter << std::endl;

    for (; num < limiter; num += 2) {}

    std::cout << "num is " << num << std::endl;

}

int main() {

    std::thread child(increase_num, 101);

    std::cout << "now, main thread is waiting for the death of child thread" << std::endl;

    child.join(); // wait for the child thread until it deads.

    std::cout << "child thread is dead, take a look at num: " << num << std::endl;

}

// 执行代码 make run c=26 e=1

