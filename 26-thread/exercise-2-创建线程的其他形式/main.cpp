#include <iostream>
#include <thread>

int num = 0;

void increase_num(int limiter, int delta) {

    std::cout << "child thread workplace: Function" << std::endl;

    for (; num < limiter; num += delta) {}

    std::cout << "child thread is done by num: " << num \
    << " in Function" << std::endl;
}



class Runner {

    public:
        void operator() (int limiter, int delta) {
            
            std::cout << "child thread workplace: Runner" << std::endl;
            for (; num < limiter; num += delta) {}
             std::cout << "child thread is done by num: " << num \
             << " in Runner" << std::endl;
        }

        void increase(int limiter, int delta) {

            std::cout << "child thread workplace: Runner increase" << std::endl;
            for (; num < limiter; num += delta) {}
             std::cout << "child thread is done by num: " << num \
             << " in Runner increase" << std::endl;
        }

        static void increase_static(int limiter, int delta) {
            std::cout << "child thread workplace: Runner increase_static" << std::endl;
            for (; num < limiter; num += delta) {}
             std::cout << "child thread is done by num: " << num \
             << " in Runner increase_static" << std::endl;
        }
};


int main() {

    auto F = [](int limiter, int delta) {
        
        std::cout << "child thread workplace: Lambda" << std::endl;
        for (; num < limiter; num += delta) {}
        std::cout << "child thread is done by num: " << num \
        << " in Lambda" << std::endl;
    };

    Runner runner;

    std::thread p_1(increase_num, 101, 1);
    std::thread p_2(runner, 108, 2);
    std::thread p_3(&Runner::increase,&runner, 111, 3);
    std::thread p_4(Runner::increase_static, 116, 4);
    std::thread p_5(F, 120, 5);

    p_1.join();
    p_2.join();
    p_3.join();
    p_4.join();
    p_5.join();

    std::cout << "all child threads are dead now" << std::endl;
}

// 运行代码 make run c=26 e=2

// 观察第 58 ～62行代码，可以知道创建线程的多样形式，特别要注意的是第60行代码，
// 它是以 类的成员函数 为线程入口点的，除了传入limiter、delta参数，还要传入
// 一个Runner实例的指针；