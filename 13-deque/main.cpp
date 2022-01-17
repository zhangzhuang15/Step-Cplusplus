// 顺序容器： 双边队列
#include <iostream>
#include <deque>


template<typename T>
void tranverse(std::deque<T>& deque) {

    std::cout << "deque: ";
    for (auto start = deque.begin() ; start != deque.end(); start += 1) {
        std::cout<<"\t"<< *start;
    }
    std::cout<<std::endl;
}

int main() {
    std::deque<int> deque{1, 2, 3, 4};
    // [1, 2, 3, 4]
    tranverse(deque);


    deque.push_back(5); 
    // [1, 2, 3, 4, 5]


    deque.insert(deque.end() - 1, { 7, 8}); 
    // [ 1, 2, 3, 4, 7, 8, 5}
    tranverse(deque);


    deque.pop_front();
    // [ 2, 3, 4, 7, 8, 5 ]


    deque.erase(deque.begin()+2, deque.end()-2); 
    // [ 2, 3, 8, 5 ]
    tranverse(deque);


    deque.pop_back();
    // [ 2, 3, 8]
    tranverse(deque);


    deque.push_front(1);
    // [ 1, 2, 3, 8]


    deque.clear();
}