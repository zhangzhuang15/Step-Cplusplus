#include <iostream>
#include <initializer_list>
#include <string>
#include <cstdarg>

// C 风格获取可变参数
void print_age(int length, bool sex, ...){
    va_list list;
    // 告诉list，可变参数有多少个
    va_start(list, sex);

    std::cout<< "可变参数总数: " << length << std::endl;
    std::cout << "性别男？"     << sex    << std::endl;

    std::cout << "打印参数" << std::endl;

    for(int i = 0; i < length; i++) {
        // 取出一个可变参数
        int age = va_arg(list, int);

        // 打印之
        std::cout << "age: " << age << std::endl;
    }

    va_end(list);
}

// C++风格
// 缺点是传入的是 {} 列表，不是变长参数
void print_age(std::initializer_list<int> list) {

    auto start = list.begin();
    auto end   = list.end();

    for( ; start != end; start += 1) std::cout << "age: " << *start << std::endl;
}

// C++风格
// 模版方式
template<typename T>
void print_name(const T& value) {
    std::cout << value << " " ;
}

template<typename K , typename... T>
void print_name(const K& value, const T& ...args) {
    std::cout << value << " ";
    print_name(args...);
}


int main() {
    print_age(4, false, 10, 34, 23, 17);

    std::cout << std::endl;

    print_age({24, 21, 26, 15, 19, 12});

    print_name("Jack", "Peter", "Nancy");
}

//
// 运行代码 make run c=2 e=8
//
// wow! it's cool🎉