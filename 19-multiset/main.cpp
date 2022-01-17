// 关联容器：multiset
#include <iostream>
#include <set>

#define traverse(item)  std::cout << "set: "; \
                        for (auto element:item) { \
                          std::cout<<"\t" << element;\
                        }\
                        std::cout<<std::endl
   

int main() {
    std::multiset<int> set;

    set.insert(10);
    set.insert(10);
    set.insert(12);
    set.insert(11);
    // {10, 10, 11, 12}
    traverse(set);


    auto start = set.begin();
    ++start;
    set.insert(start, 13);
    // {10, 10, 11, 12, 13}


    std::cout<<"set size: "<< set.size()<<std::endl;
    std::cout<<"10出现几次？ "<< set.count(10) << std::endl;

    traverse(set);

}

// 运行代码 make run c=19