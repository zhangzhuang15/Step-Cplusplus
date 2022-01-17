// 关联容器： map
#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, int> map;
    // {}

    map["Jack"] = 123;
    // { "Jack": 123 }

    map.insert({"Ken", 876});
    map.insert({"Ken", 145});
    // { "Jack": 123, "Ken": 145 }

    try {
        map.at("Peter");
    } catch(std::out_of_range err) {
        map["Peter"] = 9765;
        // { "Jack": 123, "Ken": 145 , "Peter": 9765}
    }

    std::cout<<"Jack: "<<map["Peter"]<<std::endl;
    std::cout<<"Ken: "<<map["Ken"]<<std::endl;
    std::cout<<"Ken 字段数量: "<<map.count("Ken")<<std::endl;

    // find方法返回的 pair，应该用 -> 访问属性
    auto pair = map.find("Peter");
    std::cout<<"Key: "<< pair->first << "\tValue: "<< pair->second<< std::endl;
    


    std::cout << "map:" << std::endl;
    // 这里用 . 而不是用->访问属性
    for (auto ptr:map) {
        std::cout<< "\t" << ptr.first << ":"<< ptr.second <<std::endl;
    }
    std::cout << std::endl;



    
    // 由于Mercy不在map中，于是会在map中创建一个
    // Mercy键，同时为该键赋初始值，int类型的初始值
    // 是0，因此在这里 map["Mercy"] == false
    // 可是如果 Mercy本身存在，且值就是0，该判断将
    // 不能说明Mercy本身不存在
    // if (map["Mercy"] == false) {
    //     std::cout<< "没有找到Mercy" << std::endl;
    // }

    if (map.find("Mercy") == map.end()) {
        std::cout << "没有找到Mercy" << std::endl;
    }

    if (map.count("Mercy") == 0) {
        std::cout << "没有找到Mercy" << std::endl;
    }

    if (map["Peter"] == false) {
        std::cout<< "没有找到Peter" << std::endl;
    }
}

// 运行代码 make run c=21