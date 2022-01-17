#include <iostream>

class Computer {

    private:
      int price;

    public:
      explicit Computer(): price(4000) {}
      explicit Computer(int _price): price(_price) {}
      //Computer(Computer& computer): price(computer.price){}
      //Computer(Computer&& computer): price(computer.price){}
 
      // 重载 关系运算符
      bool operator== (Computer& computer) { return price == computer.price; }
      bool operator> (Computer& computer) { return price > computer.price; }
      bool operator< (Computer& computer) { return price < computer.price; }
      bool operator>= (Computer& computer) { return price >= computer.price; }
      bool operator<= (Computer& computer) { return price <= computer.price; }
      bool operator!= (Computer& computer) { return price != computer.price; }

      // 重载 逻辑运算符
      bool operator! () { return !price; }
      bool operator&& (Computer& computer) { return price && computer.price ; }
      bool operator|| (Computer& computer) { return price || computer.price; }

      // 重载 位运算符
      int operator| (Computer& computer) { return price | computer.price; }
      int operator& (Computer& computer) { return price & computer.price; }
      // 重载 异或运算符
      int operator^ (Computer& computer) { return price ^ computer.price; }

      // 重载 移位运算符
      int operator>> (int num) { return price >> num; }
      int operator<< (int num) { return price << num; }


      // 重载 加法运算
      Computer operator+ (Computer& computer) {
          int _price = price + computer.price;
          Computer _computer(_price);
          return _computer;
      }


      // 重载 +=运算符
      Computer operator+= (Computer& computer) {
          price += computer.price;
          return *this;
      }


      // 重载 乘法运算
      Computer operator* (Computer& computer) {
          int _price = price * computer.price;
          Computer _computer(_price);
          return _computer;
      }


      // 重载 除法运算
      Computer operator/ (Computer& computer) {
          int _price = price / computer.price;
          Computer _computer(_price);
          return _computer;
      }


      // 重载 赋值运算符
      Computer& operator= (Computer& computer) { price = computer.price; return *this; }
      //Computer& operator= (Computer&& computer) { price = computer.price; return *this; }


      // 后置++运算符重载， int类型的参数无实际意义，仅仅作为后置++的标志
      // 返回类型是 Computer, 如果是 Computer& 的话，会因为 _computer离开函数被释放掉引发问题
      Computer operator++ (int) {
          Computer _computer = *this;
          price++;
          return _computer;
      }


      // 前置++运算符重载
      Computer& operator++ () {
          price++;
          return *this;
      }

      
      // 重载 []访问符
      int operator[] (int num) {
          if(num < 0) return -1;
          else if(num>=0 && num < 10) return 5;
          else return 10;
      }


      // 重载 （）访问符
      void operator() (int num) {
          std::cout << "you give me an argument: " << num << std::endl;
      }

      // 重载 * 访问符，注意返回值一定是 对象 或者 对象的左值引用
      Computer& operator* () {
          std::cout << "welcome to use *" << std::endl;
          return *this;
      }

      // 重载 -> 运算符， 注意返回值一定是 指向某个对象的指针 或者 重载了 -> 运算符的对象（当然也可以是对象的左值引用）
      Computer* operator-> () {
          std::cout << "welcome to use ->" << std::endl;
          return this;
      }
 
     // 重载 int 类型转换操作，该函数不能有返回类型
      explicit operator int() {
          return price;
      }

      // 重载 cout<< 输出流操作符
      friend std::ostream& operator<< (std::ostream& out, Computer& computer) {
          return out << "Computer { price: " << computer.price << " }";
      }

      void echo() {
          std::cout << "price: " << price << std::endl;
      }

};

int main() {

    Computer black_computer(1000);
    Computer green_computer(5);

    Computer m = black_computer * green_computer;
    m.echo();

    m = black_computer / green_computer;
    m.echo();

    m = black_computer + green_computer;
    m.echo();

    *m;

    m->echo();

    int value = m;
    std::cout << "value: " << value << std::endl;

    std::cout << "m[9]: " << m[9] << std::endl;

    std::cout << m << std::endl;
}

// 运行代码  make run c=6 e=6

//
// 介绍下 左值 和 右值 的概念;
//
// int num = 4;
//
// int get() { return 4; }
//
// int age = 10;
// age = get();
//
// age 出现在等号左边，可以被重新赋值，其拥有一个确切的地址，属于 左值；
//
// 10 出现在等号右侧，它不能被重新赋值，只能把自己赋值给别的变量，而且你无法知道它的地址， 属于 右值；
//
// get函数的返回值，你同样无法知道它的地址，因此也是右值;
//
// 对于左值的引用，就是左值引用，一般被理解为变量的别称；
// 对于右值的引用，就是右值引用，只不过用2个&符号修饰表示，这是C++特有的内容，C没有。

//
// * 第 139 行 报错
// 我们重载了 = 运算符，但重载函数的参数是 左值引用；
// 而133行 =右侧 的值是 右值，编译器找不到 参数值是右值引用的 = 运算符重载函数。
//
// 去掉 71 行注释

//
// * 第 136 行 报错
// 因为上一步我们重载了 右值引用版本的 = 运算符函数，
// 编译器于是删除了上一步默认生成的拷贝构造函数，
// 找不到拷贝构造函数，当然就要报错啦。
// 观察 136行 =右侧的值是一个右值，因此应该加入移动构造函数（exercise-1简单介绍过）
//
// 去掉 12 行注释

//
// 第 49 行报错
// 这一行其实调用了拷贝构造函数，但因为我们重载了 = 运算符，
// 编译器于是将默认的拷贝构造函数删除了。
// 上一步我们加入的构造函数，其参数是 右值引用，但这里需要 左值引用，
// 结果还是报错了
//
// 去掉 11 行注释

//
// 第 149 行报错
// 看看 115 行的定义，瞧见了吧，explicit！ 上一节修饰了构造函数，
// 这里修饰 运算符重载函数。
// 149 行的写法，其实是触发 类型的隐式转换，不过很可惜，explicit给限制住了
// 因此我们要显示转换。
//
// 将149行代码改为
//
// 方法1: int value = (int)m;
//
// 方法2: int value = static_cast<int>(m);
// cast 有 抛、描述的含义，这里就是进行强行转换，描述为int

//
//  