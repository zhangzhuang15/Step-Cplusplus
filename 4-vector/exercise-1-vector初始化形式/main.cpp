#include <iostream>
#include <vector>

// 定义一个宏，降低打印vector的编码负担
#define print(age)  for(auto item : age) std::cout << item << "\t"; std::cout << std::endl

int main() {
    std::vector<int>* age = new std::vector<int>(5);

    // 猜猜都会输出什么
    print(*age);
    free(age);


    age = new std::vector<int>(5, 4);

    // 这次会输出什么呢
    print(*age);
    free(age);



    // 还可以像数组那样定义
    std::vector<int> array_t_age = {15, 34, 23, 8};
    print(array_t_age);


    // 这种风格像结构体
    std::vector<int> m_t_array{ 17, 34, 22, 25};
    print(m_t_array);
}

// 运行代码 make run c=4 e=1

//
//
// 上面的例子中使用了4钟风格创建 vector，
// 前两种建在堆上，后两种在栈上
