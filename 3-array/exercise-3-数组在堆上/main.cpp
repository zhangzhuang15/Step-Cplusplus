#include <iostream>

int* create_int_array(int size) {
    int* array = new int[size];
    return array;
}

int main() {

    int* array_heap = create_int_array(5);
    for(int i = 0; i < 5; i++) std::cout<< array_heap[i] << "\t";

    delete array_heap;
}

// 运行代码 make run c=3 e=3

//
// 11行无法使用 for each 的方式访问啦

// 第4行的 改为 new int(size) ， 看看输出的结果有什么不同吧🤓

// 使用new开辟的空间位于堆，需要配合delete释放掉，防止内存泄漏；

// 在 C 中，使用 malloc 开辟的空间，使用 free函数释放；

// 本例子中尽管在进程退出时，操作系统会回收堆内存，但这是非常简单的例子，要养成好的习惯呀🌹