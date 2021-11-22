# 第十一章 使用类

本章内容包括：

- 运算符重载；
- 友元函数；
- 重载 `<<` 运算符，以便用于输出；
- 状态成员；
- 使用 `rand()` 生成随机值；
- 类的自动转换和强制类型转换；
- 类转换函数。


学习C++的难点之一是需要记住大量的东西，但在拥有丰富的实践 经验之前，根本不可能全部记住这些东西。从这种意义上说，学习 C++ 就像学习功能复杂的字处理程序或电子制表程序一样。任何特性都不可怕，但多数人只掌握了那些经常使用的特性，如查找文本或设置为 斜体等。您可能在那里曾经学过如何生成替换字符或者创建目录，除非经常使用它们，否则这些技能可能根本与日常工作无关。也许，学习本 章知识的最好方法是，在我们自己开发的C++程序中使用其中的新特性。


## 11.1 运算符重载

运算符重载是一种形式的 C++ 多态。
运算符 重载将重载的概念扩展到运算符上，允许赋予C++运算符多种含义。实 际上，很多C++（也包括C语言）运算符已经被重载。例如，将 `*` 运算符用于地址，将得到存储在这个地址中的值；但将它用于两个数字时，得到的将是它们的乘积。C++根据操作数的数目和类型来决定采用哪种操 作。

重载运算符可使代码看起来更自然。

要重载运算符，需使用被称为运算符函数的特殊函数形式。运算符函数的格式为：`operatorop(argument-list)`。

例如，`operator +()` 重载 `+` 运算符，`operator *()` 重载 `*` 运算符。`op` 必须是有效的C++运算符，不能虚构一个新的符号。例如，不能有 `operator@()` 这样的函数，因为C++中没有 `@` 运算符。然而，`operator` 函数可以重载 `[]` 运算符，因为 `[]` 是数组索引运算符。

## 11.2 计算时间：一个运算符重载示例

定义一个 `Time` 类:

```Cpp
// mytime0.h -- Time class before operator overloading
#ifndef MYTIME0_H_
#define MYTIME0_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time Sum(const Time & t) const;
    void Show() const;
};
#endif
```

该类的定义：

```Cpp
#include <iostream>
#include "mytime0.h"

Time::Time()
{
    hours = minutes = 0;
}

Time::Time(int h, int m )
{
    hours = h;
    minutes = m;
}

void Time::AddMin(int m)
{
    minutes += m;
    hours += minutes / 60;
    minutes %= 60;
}

void Time::AddHr(int h)
{
    hours += h;
}

void Time::Reset(int h, int m)
{
    hours = h;
    minutes = m;
}

Time Time::Sum(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

void Time::Show() const
{
    std::cout << hours << " hours, " << minutes << " minutes";
}
```


来看一下 `Sum()` 函数的代码。注意参数是引用，但返回类型却不是 引用。将参数声明为引用的目的是为了提高效率。如果按值传递 `Time` 对象，代码的功能将相同，但传递引用，速度将更快，使用的内存将更少。

然而，返回值不能是引用。因为函数将创建一个新的Time对象 （sum），来表示另外两个Time对象的和。返回对象（如代码所做的那 样）将创建对象的副本，而调用函数可以使用它。然而，如果返回类型 为 `Time &`，则引用的将是 `sum` 对象。但由于 `sum` 对象是局部变量，在函数结束时将被删除，因此引用将指向一个不存在的对象。使用返回类型 `Time` 意味着程序将在删除 `sum` 之前构造它的拷贝，调用函数将得到该拷贝。

> 不要返回指向局部变量或临时对象的引用。函数执行完毕后，局部变量和临时对象将消失， 引用将指向不存在的数据。

但这种 sum 时间的方法看起来很傻。

### 11.2.1 添加加法运算符

将Time类转换为重载的加法运算符很容易，只要将`Sum()` 的名称改为 `operator +()` 即可。

```Cpp
// mytime1.h -- Time class before operator overloading
#ifndef MYTIME1_H_
#define MYTIME1_H_

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+ (const Time & t) const;
    void Show() const;
};
#endif
```

类定义中改为：

```Cpp
// mytime1.cpp  -- implementing Time methods
#include <iostream>
#include "mytime1.h"
...
Time Time::operator+(const Time & t) const
{
    Time sum;
    sum.minutes = minutes + t.minutes;
    sum.hours = hours + t.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}
...
```

