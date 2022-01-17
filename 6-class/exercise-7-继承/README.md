运行代码 `make run c=6 e=7`

##### 第 29 行代码`price(_price)`报错  
> 表明：  
> * Computer中的 price 是 protected, 可以被 MacBook继承并使用；
> * price不能通过MacBook的构造函数初始化；

##### 第 41 行代码`print(id);`报错
> 表明：  
> * Computer中的 id 是 private，无法被 MacBook 使用；

&nbsp;

注释第41、42行代码，去掉第29行代码片段`,price(_price)`, 再运行  

&nbsp;

#### 报错， MacBook构造函数应该调用 Computer的默认构造函数，但是该函数没有找到  
> 表明：
> * 如果我们没有定义构造函数，编译器会为我们默认生层构造函数；
> * 一旦我们定义了构造函数，编译器就不会默认生成构造函数；
> * 子类的构造函数必须调用父类的构造函数，无论这种调用是我们明写出来的，还是编译器偷偷帮我们调用的；  


&nbsp;

注释掉第28、29行代码，打开第31、32、33行代码的注释，再运行

&nbsp;

注释掉 MacBook的 echo方法，再运行  
`运行成功🎉`

&nbsp;

将第23行代码中的 public 分别改为 protected、private，比较两次运行结果  
`运行失败😭`   
根据错误信息
> 表明：
>  * 这两种继承方式下，public成员将不能在类的外部访问；
>  * protected继承方式下，原来是protected、public的成员，一律会变成protected成员，最多由子类访问；
>  * private继承方式下，一律变成private成员，只能在类内部访问；
>  * 原来private的成员，不受到影响，因为子类无论咋继承，都‘看不到’它们；

&nbsp;

第23行 写成 class MacBook: Computer 再运行下  
`运行失败😭`  
根据错误信息
> 表明：
>  * 默认继承方式是 private
