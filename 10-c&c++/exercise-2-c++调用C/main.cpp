extern "C" {
    #include "echo.h"
}

int main() {
    char* m = "this is c++ main file";

    echo(m);
}

// 运行代码 切换到本目录下，执行 make

// 清除 main echo.o ： make clean 

// C++调用C时，C代码该怎么声明怎么声明，该怎么定义怎么定义；
// 在C++中需要使用 extern "C" {} 将 #include 括起来，
// 告诉编译器，这个头文件里边声明的函数都是C风格的函数，调用
// 的时候你也给我按照这种风格寻找相应的同名函数。