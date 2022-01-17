#include <iostream>
#include <string>

#define println(item) std::cout << item << std::endl

int main() {

    std::string s("");

    if(s.empty()) std::cout << "s is empty" << std::endl;

    s.append("this");
    // "this"
    println(s);

    s.append(2, 'a');
    // "thisaa"
    println(s);

    s.append("demo is wrong", 4, 4);
    // "thisaa is "
    println(s);

    s.append("open your heart", 4);
    // "thisaa is open"
    println(s);



    s.push_back('H');
    // "thisaa is openH"
    println(s);

    s.pop_back();
    // "thisaa is open"
    println(s);




    if(s.find("saa", 2) > 0) println("找到 saa");
    if(s.find("is", 4, 6) > 0) println("在 s[4,10）找到 is");


    std::string substr = s.substr(0, 4); // 深拷贝
    // "this"
    substr[0] = 'T';

    println(s);
    // "thisaa is open"


    s.erase(4, 2);
    // "this is open"
    println(s);



    s.replace(0, 4, "I like That style", 7, 4); // 还有其他重载形式，查看API，这里就不再举例啦
    // "That is open"
    println(s);


    std::cout << "s size: " << s.size() << std::endl; // 12
    std::cout << "s length: " << s.length() << std::endl; // 12
    std::cout << "s capacity: " << s.capacity() << std::endl; // 22

    println("");

    s.shrink_to_fit();

    std::cout << "s size: " << s.size() << std::endl; // 12
    std::cout << "s length: " << s.length() << std::endl; // 12
    std::cout << "s capacity: " << s.capacity() << std::endl; // 12

    println("");

    s.resize(18);
    std::cout << "s size: " << s.size() << std::endl; // 18
    std::cout << "s length: " << s.length() << std::endl; // 18
    std::cout << "s capacity: " << s.capacity() << std::endl; // 22

    println("");


    if(s.compare("A string") > 0) println("s is greater than 'A string'");


    s.insert(8, "not "); // 其他重载形式查看API吧
    std::cout << s << std::endl;

    s.clear();

}

// 运行代码 make run c=5 e=3