#include <future>
#include <iostream>

using namespace std;

int run(int number) { return number + 1; }

int main() {
    auto res = std::async(run, 5);
    auto response = std::async(std::launch::async, [](int n){ cout << "hello " << run(n) << endl; }, 9);
    cout << res.get() << endl;
    response.get();
    return 0;
}