#include <assert.h>

int main() {

    int price = 200;
    const int p = 200;

    assert(price == 100); 
    static_assert(p == 100);

    return 0;
}

// 运行代码 make run c=11

// 第8行报错
// 当 assert()中的语句为真，则忽略，继续执行，否则报错，终止程序；

// assert是运行时报错
// static_assert是编译时报错