// 队列
#include <iostream>
#include <queue>

int main() {
    std::queue<int> queue;
    // []

    if(queue.empty()) std::cout << "queue is empty" << std::endl;

    queue.push(1);
    queue.push(2);
    queue.push(3);
    // [1, 2, 3]

    std::cout<<"queue中有多少元素? "<< queue.size() << std::endl;

    int p = queue.front();
    std::cout<<"queue front element: "<< p << std::endl;

    queue.pop();//删除队首元素，不会有返回值
    // [2,3]

    p = queue.front();
    std::cout<<"queue 队首元素: "<< p << std::endl;

    p = queue.back();
    std::cout<<"queue 队尾元素: "<< p << std::endl;
}

// 运行代码 make run c=12