#include <iostream>
#include <memory>


class Man {
    public:
    Man(){}
    ~Man() { std::cout << "goodbye" << std::endl; }
};

int main() {
   
    std::unique_ptr<Man> w = std::make_unique<Man>();
    
    // failed
    std::unique_ptr<Man> t = w;

    std::unique_ptr<Man> ww = std::move(w);
    return 0;
}

// please run under -std=c++17