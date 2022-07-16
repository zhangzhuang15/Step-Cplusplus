#include <iostream>
#include <memory>

using namespace std;

class Man {
    public:
    ~Man() { cout << "goodbye" << endl; }
};

int main() {
    shared_ptr<Man> man(new Man());
    shared_ptr<Man> mman = man;

    // w 独占所有权
    unique_ptr<Man> w(new Man());
    // w 所有权交给 ww
    unique_ptr<Man> ww = move(w);
    return 0;
}
