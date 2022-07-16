#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;


void print(int&& message) {
    cout << "print: " << message << endl;
}

template<typename T>
void printT(T&& message) {
    cout << "printT: " << message << endl;
}

template<typename T>
void printConstT(const T&& message) {
    cout << "printConstT: " << message << endl;
}

template<typename T>
void printVector(vector<T>&& messages) {
    cout << "printVector: ";
    for(auto start = messages.begin(); start != messages.end(); start++) {
        cout << *start << " ";
    }
    cout << endl;
}



int main() {
    int number = 25;

    print(number);                     // 报错
    print(25);
    print(std::move(number));

    printT(number);
    printT(25);
    printT(std::move(number));

    printConstT(number);               // 报错
    printConstT(25);
    printConstT(std::move(number));

    vector<int> messages{1, 4, 5, 8};
    printVector(messages);             // 报错
    printVector(std::move(messages));
    printVector(vector<int>{1, 3, 2, 7});
}


// 运行代码： make run c=6 e=23

// 第38、46、51行报错

// 注释掉上述行，再次运行， 成功🎉


// 看来不是所有的 && 都意味着右值引用！

// print(int&& message)
// 实参必须是右值。
// 也就是说 非模板函数，int&& 确实表示右值。


// 但是在模板函数里却不一定了

// printT(T&& message)
// 实参是左值或者右值都可以。

// printConstT(const T&& message)
// 实参必须是右值才可以。

// printVector(vector<T>&& messages)
// 实参必须是右值才可以