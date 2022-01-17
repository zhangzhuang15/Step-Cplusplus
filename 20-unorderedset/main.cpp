// 无序关联容器: unordered_set
// 容器中的元素排列会按照键的hash值分布，并不是按照插入顺序
#include <unordered_set>
#include <iostream>

#define traverse(set) std::cout << "set:" ;\
                      for(auto element: set) {\
                        std::cout <<"\t" <<element;\
                       }\
                       std::cout << std::endl


int main() {
    std::unordered_set<int> set;

    set.insert(10);
    set.insert(13);
    set.insert(12);
    // { 12, 13, 10}
    traverse(set);

    auto start = set.begin();
    start++;
    set.insert(start, 9); // start并没有什么卵用
    // { 9, 12, 13, 10}

    traverse(set);

    start = set.begin();
    start++;
    set.erase(start); // start管用啦
    // { 9, 13, 10 }

    traverse(set);

    set.erase(13);
    // { 9, 10}
    traverse(set);

    set.clear();
   
}

// 运行代码 make run c=20