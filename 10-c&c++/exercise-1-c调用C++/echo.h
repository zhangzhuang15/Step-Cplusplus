#ifndef _ECHO
#define _ECHO

extern "C" {
    void echo(char* p);
}

#endif



// C++代码照常声明，定义，
// 对于要暴露给C调用的，需要使用 extern "C"修饰，
// 告诉编译器按照 C 的风格给这些函数命名，不要搞C++那一套

// 单行直接加 extern “C” 完事儿
//
// 多个函数的话，可以用 extern “C” {}括上
//
// 具体咋编译，见 Makefile