将该方法命令改为 `operator +()` 后，就可以使用运算符表示法：

```Cpp
total = coding + fixing;
```

```Cpp
// usetime1.cpp -- using the second draft of the Time class
// compile usetime1.cpp and mytime1.cpp together
#include <iostream>
#include "mytime1.h"

int main()
{
    using std::cout;
    using std::endl;
    Time planning;
    Time coding(2, 40);
    Time fixing(5, 55);
    Time total;

    total = coding + fixing;
    cout << "coding + fixing = ";
    total.Show();
    cout << endl;

    return 0;
}
```

### 11.2.2 重载限制

![image-20210812010750643](https://static.fungenomics.com/images/2021/08/image-20210812010750643.png)

多数C++运算符（参见表11.1）都可以用这样的方式重载。重载的运算符（有些例外情况）不必是成员函数，但必须至少有一个操作数是 用户定义的类型。下面详细介绍C++对用户定义的运算符重载的限制：

- 1．重载后的运算符**必须至少有一个操作数是用户定义的类型**，这将防止用户为标准类型重载运算符；
- 2．使用运算符时不能违反运算符原来的句法规则。例如不要将 `-` 重载为加法运算。同样，不能修改运算符的优先级；
- 3．不能创建新运算符。例如，不能定义 `operator **()` 函数来表示求幂；
- 4．不能重载下面的运算符：

![image-20210812010658117](https://static.fungenomics.com/images/2021/08/image-20210812010658117.png)

- 5．表11.1中的大多数运算符都可以通过成员或非成员函数进行重 载，但下面的运算符只能通过成员函数进行重载。

![image-20210812010824269](https://static.fungenomics.com/images/2021/08/image-20210812010824269.png)

### 11.2.3 其他重载运算符

还有一些其他的操作对 `Time` 类来说是有意义的。例如，可能要将两个时间相减或将时间乘以一个因子，这需要重载减法和乘法运算符。这 和重载加法运算符采用的技术相同，即创建 `operator –()` 和 `operator *()` 方法。也就是说，将下面的原型添加到类声明中：

```Cpp
Time operator- (const time & t) const;
Time operator* (double n) const;
```

修改类定义：

```Cpp
// mytime2.cpp  -- implementing Time methods
#include <iostream>
#include "mytime2.h"

...
Time Time::operator-(const Time & t) const
{
    Time diff;
    int tot1, tot2;
    tot1 = t.minutes + 60 * t.hours;
    tot2 = minutes + 60 * hours;
    diff.minutes = (tot2 - tot1) % 60;
    diff.hours = (tot2 - tot1) / 60;
    return diff;
}

Time Time::operator*(double mult) const
{
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
...
```

## 11.3 友元

通常，公有类方法提 供唯一的访问途径，但是有时候这种限制太严格，以致于不适合特定的 编程问题。在这种情况下，C++提供了另外一种形式的访问权限：友 元。友元有3种：

- 友元函数；
- 友元类；
- 友元成员函数。

通过让函数成为类的友元，可以赋予该函数与类的成员函数相同的访问权限。

需要友元的原因是为了解决这样一个问题：

![image-20210812011654884](https://static.fungenomics.com/images/2021/08/image-20210812011654884.png)

![image-20210812011808963](https://static.fungenomics.com/images/2021/08/image-20210812011808963.png)

对于非成员重载运算符函数来说，**运算符表达式左边的操作数对应于运算符函数的第一个参数，运算符表达式右边的操作数对应于运算符函数的第二个参数**。而原来的成员函数则按相反的顺序处理操作数，也就是说，double值乘以Time值。

使用非成员函数可以按所需的顺序获得操作数（先是double，然后 是Time），但引发了一个新问题：**非成员函数不能直接访问类的私有数据，至少常规非成员函数不能访问**。然而，有一类特殊的*非成员函数*可以访问类的私有成员，它们被称为友元函数。

### 11.3.1 创建友元

创建友元函数的第一步是将其原型放在类声明中，并在原型声明前 加上关键字 `friend`。

```Cpp
friend Time operator* (double m, const Time & t);
```

该原型意味着下面两点：

- 虽然 `operator *()` 函数是在类声明中声明的，但它不是成员函数，因 此不能使用成员运算符来调用；
- 虽然 `operator *()` 函数不是成员函数，但它与成员函数的访问权限相同。

第二步是编写函数定义。**因为它不是成员函数**，所以不要使用 `Time::` 限定符。另外，不要在定义中使用关键字 `friend`，定义应该如下：

```Cpp
Time operator*(double mult) {
    Time result;
    long totalminutes = hours * mult * 60 + minutes * mult;
    result.hours = totalminutes / 60;
    result.minutes = totalminutes % 60;
    return result;
}
```

有了上述声明和定义后，语句：`A = 2.75 * B` 就被自动转换为 `A = operator*(2.75, B)`。

总之，**类的友元函数是非成员函数，但访问权限与成员函数相同**。

### 11.3.2 常用的友元：重载 `<<` 运算符

```Cpp
// mytime3.h -- Time class with friends
#ifndef MYTIME3_H_
#define MYTIME3_H_
#include <iostream>

class Time
{
private:
    int hours;
    int minutes;
public:
    Time();
    Time(int h, int m = 0);
    void AddMin(int m);
    void AddHr(int h);
    void Reset(int h = 0, int m = 0);
    Time operator+(const Time & t) const;
    Time operator-(const Time & t) const;
    Time operator*(double n) const;
    friend Time operator*(double m, const Time & t)
        { return t * m; }   // inline definition
    friend std::ostream & operator<<(std::ostream & os, const Time & t);

};
#endif
```
代码中对 `friend Time operator*(double m, const Time & t)` 的重载定义非常棒，是一个相当聪明的做法！它不是重新写一段代码，而是调用已重载的 `Time operator*(double n) const` 成员函数。



## 11.4 重载运算符：作为成员函数还是非成员函数

一般来说，非成员函数应是友元函数，这样它才能直接访 问类的私有数据。加法运算符需要两个操作数。对于成员函数版本来说，一个操作数 通过this指针隐式地传递，另一个操作数作为函数参数显式地传递；对 于友元版本来说，两个操作数都作为参数来传递。

对于某些运算符来说（如前所述），成员函数是唯一合法的选择。在其他情况下，这两种格式没有太大的区别。有时，根据类设计，使用非成员函数版本可能更好（尤其是为类定义类型 转换时）。

## 11.5 再谈重载：一个矢量类

```Cpp
    // subtract Vector b from a
    Vector Vector::operator-(const Vector & b) const
    {
        return Vector(x - b.x, y - b.y);
    }

    // reverse sign of Vector
    Vector Vector::operator-() const
    {
        return Vector(-x, -y);
    }
```

operator-( )有两种不同的定义。这是可行的，因为它们的特征标不同（两个矢量相减，或者单个矢量取反）。可以定义−运算符的一元和二元版本，因为C++提供了该运 算符的一元和二元版本。对于只有二元形式的运算符（如除法运算符），只能将其重载为二元运算符。

> 因为运算符重载是通过函数来实现的，所以只要运算符函数的特征标不同，使用的运算符数 量与相应的内置C++运算符相同，就可以多次重载同一个运算符。

## 11.6 类的自动转换和强制类型转换
## 11.7 总结
一般来说，访问私有类成员的唯一方法是使用类方法。C++使用友 元函数来避开这种限制。要让函数成为友元，需要在类声明中声明该函 数，并在声明前加上关键字friend。

C++扩展了对运算符的重载，允许自定义特殊的运算符函数，这种 函数描述了特定的运算符与类之间的关系。运算符函数可以是类成员函数，也可以是友元函数（有一些运算符函数只能是类成员函数）。

最常见的运算符重载任务之一是定义<<运算符，使之可与cout一起 使用，来显示对象的内容。要让ostream对象成为第一个操作数，需要将 运算符函数定义为友元；要使重新定义的运算符能与其自身拼接，需要 将返回类型声明为 `ostream &`。

![image-20210812015334769](https://static.fungenomics.com/images/2021/08/image-20210812015334769.png)

然而，如果类包含这样的方法，它返回需要显示的数据成员的值， 则可以使用这些方法，无需在`operator<<()`中直接访问这些成员。在这种情况下，函数不必（也不应当）是友元。

C++允许指定在类和基本类型之间进行转换的方式。首先，任何接 受唯一一个参数的构造函数都可被用作转换函数，将类型与该参数相同 的值转换为类。如果将类型与该参数相同的值赋给对象，则C++将自动调用该构造函数。

要将类对象转换为其他类型，必须定义转换函数，指出如何进行这种转换。转换函数必须是成员函数。
