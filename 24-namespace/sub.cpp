#include <iostream>
#include "sub.h"
using namespace std;

namespace my_tool{
    int sub(int a, int b) {
        cout<<"int sub: " << "a: "<< a <<" b: "<< b << " a-b: " << (a-b) <<endl;
        return a-b;
    }
    float sub(float a, float b) {
        cout<<"float sub: " << "a: "<< a <<" b: "<< b << " a-b: " << (a-b) <<endl;
        return a-b;
    }
    namespace extra_add{
        int add(int a, int b) {
            cout<< "extra int add: " << "a: " << a << " b: " << b << " a+b:" << (a+b) <<endl;
            return a+b;
        }
    }
}