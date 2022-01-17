#include <string>
#include <iostream>

int main() {

    std::string s = "this is A";

    for(auto m : s) std::cout << m << "\t";
    std::cout << std::endl;

    // 只读迭代器
    for(auto start = s.cbegin();start != s.cend(); start +=1) std::cout << *start << "\t";
    std::cout << std::endl;

    // 可读可写迭代器
    for(auto start = s.begin(); start != s.end(); start += 1) { *start += 1; }
    std::cout << "s[0]: " << s[0] << std::endl;
    std::cout << "s[1]: " << s.at(1) << std::endl;
}

// 运行代码 make run c=5 e=2

// 恭喜你🎉，已经知道如何遍历字符串，查找字符串的某个字符啦