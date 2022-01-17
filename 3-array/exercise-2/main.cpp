#include <iostream>

// 本函数无法正确求出数组的长度
// 因为 sizeof(array)求的是 array这个指针占据内存的字节大小，不是整个数组
int getSize(int* array) {
    return sizeof(array)/sizeof(int);
}

int main() {

    const int size = 5;

    int age[size];

    for(auto i : age) std::cout<< i << "\t";

    std::cout<< std::endl;

    int score[size] = {0};

    for(auto i : score) std::cout<< i << "\t";

    std::cout<< std::endl;

    std::cout << "score array size: " << sizeof(score)/sizeof(int) << std::endl;

    std::cout << "score array size: " << getSize(score) << std::endl;
}

// 运行代码 make run c=3 e=2

//
// age数组虽然被编译器赋值了，但是5个值极不规律
// 反观 score数组，各个元素值清一色是 0，很靠谱