// 关联容器：set
#include <iostream>
#include <set>

#define traverse(item)  std::cout<< "set: "; \
                        for (auto element: item) { \
                             std::cout<< "\t" << element; \
                        } \
                        std::cout<< std::endl


int main() {
    std::set<int> set;

    set.insert(10);
    set.insert(10);
    set.insert(12);
    set.insert(11);
    traverse(set);
    // {10, 11， 12} 集合中没有重复值

    auto start = set.begin();
    start++; // 不支持 += 1 运算
    // 这样插入数据不能指定被插入值的顺序，因为set multiset会按照键有序排列，最终输出结果就是由小到大
    set.insert(start, 13);
    // {10, 11, 12, 13}

    traverse(set);


    std::cout<<"set size: "<< set.size()<<std::endl;
    std::cout<<"10出现几次？ "<< set.count(10) << std::endl;


    if(set.find(14) != set.end()) std::cout << "set 中有 14" << std::endl;
}

// 运行代码 make run c=18