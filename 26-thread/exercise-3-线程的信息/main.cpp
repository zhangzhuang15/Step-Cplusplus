#include <iostream>
#include <thread>
#include <chrono>

int num = 0;

void increase_num(int limiter, int delta) {

    // 获取线程id
    std::thread::id id = std::this_thread::get_id();
    std::cout << "child thread id : " << id << std::endl;


    for(; num < limiter; num += delta) {
        if(num % 10 == 0)  std::this_thread::yield(); // 暂时释放运行权
    }

     // this thread sleep for 5 seconds
    std::this_thread::sleep_for(std::chrono::seconds(5));
    std::cout << "child thread is dead" << std::endl;
}

int main() {
    std::thread p(increase_num, 120, 4);
    //p.join();

    std::cout << "1. come back to the main thread with num : " << num << std::endl;
    std::this_thread::yield();

    std::cout << "2. come back to the main thread with num: " << num << std::endl;

    //if(p.joinable()) p.join();
}

// 运行代码： make run c=26 e=3
// 
// 运行代码后，你会发现主线成结束了，但是子线程的 “child thread is dead” 没有被打印出来

// 打开第32行注释，运行代码，你会发现
// 先打印 1. come back to the main thread with num...
// 后打印 child thread id....
// 这表明执行到第27行代码时，主线程交出了自己的运行权，切换到子线程中。
// 
// 可是之后打印的却是 2.come back to the main thread... num: 120
// 这表示第14行代码执行后，子线程交出了运行权，但是运行权又被子线程拿到了，也就是
// 说，yield方法让线程暂时交出了运行权，之后运行权重新调度后依旧可能回来

// 打开第24行代码，运行代码，你会发现第14行代码执行，并没有切换到第26行。这表明
// join方法一旦调用，那么主线程就会一直等着

// 依旧将第25行、32行代码注释，将第19行代码放在第12行代码的位置上，执行代码，
// 你会发现，线程睡眠也会令线程交出执行权，切换到主线程中
