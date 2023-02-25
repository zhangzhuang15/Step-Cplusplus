#include <iostream>

class Human {
    public:
    void hello() { std::cout << "Human" << std::endl; }
};

class Man: Human {
    public:
    void hello() { std::cout << "Man" << std::endl; }
};

int main() {
    Human human;
    Man man;

    auto t = dynamic_cast<Man*>(&human);
    auto p = dynamic_cast<Human*>(&man);

    t->hello();
    p->hello();

    return 0;
}

// run under -std=c++17
// follow the compiler errors, learn everything