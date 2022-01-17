// 关联容器：multimap
#include <iostream>
#include <map>
#include <string>

int main() {
    std::multimap<std::string, int> map;
    // multimap没有重载[]运算符，因此无法使用map[]

    map.insert({"Peter", 24});
    map.insert({"Peter", 25});
    map.insert({"Peter", 26});
    map.insert({"Jack", 78});
    map.insert({"Jack", 79});
    // {"Peter": 24, "Peter": 25 , "Peter": 26, "Jack": 78, "Jack": 79}

    std::cout<<"Peter出现几次? " << map.count("Peter") <<std::endl;
    std::cout<<"Jack出现几次? " << map.count("Jack") <<std::endl;
    auto pair = map.find("Peter");
    std::cout<<"Key: " << pair->first << "\tValue: "<< pair->second << std::endl;

    map.erase("Jack"); // 关于 “Jack‘ 的都删除了
    // {"Peter": 24, "Peter": 25 , "Peter": 26 }

    std::cout << "map: " << std::endl;
    for (auto pair:map){
        std::cout<< "\tKey:" << pair.first << "\tValue:" << pair.second << std::endl;
    }

    pair = map.find("Peter");

    map.erase(pair); // 只删除了 "Peter": 24
     // { "Peter": 25 , "Peter": 26 }
    
    pair = map.find("Peter");
    pair++;
    std::cout << "Peter: " << pair->second << std::endl; // 26

    std::cout << "map: " << std::endl;
    for (auto pair:map){
        std::cout<< "\tKey:" << pair.first << "\tValue:" << pair.second << std::endl;
    }
    
    
    map.clear();
}

// 运行代码 make run c=22