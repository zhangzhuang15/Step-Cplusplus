#include <iostream>

class A {
    private:
    int age;
    public:
    A(int _age): age(_age){}
    virtual void hello() {}
};

class B: public A {
    private:
    int id;
    public:
    B(int _id, int age):id(_id), A(age) {
    } 
    virtual void why(){}
};

int main() {
    B b(2, 12);
    A a(5);

    int* ptr = reinterpret_cast<int*>(&b);
    int* ptr_a = reinterpret_cast<int*>(&a);

    std::cout << *(ptr_a -1) << std::endl;
    std::cout << *(ptr_a) << std::endl;
    std::cout << *(ptr_a + 1) << std::endl;
    std::cout << *(ptr_a + 2) << std::endl;
    std::cout << *(ptr-1) << std::endl;
    std::cout << *ptr << std::endl;
    std::cout << *(ptr+1) << std::endl;
    std::cout << *(ptr+2) << std::endl;
    std::cout << *(ptr+3) << std::endl;

    return 0;
}

/**
 * B:
 *  +-----------+
 *  +   id      +
 *  +-----------+
 *  +  age      +
 *  +-----------+
 *  +  virtual  +
 *  +   table   +
 *  +    ptr    +
 *  +-----------+   ------> ptr
 */