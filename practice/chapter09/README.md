# 第九章 《内存模型和名字空间》 编程练习题之我解

## 9.1

**题：**下面是一个头文件

```cpp
const int Len = 40;
struct golf {
    char fullname[Len];
    int handicap;
};
void handicap(golf & g, int hc);
void showgolf(const golf & g);
int setgolf(golf & g);
```

注意到 setgolf() 被重载，可以这样使用其第一个版本：

```cpp
golf ann;
setgolf(ann, "Ann Birdfree", 24);
```

上述函数调用提供了存储在ann结构中的信息。可以这样使用其第二个版本:

```cpp
golf andy;
setgolf(andy);
```
上述函数将提示用户输入姓名和等级，并将它们存储在andy结构 中。这个函数可以(但是不一定必须)在内部使用第一个版本。
根据这个头文件，创建一个多文件程序。其中的一个文件名为 golf.cpp，它提供了与头文件中的原型匹配的函数定义;另一个文件应 包含main( )，并演示原型化函数的所有特性。例如，包含一个让用户输 入的循环，并使用输入的数据来填充一个由golf结构组成的数组，数组 被填满或用户将高尔夫选手的姓名设置为空字符串时，循环将结束。 main( )函数只使用头文件中原型化的函数来访问golf结构。

## 9.2

**题：** 修改程序清单9.9:用string对象代替字符数组。这样，该程序将 不再需要检查输入的字符串是否过长，同时可以将输入字符串同字符 串“”进行比较，以判断是否为空行。


## 9.3

**题：** 下面是一个结构声明:

```cpp
struct chaff {
    char dross[20];
    int slag;
};
```

编写一个程序，使用定位new运算符将一个包含两个这种结构的数 组放在一个缓冲区中。然后，给结构的成员赋值(对于char数组，使用函数 strcpy( ))，并使用一个循环来显示内容。一种方法是像程序清单 9.10那样将一个静态数组用作缓冲区;另一种方法是使用常规new运算 符来分配缓冲区。

## 9.4

**题：** 4.请基于下面这个名称空间编写一个由3个文件组成的程序:

```cpp
namespace SAIGES {
    const int QUARTERS = 4;
    struct Sales {
        double sales[QUARTERS];
        double average;
        double max;
        double min;
    };
    void setSales(Sales &s, const double ar[], int n);
    void setSales(Sales &s);
    void showSales(const Sales &s);
}
```
第一个文件是一个头文件，其中包含名称空间; 第二个文件是一个 源代码文件，它对这个名称空间进行扩展，以提供这三个函数的定义; 第三个文件声明两个Sales对象，并使用 `setSales()` 的交互式版本为一个 结构提供值，然后使用 `setSales()` 的非交互式版本为另一个结构提供值。 另外它还使用 `showSales()` 来显示这两个结构的内容。





