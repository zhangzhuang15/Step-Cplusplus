#include <iostream>
#include "add.h"
using namespace std;

namespace my_tool{
    int add(int a, int b) { 
        cout<< "int add:  " << "a: " << a << " b: " << b << " a+b: " << (a+b) <<endl;
        return a+b; }
    float add(float a, float b) { 
        cout<< "float add:  " << "a: " << a << " b: " << b << " a+b: " << (a+b) <<endl;
        return a+b; }
}