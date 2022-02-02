#include <iostream>
#include <thread>
#include <mutex>

std::mutex m; // mutex其实也是封装 pthread_mutex完成的

bool flag = true;             // true表示轮到 print_odd执行，false表示轮到 print_even执行

bool alive_print_odd = true;  // 记录 print_odd 是否运行结束
bool alive_print_even = true; // 记录 print_even 是否运行结束

void print_odd(int limiter) {

    for(int i = 0 ; i < limiter; i++) {
        while(flag == false && (i & 0x1) && alive_print_even) { std::this_thread::yield();}
        if (i & 0x1 && flag) {
            m.lock();
            std::cout << "odd: " << i << std::endl;
            flag = false;
            m.unlock();
        }
    }
    alive_print_odd = false;
    

}

void print_even(int limiter) {

    for(int i = 0 ; i < limiter; i++) {
        while(flag && (i & 0x1) == 0 && alive_print_odd) { std::this_thread::yield();}
        if ((i & 0x1) == 0 && !flag) {
            m.lock();
            std::cout << "even: " << i << std::endl;
            flag = true;
            m.unlock();
        }
    }
    alive_print_even = false;
}


int main() {

    std::thread odd(print_odd, 102);
    std::thread even(print_even, 100);

    odd.join();
    even.join();
}

// 执行代码 make run c=26 e=5