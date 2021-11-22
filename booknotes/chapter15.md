# 第十五章 友元、异常和其他

本章内容包括：

- 友元类；
- 友元类方法；
- 嵌套类；
- 引发异常、`try`块和`catch`块；
- 异常类；
- 运行阶段类型识别（RTTI）；
- `dynamic_cast` 和 `typeid`；
- `static_cast`、`const_cast` 和 `reiterpret_cast`。


![image-20210815204948714](https://static.fungenomics.com/images/2021/08/image-20210815204948714.png)

2．bad_alloc异常和new

对于使用new导致的内存分配问题，C++的**最新处理方式是让new引发bad_alloc异常**。头文件new包含bad_alloc类的声明，它是从exception 类公有派生而来的。但**在以前，当无法分配请求的内存量时，new返回 一个空指针**，然后我们可以 `exit(EXIT_FAILURE)`。


## 15.6 总结

友元使得能够为类开发更灵活的接口。类可以将其他函数、其他类 和其他类的成员函数作为友元。在某些情况下，可能需要使用前向声 明，需要特别注意类和方法声明的顺序，以正确地组合友元。

嵌套类是在其他类中声明的类，它有助于设计这样的助手类，即实 现其他类，但不必是公有接口的组成部分。
