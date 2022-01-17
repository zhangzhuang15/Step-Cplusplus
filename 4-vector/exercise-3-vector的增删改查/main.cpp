#include <iostream>
#include <vector>

#define print(item) std::cout << item
#define println(item) print(item);print("\n")
#define print_vector(item) for(int i = 0; i < item.size(); i++) { \
                                    print(item[i]);\
                                    print("\t");\
                            } \
                            println("");

int main() {
    
    
    std::vector<int> age;
    // []
  
    
    if(age.empty()) age.push_back(1);
    // [1]

    
    age.push_back(5);
    age.push_back(15);
    // [1,5,15]


    auto start = age.begin();
    
    
    // insert方法要传入迭代器
    age.insert(start+2, 10);
    // [1,5,10,15]

    
    age.insert(start+4, 2, 20);
    // [1,5,10,15,20,20]

    // 验证一下
    print_vector(age);

    // 获取最后一个数据
    int& last_one = age.back();
    print("last one: ");
    println(last_one);

    // 删除最后一个数据
    // 没有返回值的哦
    age.pop_back();
    //[1,5,10,15,20]

    print_vector(age);

    // 上一步 pop_back改变了 vector，迭代器要从新获取！
    start = age.begin();
    age.erase(start);
    // [5,10,15,20]

    start = age.begin();
    age.erase(start, start+2);
    // [15,20]

    print_vector(age);


    // 15
    int& first_one = age.front();
    
    age.clear();
    // []


    print_vector(age);

    print("first one: ");
    println(first_one);
}

// 运行代码 make run c=4 e=3

//
// 现在你知道了vector的 入栈、出栈、插入、删除、清空、随机访问 啦🎉


// 第6行中的 \ 作用是忽视掉后边的空白符（空格、换行符）