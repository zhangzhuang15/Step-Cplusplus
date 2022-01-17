#include <iostream>
#include <vector>

#define print(item) std::cout<< item
#define println(item) std::cout << item << std::endl

int main() {

    std::vector<int> age(5);

    // start是vector的起始迭代器, end是终止迭代器。
    // 要习惯使用迭代器去访问vector，而不是采用C语言的传统，大刀阔斧直接 for循环;
    // 有了迭代器，函数式编程就充满了生机；
    // 在 Rust 里面，迭代器更常见.
    auto start = age.begin();
    auto end = age.end();

    // 当访问结束时，也就是 start迭代器和
    while(start != age.end()) {
        
        // 从迭代器拿到数据
        int item = *start;
       
        // 处理数据，这里简化，直接打印
         print(item);
         print("\t");

        // 设置可以修改原数据
        (*start) += 1; 
       
       // 迭代器向后迭代一步
       // 不要使用 start++ 或者 ++start
        start += 1;
    }
    println("\n");
    
    // end迭代器对应的值是什么呢？会不会是空值？
    println(*end);

    // end迭代器前边的一步会不会是最后一个值？
    println(*(end-1));


    // 也可以使用 C 风格
    for (int i = 0; i < age.size(); i++) {
        print(age[i]);
        print("\t");
    }
    
}

// 运行代码 make run c=4 e=2

// 使用 age.cbegin() 迭代器访问数据时，
// 只能读数据，不能修改数据。
// cbegin的 c 是 const 缩写。