# 第四章 《复合类型》 编程练习题之我解

## 4.1

**题：** 编写一个程序，如下输出实例所示的请求并显示信息：

```bash
What is your first name? Betty Sue
Waht is your last name? Yewe
What letter grade do you deserve? B 
What is your age? 22

Name: Yewe, Betty Sue
Grade: C 
Age: 22

```

> 程序应接受的名字包含多个单词。另外，程序将向下调整成绩。假设用户请求A、B或C，所以不必担心 D 和 F 之间的空档。


## 4.2

**题：** 修改程序清单4.4，使用C++ string类而不是char数组。

## 4.3

**题：** 编写一个程序，它要求用户首先输入其名，然后输入其姓；然 后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用char数组和头文件cstring中的函数。下面是该程序运行时的 情形：

```bash
Enter your first name: Flip
Enter your last name: Fleming
Here's the information in a single string: Fleming, Flip

```


## 4.4

**题：** 编写一个程序，它要求用户首先输入其名，再输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用string对象和头文件string中的函数。下面是该程序运行时的情形：

```bash
Enter your first name: Flip
Enter your last name: Fleming
Here's the information in a single string: Fleming, Flip

```


## 4.5

**题：** 结构CandyBar包含3个成员。第一个成员存储了糖块的品牌；第 二个成员存储糖块的重量（可以有小数）；第三个成员存储了糖块的卡路里含量（整数）。请编写一个程序，声明这个结构，创建一个名为 `snack` 的 `CandyBar` 变量，并将其成员分别初始化为 "Mocha Munch"、2.3 和 350。初始化应在声明 `snack` 时进行。最后，程序显示 `snack` 变量的内容。



## 4.6

**题：** 结构体 `CandyBar` 包含3个成员，如 `编程练习5`所示。请编写一个程序，创建一个包含3个元素的 `CandyBar` 数组，并将它们初始化为所选择的值，然后显示每个结构体的内容。



## 4.7

**题：** William Wingate从事比萨饼分析服务。对于每个披萨饼，他都 需要记录下列信息：

- 披萨饼公司的名称，可以有多个单词组成；
- 披萨饼的直径；
- 披萨饼的重量。

请设计一个能够存储这些信息的结构，并编写一个使用这种结构变量的程序。程序将请求用户输入上述信息，然后显示这些信息。请使用 cin（或它的方法）和cout。


## 4.8

**题：** 完成编程练习7，但使用 `new` 来为结构分配内存，而不是声明一个结构体变量。另外，让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。

## 4.9

**题：** 完成编程练习6，但使用new来动态分配数组，而不是声明一个包含3个元素的 `CandyBar` 数组。

## 4.10

**题：** 编写一个程序，让用户输入三次40码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩），并显示次数和平均成绩。请使用一个`array`对象来存储数据（如果编译器不支持 `array` 类，请使用数组）。




