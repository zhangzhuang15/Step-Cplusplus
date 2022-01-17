// 栈
#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;

    stack.push(22);
    stack.push(12);
    stack.push(10);
    // [22, 12, 10]

    int tp = stack.top();
    std::cout<< "stack 栈顶元素: " << tp << std::endl;

    stack.pop();
    // [22, 12]
    

    if (!stack.empty()) {
        std::cout<< "栈中还有元素" << std::endl;
    }
}

// 运行代码 make run c=17