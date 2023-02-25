#include <iostream>
#include <memory>
#include <string>

class Man {
    private:
    std::string _name;
    
    public:
    Man(std::string name): _name(name) {}
    ~Man() { std::cout << this->_name << ": bye bye" << std::endl; }
};

int main() {
    std::shared_ptr<Man> ptr_1  = std::make_shared<Man>("Peter");
    {
        std::shared_ptr<Man> ptr_2 = ptr_1;
        std::cout << "ptr_2" << std::endl;
        // ptr_2 release, but Man won't be released
    }

    std::cout << "ptr_1" << std::endl;

    return 0;
}