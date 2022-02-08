# 第六章 分支语句和逻辑运算符

本章的内容包括：

- `if` 语句；
- `if else` 语句；
- 逻辑运算符：`&&`、`||` 和 `!`；
- `cctype` 字符函数库；
- 条件运算符：`?:`；
- `switch` 语句；
- `continue` 和 `break` 语句；
- 读取数字的循环；
- 基本文件输入/输出。

## 6.1 `if` 语句

如果测试条件为 `true`， 则 `if` 语句将引导程序执行语句或语句块；如果条件是`false`，程序将跳过 这条语句或语句块。因此，`if` 语句让程序能够决定是否应执行特定的语句。

![image-20210728225254330](https://static.fungenomics.com/images/2021/07/image-20210728225254330.png)

### 6.1.1 `if else` 语句

`if` 语句让程序决定是否执行特定的语句或语句块，而`if else`语句则让程序决定执行两条语句或语句块中的哪一条，这种语句对于选择其中一 种操作很有用。

`if else` 语句的通用格式如下：

![image-20210728225544934](https://static.fungenomics.com/images/2021/07/image-20210728225544934.png)

![image-20210728225606236](https://static.fungenomics.com/images/2021/07/image-20210728225606236.png)

### 6.1.2 格式化 `if else` 语句

`if else` 中的两种操作都必须是一条语句。如果需要多条语句，需要 用大括号将它们括起来，组成一个块语句。

### 6.1.3  `if`- `else if`- `else` 结构

计算机程序也可能提供两个以上的 选择。可以将`C++`的 `if else` 语句进行扩展来满足这种需求。正如读者知 道的，`else` 之后应是一条语句，也可以是语句块。由于 `if else` 语句本身是 一条语句，所以可以放在 `else` 的后面。

## 6.2 逻辑表达式

C++ 提供了3种逻辑运算符，来组合或修改已有的表达式。这些运算符分别是逻 辑 `OR (||)`、逻辑 `AND (&&)`和逻辑 `NOT (!)`。

### 6.2.1 逻辑OR运算符：`||`

C++可以采用逻辑OR运算 符 `||`，将两个表达式组合在一起。如果原来表达式中的任何一个或 全部都为 `true`（或非零），则得到的表达式的值为 `true`；否则，表达式的值为 `false`。

C++ 规定 `||` 运算符是个顺序点（sequence point）。也是说，先修改左侧的值，再对右侧的值进行判定（C++11的说法是，运算符左边的子表达式先于右边的子表达式）。

![image-20210728230438579](https://static.fungenomics.com/images/2021/07/image-20210728230438579.png)

### 6.2.2 逻辑AND运算符：`&&`

逻辑AND运算符 `&&`，也是将两个表达式组合成一个表达式。 仅当原来的两个表达式都为 `true` 时，得到的表达式的值才为 `true`。

`&&` 运算符也是顺序点，因此将首先判定左侧， 并且在右侧被判定之前产生所有的副作用。如果左侧为 `false`，则整个逻 辑表达式必定为 `false`，在这种情况下，C++ 将不会再对右侧进行判定。

![image-20210728230605370](https://static.fungenomics.com/images/2021/07/image-20210728230605370.png)

### 6.2.3 用 `&&` 来设置取值范围

`&&` 运算符还允许建立一系列`if` `else if` `else`语句，其中每种选择都对 应于一个特定的取值范围。

### 6.2.4 逻辑NOT运算符：`!`

`!` 运算符将它后面的表达式的真值取反。也是说，如果 `expression` 为 `true`，则 `!expression` 是 `false`；如果 `expression` 为 `false`，则 `!expression`是 `true`。更准确地说，如果 `expression` 为 `true` 或非零，则 `!expression` 为 `false`。

然而，`!` 运算符对于返回 `true-false` 值或可以被解释为 `true-false` 值的函数来说很有用。例如，如果C-风格字符串 `s1` 和 `s2` 不同，则 `strcmp(s1,s2)` 将返回非零`true`值，否则返回 `0`。这意味着如果这两个字符串相同， 则 `!strcmp(s1,s2)` 为 `true`。

### 6.2.5 逻辑运算符细节

`!` 运算符的优先级高于所有的关系运算符和算术运算符。因此，要对表达式求反，必须用括号将其括起。

### 6.2.6 其他表示方式

并不是所有的键盘都提供了用作逻辑运算符的符号，因此C++标准 提供了另一种表示方式，如表6.3所示。标识符`and`、`or`和`not`都是C++保 留字，这意味着不能将它们用作变量名等。它们不是关键字，因为它们 都是已有语言特性的另一种表示方式。另外，它们并不是C语言中的保 留字，但C语言程序可以将它们用作运算符，只要在程序中包含了头文 件 `iso646.h`。C++不要求使用头文件。

![image-20210728232023659](https://static.fungenomics.com/images/2021/07/image-20210728232023659.png)

## 6.3 字符函数库 `cctype`

C++ 从 C 语言继承了一个与字符相关的、非常方便的函数软件包， 它可以简化诸如确定字符是否为大写字母、数字、标点符号等工作，这 些函数的原型是在头文件`cctype`（老式的风格中为 `ctype.h`）中定义的。 例如，如果 `ch` 是一个字母，则 `isalpha(ch)` 函数返回一个非零值，否则返回 `0`。同样，如果 `ch` 是标点符号（如逗号或句号），函数 `ispunct(ch)` 将返回 `true`。（**注意这些函数的返回类型为 `int`，而不是 `bool`， 但通常 `bool` 转换能够将它们视为`bool` 类型**）

![image-20210728232352198](https://static.fungenomics.com/images/2021/07/image-20210728232352198.png)

`isalpha()` 不仅更容易使用，而且更通用。例子中用AND/OR格式假设A-Z的字符编码是连续的，其他字符的编码不在这个范围内。这种假设对于ASCII码来说是成立的，但也并非总是如此。

具体地说：

- `isalpha()` 用来检查字符是否为字母字符；
- `isdigit()` 用来测试字符是否为数字字符（0~9），如 3；
- `isspace()` 用来测试字符是否为空白，包括换行符、空格和制表符；
- `ispunct()` 用来测试字符是否为标点符号。

![image-20210728232647223](https://static.fungenomics.com/images/2021/07/image-20210728232647223.png)

总结一下这个函数包：

![image-20210728232856482](https://static.fungenomics.com/images/2021/07/image-20210728232856482.png)

![image-20210728232930054](https://static.fungenomics.com/images/2021/07/image-20210728232930054.png)

## 6.4 `?:` 运算符

C++有一个常被用来代替 `if else` 语句的运算符，这个运算符被称为条件运算符 `?:`，它是C++中唯一一个需要3个操作数的运算符，也叫**三目运算符**。

```Cpp
expression1 ? expression2 : expression3
```
如果 `expression1` 为 `true`，则整个条件表达式的值为 `expression2` 的值； 否则，整个表达式的值为 `expression3` 的值。

![image-20210728233356197](https://static.fungenomics.com/images/2021/07/image-20210728233356197.png)

## 6.5 `switch`语句

![image-20210728234430665](https://static.fungenomics.com/images/2021/07/image-20210728234430665.png)

`switch` 语句与 Pascal 等语言中类似的语句之间存在重大的差别。 C++中的 `case` 标签只是行标签，而不是选项之间的界线。也是说，程序跳到 `switch` 中特定代码行后，将依次执行之后的所有语句，除非有明确的其他指示。程序不会在执行到下一个 `case` 处自动停止，**要让程序执行 完一组特定语句后停止，必须使用`break` 语句**。这将导致程序跳到 `switch` 后面的语句处执行。

![image-20210728234458366](https://static.fungenomics.com/images/2021/07/image-20210728234458366.png)

### 6.5.1 将枚举量用作标签

通常，`cin` 无法识别枚举类型（它不知道程序员是如 何定义它们的），因此该程序要求用户选择选项时输入一个整数。当 `switch` 语句将 `int` 值和枚举量标签进行比较时，将枚举量提升为 `int`。另 外，在 `while` 循环测试条件中，也会将枚举量提升为 `int` 类型。

### 6.5.2 `switch` 和 `if else`

`switch`语句和`if else`语句都允许程序从选项中进行选择。相比之下， `if else`更通用，例如，它可以处理取值范围。

然而，`switch`并不是为处理取值范围而设计的。`switch`语句中的每 一个`case`标签都必须是一个单独的值。另外，这个值必须是整数（包括 `char`），因此 `switch` 无法处理浮点测试。另外 `case` 标签值还必须是常量。 如果选项涉及取值范围、浮点测试或两个变量的比较，则应使用 `if else` 语句。

## 6.6 `break` 和 `continue` 语句

`break`和 `continue`语句都使程序能够跳过部分代码。可以在 `switch`语句或任何循环中使用 `break` 语句，使程序跳到 `switch` 或循环后面的语句处执行。`continue` 语句用于循环中，让程序跳过循环体中余下的代码，并开始新一轮循环。

![image-20210728235538853](https://static.fungenomics.com/images/2021/07/image-20210728235538853.png)

## 6.7 读取数字的循环

假设要编写一个将一系列数字读入到数组中的程序，并允许用户在 数组填满之前结束输入，一种方法是利用cin。看下面的代码：

```Cpp
int n;
cin >> n;
```

如果用户输入一个单词，而不是一个数字，发生这种类型不匹配的情况时，将发生4种情况：

- `n` 的值保持不变；
- 不匹配的输入将被留在输入队列中；
- `cin` 对象中的一个错误标记被设置；
- 对 `cin` 方法的调用将返回 `false`（如果被转换为 `bool` 类型）。

**方法返回 `false` 意味着可以用非数字输入来结束读取数字的循环**。当用户输入的不是数字时，该程序将不再读取输入。非数字输入设置错误标记意味着**必须重置该标记，程序才能继续读取输 入**。`clear()` 方法重置错误输入标记，同时也重置文件尾（`EOF`条件，参见第5章）。输入错误和 `EOF` 都将导致`cin`返回 `false`。

![image-20210729001427328](https://static.fungenomics.com/images/2021/07/image-20210729001427328.png)

![image-20210729001350955](https://static.fungenomics.com/images/2021/07/image-20210729001350955.png)

如果用户输入非数字输入，程序将拒绝，并要求用户继续输入数字。可以看到，可以使用 `cin` 输入表达式的值来检测输入是不是数字。 程序发现用户输入了错误内容时，应采取3个步骤：

- 重置 `cin` 以接受新的输入；
- 删除错误输入；
- 提示用户再输入。

请注意，程序必须先重置cin，然后才能删除错误输入。如下程序清单 6.14演示了如何完成这些工作。

```Cpp
#include <iostream>

const int Max = 5;
int main() {
    using namespace std;
    // get data
    int golf[Max];
    cout << "Please enter your golf scores.\n";
    cout << "You must enter " << Max << " rounds.\n";
    int i;
    for (i = 0; i < Max; i++) {
        cout << "round #" << i+1 << ": ";
        while (!(cin >> golf[i])) {
            cin.clear();     // reset input
            while (cin.get() != '\n')
                continue;    // get rid of bad input
            cout << "Please enter a number: ";
        }
    }
    
    // calculate average
    double total = 0.0;
    for (i = 0; i < Max; i++)
        total += golf[i];
        
    // report results
    cout << total / Max << " = average score "
         << Max << " rounds\n";
    // cin.get();
    // cin.get();
    return 0;
}
```

![image-20210729165001482](https://static.fungenomics.com/images/2021/07/image-20210729165001482.png)

> 如果用户输入 88，则 `cin` 表达式将为 `true`，因此将一个值放到数组中；而表达式 `!(cin >> golf [i])` 为 `false`，因此结束内部循环。然而，如果用户输入 `must i?`，则 `cin` 表达式将为 `false`，因此不会将任何值放到数组 中；而表达式 `!(cin >> golf [i])` 将为 `true`，因此进入内部的 `while` 循环。该循环的第一条语句使用 `clear()` 方法重置输入，如果省略这条语句，程序将拒绝继续读取输入。接下来，程序在 `while` 循环中使用 `cin.get()` 来读取 行尾之前的所有输入，从而删除这一行中的错误输入。另一种方法是读取到下一个空白字符，这样将每次删除一个单词，而不是一次删除整 行。最后，程序告诉用户，应输入一个数字。

## 6.8 简单文件输入/输出

### 6.8.1 文本I/O和文本文件

### 6.8.2 写入到文本文件中

文件输出：

- 必须包含头文件 `fstream`；
- 头文件 `fstream` 定义了一个用于处理输出的 `ofstream` 类；
- 需要声明一个或多个 `ofstream` 变量（对象），并以自己喜欢的方式 对其进行命名，条件是遵守常用的命名规则；
- 必须指明名称空间 `std`。例如，为引用元素 `ofstream`，必须使用编译指令`using` 或前缀 `std::`；
- 需要将 `ofstream` 对象与文件关联起来。为此，方法之一是使用 `open()` 方法；
- 使用完文件后，应使用方法 `close()` 将其关闭；
- 可结合使用 `ofstream` 对象和运算符 `<<` 来输出各种类型的数据。

虽然头文件 `iostream` 提供了一个预先定义好的名为 `cout` 的 `ostream` 对象，但您必须声明自己的 `ofstream` 对象，为其命名，并将其同文件关联起来。

![image-20210729232741786](https://static.fungenomics.com/images/2021/07/image-20210729232741786.png)

注意，方法`open()` 只接受C-风格字符串作为参数，这可以是一个 字面字符串，也可以是存储在数组中的字符串。

重要的是，声明一个`ofstream`对象并将其同文件关联起来后，便可以像使用cout那样使用它。所有可用于cout的操作和方法（如<<、endl 和setf( )）都可用于ofstream对象（如前述示例中的outFile和fout）。

总之，使用文件输出的主要步骤如下：

- 包含头文件 `fstream`；
- 创建一个 `ofstream` 对象；
- 将该 `ofstream` 对象同一个文件关联起来；
- 就像使用 `cout` 那样使用该 `ofstream` 对象;
- 调用 `close()` 成员函数，关闭文件。

> 默认情况下，`open()` 的将首先截断该文件，即将其长度截短到零——丢弃原有的内容，然后将新的输出加入到该文件中。

### 6.8.3 读取文本文件

接下来介绍文本文件输入，它是基于控制台输入的。控制台输入涉 及多个方面，下面首先总结这些方面：

- 必须包含头文件 `fstream`；
- 头文件 `fstream` 定义了一个用于处理输入的 `ifstream` 类；
- 需要声明一个或多个 `ifstream` 变量（对象），并以自己喜欢的方式对其进行命名，条件是遵守常用的命名规则；
- 必须指明名称空间 `std`；例如，为引用元素 `ifstream`，必须使用编译指令`using`或前缀`std::`；
- 需要将 `ifstream` 对象与文件关联起来。为此，方法之一是使用 `open()` 方法；
- 使用完文件后，应使用 `close()` 方法将其关闭；
- 可结合使用 `ifstream` 对象和运算符 `>>` 来读取各种类型的数据；
- 可以使用 `ifstream` 对象和 `get()` 方法来读取一个字符，使用 `ifstream` 对象和 `getline()` 来读取一行字符；
- 可以结合使用 `ifstream` 和 `eof()`、`fail()` 等方法来判断输入是否成功；
- `ifstream` 对象本身被用作测试条件时，如果最后一个读取操作成 功，它将被转换为布尔值 `true`，否则被转换为 `false`。

如果试图打开一个不存在的文件用于输入，情况将如何呢？这种错误将导致后面使用`ifstream` 对象进行输入时失败。检查文件是否被成功打开的首选方法是使用`is_open()`，为此，可以使用类似于下面的代码：

```Cpp
inFile.open("b.txt");
if (!inFile.is_open()) {
    exit(EXIT_FEAILURE);
}
```

如果文件被成功地打开，方法 `is_open()` 将返回 `true`；因此如果文件没有被打开，表达式 `!inFile.is_open()` 将为 `true`。函数 `exit()` 的原型是在头文件 `cstdlib` 中定义的，在该头文件中，还定义了一个用于同操作系统通信的参数值 `EXIT_FAILURE`。函数 `exit()` 终止程序。

> 方法 `is_open()` 是C++中相对较新的内容。如果读者的编译器不支持它，可使用较老的方法 `good()` 来代替。

程序例子：

![image-20210730001839791](https://static.fungenomics.com/images/2021/07/image-20210730001839791.png)![image-20210730001922821](https://static.fungenomics.com/images/2021/07/image-20210730001922821.png)

假设该文件名为scores.txt，包含的内容如下：

```bash
18 19 18.5 13.5
16 19.5 18.5
17.5
```

> 检查文件是否被成功打开至关重要。

读取文件时，有 几点需要检查。首先，程序读取文件时不应超过 EOF。如果最后一次读取数据时遇到 `EOF`，方法 `eof()` 将返回 `true`。其次，程序可能遇到类型不 匹配的情况。例如，程序清单6.16期望文件中只包含数字。如果最后一次读取操作中发生了类型不匹配的情况，方法 `fail()` 将返回 `true`（如果遇到了 `EOF`，该方法也将返回 `true`）。最后，可能出现意外的问题，如文 件受损或硬件故障。如果最后一次读取文件时发生了这样的问题，方法 `bad()` 将返回 `true`。不要分别检查这些情况，一种更简单的方法是使用 `good()` 方法，该方法在没有发生任何错误时返回 `true`：

```Cpp
while (inFile.good()) {
    ......
}
```

方法 `good()` 指出最后一次读取输入的操作是否成功，这一点至关重要。这意味着应该在执行读取输入的操作后，立刻应用这种测试。为此，一种标准方法是，在循环之前（首次执行循环测试前）放置一条输 入语句，并在循环的末尾（下次执行循环测试之前）放置另一条输入语句：

```Cpp
// standard file-reading loop design
inFile >> value;         // get first value
while (inFile.good()) {  // while uput good and not at EOF
    //loop body goes here
    inFile >> value;     // get next value
}
```

鉴于以下事实，可以对上述代码进行精简：表达式 `inFile >> value` 的结果为`inFile`，而在需要一个 `bool` 值的情况下，`inFile` 的结果为 `inFile.good()`，即 `true` 或 `false`。

因此，可以将两条输入语句用一条用作循环测试的输入语句代替。 也就是说，可以将上述循环结构替换为如下循环结构：

```Cpp
// omit pre-loop input
while (inFile >> value) {  // read and test for success
    // loop body goes here
    // omit end-of-loop input
}
```

![image-20210730002759125](https://static.fungenomics.com/images/2021/07/image-20210730002759125.png)

这些代码紧跟在循环的后面，用于判断循环为何终止。由于 `eof()` 只能判断是否到达 `EOF`，而 `fail()` 可用于检查 `EOF` 和类型不匹配，因此上述 代码首先判断是否到达 `EOF`。这样，如果执行到了 `else if` 测试，便可排除 `EOF`，因此，如果 `fail()` 返回 `true`，便可断定导致循环终止的原因是类型不匹配。

这种设计仍然遵循了在测试之前进行读取的规则，因为要计算表达式 `inFile >> value` 的值，程序必须首先试图将一个数字读取到 `value` 中。

以上仅是对文件 I/O 的初步介绍。


## 6.9 总结

C++提供了 `if` 语句、`if-else` 语句和 `switch` 语句来管理选项。
C++还提供了帮助决策的运算符。通过使用逻辑运算符（`&&`、`||` 和 `!`），可以组合或修改关系表达式，创建更细致的测试。条件运算符 `(?:)` 提供了一种选择两个值之一 的简洁方式。

`cctype` 字符函数库提供了一组方便的、功能强大的工具，可用于分析字符输入。

![image-20210728232856482](https://static.fungenomics.com/images/2021/07/image-20210728232856482.png)
![image-20210728232930054](https://static.fungenomics.com/images/2021/07/image-20210728232930054.png)

文件 I/O 与控制台 I/O 极其相似。声明 ifstream 和 ofstream 对象，并将它们同文件关联起来后，便可以像使用 cin 和 cout 那样使用这些对象。
