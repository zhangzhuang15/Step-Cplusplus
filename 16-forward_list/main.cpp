// 顺序容器：单向列表
#include <iostream>
#include <forward_list>

template<typename T>
void tr(std::forward_list<T>& f_list) {
    
    std::cout<<"f_list: ";
    for (auto start = f_list.begin(); start != f_list.end(); start++) {
        std::cout<<"\t"<< *start;
    }
    std::cout<<std::endl;
}


int main() {
    std::forward_list<int> f_list = {1, 2, 3, 4};
    // [1 , 2, 3, 4]
    tr(f_list);

    f_list.push_front(0); 
    // [0, 1, 2, 3, 4]



    // forward_list的iterator不支持加int数据，也不支持--操作，支持++操作
    // 因为这是单向链表，只能从表头一个接着一个向后遍历，不能随机跳到某个位置访问，
    // 自然也不能反向遍历
    auto st = f_list.begin();
    ++st;++st;++st;++st;
    f_list.insert_after(st, {5, 6, 7}); 
    // [0, 1, 2, 3, 4, 5, 6, 7]
    tr(f_list);



    f_list.pop_front(); 
    // [1, 2, 3, 4, 5, 6, 7]


    f_list.remove_if([](int &a){ return a > 5;});
    // [1, 2, 3, 4, 5]
    tr(f_list);


    auto it = f_list.begin();
    ++it;++it;
    f_list.splice_after(it, {9, 10, 11}); 
    // [1, 2, 3, 9, 10, 11, 4, 5]
    tr(f_list);



    f_list.clear();
}

// 运行代码 make run c=16