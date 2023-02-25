#include <iostream>
#include <algorithm>
#include <tuple>
#include <map>
#include <list>
#include <set>
#include <string>

int main() {
    std::set<int> s;
    
    s.insert(5);
    s.insert(5);
    s.insert(3);
    s.insert(10);
    s.erase(10);

    std::for_each(s.begin(), s.end(), [](const int &i){ std::cout << i << std::endl; });

    return 0;
}