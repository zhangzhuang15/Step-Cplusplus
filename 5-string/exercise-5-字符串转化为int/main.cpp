#include <iostream>
#include <sstream>
#include <string>

float  self_transfer(std::string s) {

    float result = 0;

    std::stringstream ss; // 使用 stringstream 必须引入 sstream
    ss << s;              // s输出到 ss
    ss >> result;         // 根据 result的类型将 ss中存储的字符转化为对应类型的数据，空白符会跳过，读到不符合该类型数据的非法符号
                          // 会停止继续转化
    return result; 
    
}

int main() {

    std::string s = "22";

    int m = atoi(s.c_str());
    std::cout << "m: " << m << std::endl;

    int n = strtol(s.c_str(), NULL, 8);
    std::cout << "n: " << n << std::endl;

    std::cout << "self_transfer: " << self_transfer("3.1415") << std::endl;
}


// 运行代码 make run c=5 e=5

// std::string类型的字符串，可以使用 c_str()方法转换为 char* 的c风格字符串