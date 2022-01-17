#include <iostream>
#include "add.h"
#include "sub.h"

using namespace std;
using namespace my_tool;

int main(){
    int a = 10, b = 5;
    float aa = 10.125, bb = 4.315;

    add(a, b);
    add(aa, bb);
    sub(a, b);
    sub(aa, bb);

    extra_add::add(a, b);  
}

// 运行代码 make run c=24