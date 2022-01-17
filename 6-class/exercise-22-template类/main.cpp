#include <iostream>
#include <string>

template<typename T, typename S>
class Computer {
    
    public: using id_type=T;

    private:
        T id;
        S price;
    
    public:
        Computer(T _id, S _price): id(_id), price(_price) {}

        template<typename K>
        void echo(K message) { std::cout << message << std::endl; }
};

template< typename T, typename S, template<typename PT, typename PS> class Purchase>
class Store {

    private:
        Purchase<T, S>* purchase;

    public:
        Store(T id, S price) { purchase = new Purchase<T, S>(id, price); }

        // template<typename K>
        // void echo(K message);

        template<typename K>
        void echo(K message) {
            purchase->echo(message);
        }

        ~Store() { delete purchase; }
};
// template< typename T, typename S, template<typename PT, typename PS> class Purchase >
// template< typename K>
// void Store<T, S, Purchase>::echo(K message) {  purchase->echo(message); }

template<typename T>
void print(T t) {
    typename T::id_type id = 0;
}

int main() {

    Computer<std::string, int> computer("acee1234", 5000);

    computer.echo("hello , welcome to our computer Inc");

    Store<std::string, int, Computer> store("bdaa4321", 5200);

    store.echo("hello, welcome to our store");

    print(computer);
}

// 运行代码 make run c=6 e=22

// 解释下第18行开始的模板定义
// 模板有3个泛型参数，其中 泛型 Purchase的类型又刚好是一个有2个参数的模板，

// 在第24行使用 泛型 Purchase, 因为它自身是一个模板，必须具体化才能使用，
// 而 PT PS只是一种声明，表明 Purchase模板有两个泛型而已，所以具体化时
// 不能使用 PT、PS，而是使用 T、S；

// 同时，第24行给出的是指针，而不是 Purchase<T, S> purchase, 因为这种形式
// 下，purchase会立即初始化，而我们并不想立即初始化，而是想 在 Store构造函数
// 中初始化。

// 第32行定义的是成员函数，不过该成员函数不使用 Store的泛型，而是使用自己的
// 泛型参数，因此要加上 template<typename K>.

// 第32行的成员函数直接在类内部给出定义，如果想采取类内部声明，外部给出定义的话，
// 请将第32～35行代码注释，打开29～30 39～41行的注释。


// 第7行使用啦using定义啦一个类型 id_type；
// 在第45行 使用 typename T::id_type 使用了这个 id_type，
// typename就是在强调使用 ::访问的是一个类型，不是类变量，类函数；
// 值得注意的是，第7行给出了public限制符，否则第45行无法访问！
// 
//
// 所以，C++的泛型表述能力，还是非常强啊
// 当然， Rust、Java、Ts 也不弱。

// 请记住： 模板具体化后，才是一种类型！