#include <iostream>
#include <memory>
#include <string>

class Man {
    private:
    std::string _name;
    public:
    Man(std::string name): _name(name) {};
    ~Man() { std::cout << this->_name << ": goodbye" << std::endl; }
};

int main() {
   std::weak_ptr<Man> m;
   {
     auto man = std::make_shared<Man>("Peter");
     m = man;
   }
   // m cannot stop man being released
   return 0;
}