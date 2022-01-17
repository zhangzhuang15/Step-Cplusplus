```c++

class Computer {};

class Tool {};

class MacBook: Tool, Computer {};

```

* 构造函数执行顺序： Tool->Computer->MacBook
* 析构函数执行顺序： MacBook->Computer->Tool

具体请在 `main.cpp` 中验证