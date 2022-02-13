# 第13章 《类继承 》 编程练习题之我解

## 13.1

**题：** 以下面的类声明为基础：

![image-20220213124454672](https://static.fungenomics.com/images/2022/02/image-20220213124454672.png)

派生出一个Classic类，并添加一组char成员，用于存储指出CD中主 要作品的字符串。修改上述声明，使基类的所有函数都是虚的。如果上 述定义声明的某个方法并不需要，则请删除它。使用下面的程序测试您 的产品:

![image-20220213124529323](https://static.fungenomics.com/images/2022/02/image-20220213124529323.png)

![image-20220213124550849](https://static.fungenomics.com/images/2022/02/image-20220213124550849.png)

## 13.2

**题：** 完成练习1，但让两个类使用动态内存分配而不是长度固定的数组来记录字符串。

## 13.3

**题：** 修改baseDMA-lacksDMA-hasDMA类层次，让三个类都从一个 ABC派生而来，然后使用与程序清单13.10相似的程序对结果进行测 试。也就是说，它应使用ABC指针数组，并让用户决定要创建的对象类 型。在类定义中添加virtual View( )方法以处理数据显示。

## 13.4

**题：** Benevolent Order of Programmers用来维护瓶装葡萄酒箱。为描 述它，BOP Portmaster设置了一个Port类，其声明如下:

![image-20220213124715520](https://static.fungenomics.com/images/2022/02/image-20220213124715520.png)

show( )方法按下面的格式显示信息:

![image-20220213124736393](https://static.fungenomics.com/images/2022/02/image-20220213124736393.png)

`operator<<()` 函数按下面的格式显示信息(末尾没有换行符):

![image-20220213124811651](https://static.fungenomics.com/images/2022/02/image-20220213124811651.png)

PortMaster完成了Port类的方法定义后派生了VintagePort类，然后被 解职——因为不小心将一瓶45度Cockburn泼到了正在准备烤肉调料的人 身上，VintagePort类如下所示:

![image-20220213124838606](https://static.fungenomics.com/images/2022/02/image-20220213124838606.png)

您被指定负责完成VintagePort。

a.第一个任务是重新创建Port方法定义，因为前任被开除时销毁了方法定义。

b.第二个任务是解释为什么有的方法重新定义了，而有些没有重 新定义。

c.第三个任务是解释为何没有将operator=( )和operator<<( )声明为虚的。

d.第四个任务是提供VintagePort中各个方法的定义。











