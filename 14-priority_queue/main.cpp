// 优先队列， 默认是降序
#include <iostream>
#include <queue>

int main() {
    std::priority_queue<int> que;

    que.push(12);
    // [12]
    que.push(45);
    // [45, 12]
    que.push(10);
    // [45, 12, 10]


    int tp = que.top();
    std::cout<< "priority_queue 队首元素: " << tp << std::endl;


    que.pop();
    // [12, 10]
    tp = que.top();
    std::cout <<  "priority_queue 队首元素: " << tp << std::endl;


    if (que.size() > 0) {
        std::cout << "优先队列中还有元素" << std::endl;
    }

}

// 运行代码 make run c=14