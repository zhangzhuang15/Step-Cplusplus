#include <iostream>
#include <initializer_list>

class Man {
    private:
    int _age;

    public:
    Man(int age): _age(age) { std::cout << "Man Create" << std::endl; }
    Man(int age, int number): _age(age) { std::cout << number << " Man Create" << std::endl; }
    Man(Man& man) {
        this->_age = man._age;
        std::cout << "Man Copy" << std::endl;
    }
    Man(int age, int number, std::initializer_list<int> args): _age(age) {
        std::cout << "list Create";
        
        for (auto item : args) {
            std::cout << item << ' ' ;
        }

        std::cout << std::endl;
    }
    ~Man() { std::cout << this->_age << " years old" << std::endl; }
};

int main() {
    Man man_1 = 10;
    Man man_2 = { 20 };

    Man man_3(30);
    Man man_4{40};

    Man man_5 = { 50, 1 };
    Man man_6{ 60, 2 };

    Man man_7{ 70, 3, { 100, 101, 257 }};
    // failed
    Man man_8{80, 4, 300, 310, 320};

    return 0;
}

// please run this code under -std=c++17