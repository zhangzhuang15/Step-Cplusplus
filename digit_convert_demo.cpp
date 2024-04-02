#include <iostream>
#include <stack>

// 将十进制数 num， 转换为 base 进制数，并打印出来
void convert(int num, int base) {
    static char S[] = {'0', '1', '2', '3', '4', '5', '6', '7',
    '8', '9', 'A', 'B', 'C', 'D', 'E', 'F'};

    std::stack<char> stack;

    while(num > 0) {
        int tmp = num % base;
        stack.push(S[tmp]);
        num /= base;
    }

    while(!stack.empty()) {
        char p = stack.top();
        std::cout<<p;
        stack.pop();
    }
    std::cout<<std::endl;
}

int main() {
    int base = 0;
    int num = 0;
    while(true) {
        std::cout<<"输入进制数(输入0退出):" << std::endl;
        std::cin>>base;
        if (base == 0) break;
        std::cout<<"输入十进制数据："<< std::endl;
        std::cin>>num;
        convert(num, base);
    }
}