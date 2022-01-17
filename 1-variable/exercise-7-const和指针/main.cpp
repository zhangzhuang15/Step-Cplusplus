#include <iostream>

int main() {

    const int age = 20;

    float const temperature = 36.5;

    const int year = 2022;

    int day = 15;

    // 无法通过编译，因为变量被声明为 const，是常量，常量无法被修改哟！
    // 看完输出的错误信息后，注解这两行代码
    age = 25;
    temperature = 36.2;


    // ！！！！！！！ 高能预警   ！！！！！！！!

    // 下方内容会带来短时眩晕

    // 第24行 第26行 写法等价
    const int* age_ptr_1 = &age;
    
    int const* age_ptr_2 = &age;

    // 无法通过编译
    // 使用 &temperature &year &day 其中的一个替换 &age，修改错误，猜猜是哪一个？
    int* const age_ptr_3 = &day;

    const int* const age_ptr_4 = &age;

    // 无法通过编译，看完输出的错误信息后，注解本行
    *age_ptr_1 = 25;

    age_ptr_1 = &year;

    int month = 1;
    
    // 无法通过编译，看完输出的错误消息后，注解本行
    age_ptr_3 = &month;

    *age_ptr_3 = 25;

    // 无法通过编译，看完输出的错误信息后，注解本行
    *age_ptr_4 = 30;

    // 无法通过编译，看完输出的错误信息后，注解本行
    age_ptr_4 = &year;

    // 这一行为什么可以编译通过？
    age_ptr_1 = &month;

}

//  直接运行代码，看看编译器给出的错误吧
//  make run c=1 e=7

// 根据上边注释的提示，改正代码使其可以通过编译











//
//  第30行出错原因：
//      int* const age_ptr_3 = &age;
//  
//  age_ptr_3是一个指针，指向一个int型数据，由于const修饰符，这个指针不能指向另一个int型数据，
//  但是，这个指针可以修改 它所指向的数据；
//
//  age的声明是 const int, 是常量，不能修改，可 age_ptr_3拥有修改的权限，因此矛盾，报错了。




// 
//  第35行出错原因：
//      *age_ptr_1 = 25;
//
//  age_ptr_1被声明为一个指针，指向一个int型常量，因此没有修改该数据的权限，因此矛盾，出错了。





//
//  第42行出错原因：
//     age_ptr_3 = &month;
// 
//  age_ptr_3拥有const修饰符，无法再指向别的int型数据了，因此报错。



//
//  第47行出错原因：
//    *age_ptr_4 = 30;
//
//  age_ptr_4是一个指针，指向一个int型常量，无法修改该数据，且这个指针无法再指向别的int型数据
//  这里修改数据了，于是报错了




//
//  第50行出错原因：
//    age_ptr_4 = &year;
//    
//  因为age_ptr_4指针要指向另一个变量了，但它被const修饰了，没有权限指向另一个变量


//
//  第53行为什么可以编译通过
//     age_ptr_1 = &month;
//
//     const int* age_ptr_1 = &age;
//     int month = 1;
//
//  根据声明 age_ptr_1 指针不能修改所指向的数据，但是可以指向另一个int型数据，
//  也就是说，如果你使用 age_ptr_1 指针操作数据，那一定是只读操作，所以不论它
//  操作 int 还是 const int 都是一样的，不会带来安全问题。



// 总结：
//   const 位于 * 前，修饰的是 被指向的数据，表示被指向的数据是常量
//
//   const 位于 * 后，修饰的是 指针，表示这个指针一旦指向了某个数据，就不能再指向别的数据了，
//         注意，这里说的是 指向！ 不是说它无法修改所指向的数据啦！