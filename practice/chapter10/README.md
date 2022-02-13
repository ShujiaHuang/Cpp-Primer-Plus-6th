# 第十章 《对象和类》 编程练习题之我解

## 10.1 

**题：** 为复习题5描述的类提供方法定义，并编写一个小程序来演示所 有的特性。

> 复习题5：定义一个类来表示银行帐户。数据成员包括储户姓名、账号 (使用字符串)和存款。成员函数执行如下操作:
>
> * 创建一个对象并将其初始化;
> * 显示储户姓名、账号和存款;
> * 存入参数指定的存款;
> * 取出参数指定的款项。

## 10.2 

**题：** 下面是一个非常简单的类定义:

```cpp
class Person {
private:
    // static const LIMIT = 25 编译报错，C++不支持默认int
    static const int LIMIT = 25;
    string lname;
    char fname[LIMIT];
 
public:
    Person() { lname = ""; fname[0] = '\0'; }  // #1
    Person(const string & ln, const char * fn = "Heyyou");  // #2
    void Show() const;
    void FormalShow() const;
};
```

它使用了一个string对象和一个字符数组，让您能够比较它们的用 法。请提供未定义的方法的代码，以完成这个类的实现。再编写一个使 用这个类的程序，它使用了三种可能的构造函数调用(没有参数、一个 参数和两个参数)以及两种显示方法。下面是一个使用这些构造函数和 方法的例子:

```cpp
Person one;                     // default constructor
Person two("Smythecraft");      // use #2 with one default argument
Person three("Dimwidy", "Sam"); // use #2 with no defaults.

one.show();
cout << endl;
one.FormalShow();
```

## 10.3

**题：** 3.完成第9章的编程练习1，但要用正确的golf类声明替换那里的代 码。用带合适参数的构造函数替换 `setgolf(golf &, const char *, int)`， 以提供初始值。保留`setgolf( )` 的交互版本，但要用构造函数来实现它 (例如，`setgolf( )` 的代码应该获得数据，将数据传递给构造函数来创建 一个临时对象，并将其赋给调用对象，即`*this`)。



## 10.4

**题：** 完成第9章的编程练习4，但将Sales结构及相关的函数转换为一个类及其方法。用构造函数替换 `setSales(sales &，double [ ]，int)` 函数。用构造函数实现 `setSales(Sales &)` 方法的交互版本。将类保留在名称空间SALES中。



## 10.5

**题：** 考虑下面的结构声明:

```cpp
struct customer {
    char fullname[35];
    double payment;
}
```

编写一个程序，它从栈中添加和删除 `customer` 结构(栈用 `Stack` 类声明表示)。每次 `customer` 结构被删除时，其 `payment` 的值都被加入到总数中，并报告总数。

> 注意: 应该可以直接使用 `Stack` 类而不作修改;只需修改 `typedef` 声明，使 `Item` 的类型为 `customer`，而不是 `unsigned long` 即可。

## 10.6

下面是一个类声明:

```cpp
class Move {
private:
    double x;
    double y;
public:
    Move(double a=0, double b = 0);
    showmove() const;
    Move add(const Move &m) const:
    reset(double a = 0, double b = 0);
}
```

请提供成员函数的定义并测试这个类的测序。

## 10.7

**题：** Betelgeusean plorg有这些特征。

数据：

* plorg的名称不超过19个字符;
* plorg有满意指数(CI)，这是一个整数。

操作：

* 新的plorg将有名称，其CI值为50;
* plorg的CI可以修改;
* plorg可以报告其名称和CI;
* plorg的默认名称为“Plorga”。

请编写一个 `Plorg` 类声明(包括数据成员和成员函数原型)来表示 `plorg`，并编写成员函数的函数定义。然后编写一个小程序，以演示 `Plorg` 类的所有特性。

## 10.8

**题：** 可以将简单列表描述成下面这样:

* 可存储0或多个某种类型的列表;
* 可创建空列表;
* 可在列表中添加数据项;
* 可确定列表是否为空;
* 可确定列表是否为满; 可访问列表中的每一个数据项，并对它执行某种操作。

```
可以看到，这个列表确实很简单，例如，它不允许插入或删除数据
项。
```

请设计一个List类来表示这种抽象类型。您应提供头文件list.h和实 现文件list.cpp，前者包含类定义，后者包含类方法的实现。您还应创建 一个简短的程序来使用这个类。

该列表的规范很简单，这主要旨在简化这个编程练习。可以选择使用数组或链表来实现该列表，但公有接口不应依赖于所做的选择。也就是说，公有接口不应有数组索引、节点指针等。应使用通用概念来表达创建列表、在列表中添加数据项等操作。对于访问数据项以及执行操作，通常应使用将函数指针作为参数的函数来处理:

```cpp
void visit(void (*pf)(Item &));
```

其中，pf指向一个将Item引用作为参数的函数(不是成员函数)，Item是列表中数据项的类型。`visit()` 函数将该函数用于列表中的每个数据项。









