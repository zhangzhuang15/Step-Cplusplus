## 本文件夹展示如何使用namespace组织多文件的C++程序开发

在.h文件和.cpp文件中都使用了namespace关键字，  
但是:
* 在.h文件的namespace块中，写的是接口；
* 在.cpp文件的namespace块中，写的是接口的实现代码；
* #include语句不能写在namespace块中！

namespace块可以嵌入到另一个namespace块；

add.h 和 sub.h 的namespace都叫 my_tool  
这表示：
* 同一个namespace内的代码可以拆开写入多个.h 或 .cpp文件中

在main.cpp文件中引用namespace中定义的函数时，  
可以这样做：
 1. 给出 using namespace my_tool。
   在使用my_tool中的add函数时，可以不用带上my_tool::前缀。
   > 使用嵌套在extra_add中的add函数时，要用extra_add::add，因为using namespace my_tool只是省略了 my_tool，其内部的namespace不能忽略；
 2. 不给出 using namespace my_tool，此时应带上前缀使用
        my_tool::add  
        my_tool::sub  
        my_tool::extra_add::add