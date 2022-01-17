// 顺序容器： 双向链表
#include <iostream>
#include <list>

template <typename T>
void traverse(std::list<T>& list) {
    
    std::cout << "list: ";
    for (auto begin = list.begin();begin != list.end(); begin ++) {
        std::cout<<"\t"<< *begin;
    }
    std::cout << std::endl;
}


int main() {
    
    std::list<int> l(4); 
    // [0, 0, 0, 0]

    l.push_back(5); 
    // [0, 0, 0, 0, 5]
    

    l.push_front(1); 
    // [ 1, 0, 0, 0, 0, 5]


    l.insert(l.begin(), 3, 100); 
    // [100, 100, 100, 1, 0, 0, 0, 0, 5]
    traverse(l);
    

    std::cout<< std::endl;


    l.pop_back(); 
    // [100, 100, 100, 1, 0, 0, 0, 0]


    l.pop_front(); 
    // [100, 100, 1, 0, 0, 0, 0]

    l.remove(100); 
    // [1, 0, 0, 0, 0]

    // list的iterator不支持和int数据的加法减法运算，
    // 但是支持 前置++ 后置++ 前置-- 后置-- 运算
    auto it = l.begin();
    ++it;
    l.splice(it , {2, 3, 4, 5}); 
    // [1, 2, 3, 4, 5, 0, 0, 0, 0]
    traverse(l);

    std::cout<< std::endl;


    l.unique(); 
    // [1, 2, 3, 4, 5, 0]
    traverse(l);

    l.clear();
}

// 运行代码 make run c=15