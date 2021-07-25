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

> 程序应接受的名字包含多个单词。另外，程序将向下调整成绩。假设用户请求A、B或C，返回 B、C 或 D。


**解：**

```Cpp
#include <iostream>

int main() {

    using namespace std;

    char first_name[40];
    char last_name[40];
    char grade_letter;
    int age;

    cout << "What is your first name: ";
    cin.getline(first_name, 40);

    cout << "What is your last name: ";
    cin.getline(last_name, 40);

    cout << "What letter grade do you deserve: ";
    cin >> grade_letter;

    cout << "What is your age: ";
    cin >> age;

    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << char(grade_letter+1) << "\n";
    cout << "Age: " << age << endl;

    return 0;
}

```


## 4.2

**题：** 修改程序清单4.4，使用 C++ `string` 类而不是 `char` 数组。

**解：**

```Cpp
#include <iostream>
#include <string>

int main() {
    using namespace std;

    string name;
    string dessert;

    cout << "Enter your name: \n";
    getline(cin, name);

    cout << "Enter your favorite dessert:\n";
    getline(cin, dessert);

    cout << "I have delicious " << dessert;
    cout << " for you,  " << name << ".\n";

    return 0;
}

```

## 4.3

**题：** 编写一个程序，它要求用户首先输入其名，然后输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用char数组和头文件cstring中的函数。下面是该程序运行时的 情形：

```bash
Enter your first name: Flip
Enter your last name: Fleming
Here's the information in a single string: Fleming, Flip

```

**解：**

```Cpp
#include <iostream>
#include <cstring>

int main() {

    using namespace std;
    char first_name[20], last_name[20];
    char final_name[50];

    cout << "Enter your first name: ";
    cin.getline(first_name, 20);

    cout << "Enther your last name: ";
    cin.getline(last_name, 20);

    strcpy(final_name, last_name);
    strcat(final_name, ", ");
    strcat(final_name, first_name);

    cout << "Here's the information in a single string: " << final_name << endl;

    return 0;
}

```


## 4.4

**题：** 编写一个程序，它要求用户首先输入其名，再输入其姓；然后程序使用一个逗号和空格将姓和名组合起来，并存储和显示组合结果。请使用string对象和头文件string中的函数。下面是该程序运行时的情形：

```bash
Enter your first name: Flip
Enter your last name: Fleming
Here's the information in a single string: Fleming, Flip

```

**解：**


```Cpp
#include <iostream>
#include <string>

int main() {

    using namespace std;
    string first_name, last_name;
    string final_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    cout << "Enther your last name: ";
    getline(cin, last_name);

    final_name = last_name + ", " + first_name;

    cout << "Here's the information in a single string: " << final_name << endl;

    return 0;
}

```


## 4.5

**题：** 结构体 `CandyBar` 包含3个成员。第一个成员存储了糖块的品牌；第二个成员存储糖块的重量（可以有小数）；第三个成员存储了糖块的卡路里含量（整数）。编写一个程序，声明这个结构体，创建一个名为 `snack` 的 `CandyBar` 变量，并将其成员分别初始化为 "Mocha Munch"、2.3 和 350。初始化应在声明 `snack` 时进行。最后，程序显示 `snack` 变量的内容。


**解：**

```Cpp
#include <iostream>
#include <string>

struct CandyBar
{
    std::string name;
    double weight;
    int calories;
};


int main() {
    using namespace std;

    CandyBar snack = {"Mocha Munch", 2.3, 350};  // 初始化结构体

    cout << "The name of the CandyBar: " << snack.name << "\n";
    cout << "The weight of the candy: " << snack.weight << "\n";
    cout << "The calories information: " << snack.calories << endl;

    return 0;
}

```


## 4.6

**题：** 结构体 `CandyBar` 包含3个成员，如 `编程练习5`所示。请编写一个程序，创建一个包含 3 个元素的 `CandyBar` 数组，并将它们初始化为所选择的值，然后显示每个结构体的内容。


**解：**

```Cpp
#include <iostream>
#include <string>

struct CandyBar
{
    std::string name;
    double weight;
    int calories;
};


int main() {

    using namespace std;

    CandyBar candbar[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
    };

    cout << "The name of the CandyBar: " << candbar[0].name << "\n"
         << "The weight of the candy: " << candbar[0].weight << "\n"
         << "The calories information: " << candbar[0].calories << "\n\n";

    cout << "The name of the CandyBar: " << candbar[1].name << "\n"
         << "The weight of the candy: " << candbar[1].weight << "\n"
         << "The calories information: " << candbar[1].calories << "\n\n";

    cout << "The name of the CandyBar: " << candbar[2].name << "\n"
         << "The weight of the candy: " << candbar[2].weight << "\n"
         << "The calories information: " << candbar[2].calories << endl;

    return 0;
}

```

## 4.7

**题：** William Wingate从事比萨饼分析服务。对于每个披萨饼，他都需要记录下列信息：

- 披萨饼公司的名称，可以有多个单词组成；
- 披萨饼的直径；
- 披萨饼的重量。

请设计一个能够存储这些信息的结构体，并编写一个使用这种结构体变量的程序。程序将请求用户输入上述信息，然后显示这些信息。请使用 cin（或其它的方法）和cout。

**解：**

```Cpp

#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    double diameter;
    double weight;
    
};

int main() {
    using namespace std;

    Pizza pizza;
    cout << "Enter the pizza company: ";
    getline(cin, pizza.company);

    cout << "Enter the diameter of pizza: ";
    cin >> pizza.diameter;

    cout << "Enter the weight of pizza: ";
    cin >> pizza.weight;

    cout << "\nHere is the pizza information: \n"
         << "Company: " << pizza.company << "\n"
         << "Diameter: " << pizza.diameter << "\n"
         << "Weight: " << pizza.weight << endl;

    return 0;
}

```

## 4.8

**题：** 完成编程练习7，但使用 `new` 来为结构体分配内存，而不是声明一个结构体变量。另外，让程序在请求输入比萨饼公司名称之前输入比萨饼的直径。


**解：**

```Cpp
#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    double diameter;
    double weight;
};

int main() {
    using namespace std;

    Pizza *pizza = new Pizza;
    
    cout << "Enter the diameter of pizza: ";
    cin >> pizza->diameter;

    cout << "Enter the weight of pizza: ";
    cin >> pizza->weight;

    // 注意上语句输入完 weight 后，回车键留在输入流中，以下的 getline 
    // 碰到输入流中的回车就以为结束了，所以如果没有这个 cin.get() 先读
    // 取回车，那么用户永远获得 company 的值。
    cin.get(); 

    cout << "Enter the pizza company: ";
    getline(cin, pizza->company);

    cout << "\nHere is the pizza information: \n"
         << "Company: " << pizza->company << "\n"
         << "Diameter: " << pizza->diameter << "\n"
         << "Weight: " << pizza->weight << endl;

    delete pizza;

    return 0;
}

```


## 4.9

**题：** 完成编程练习6，但使用 `new` 来动态分配数组，而不是声明一个包含 3 个元素的 `CandyBar` 数组。


**解：**

```Cpp
#include <iostream>
#include <string>

struct CandyBar
{
    std::string name;
    double weight;
    int calories;
};


int main() {

    using namespace std;

    CandyBar *p_candybar = new CandyBar [3] {
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
    };

    // 输出第一个结构体元素，按照数组的方式输出
    cout << "The name of the CandyBar: " << p_candybar[0].name << "\n"
         << "The weight of the candy: " << p_candybar[0].weight << "\n"
         << "The calories information: " << p_candybar[0].calories << "\n\n";

    // 输出第二个结构体元素，可以按照指针的逻辑输出
    cout << "The name of the CandyBar: " << (p_candybar+1)->name << "\n"
         << "The weight of the candy: " << (p_candybar+1)->weight << "\n"
         << "The calories information: " << (p_candybar+1)->calories << "\n\n";

    // 输出第三个结构体元素，又是数据的方式
    cout << "The name of the CandyBar: " << p_candybar[2].name << "\n"
         << "The weight of the candy: " << p_candybar[2].weight << "\n"
         << "The calories information: " << p_candybar[2].calories << endl;

    delete [] p_candybar;

    return 0;
}

```

## 4.10

**题：** 编写一个程序，让用户输入三次 40 码跑的成绩（如果您愿意，也可让用户输入40米跑的成绩），并显示次数和平均成绩。请使用一个 `array`对象来存储数据（如果编译器不支持 `array` 类，请使用数组）。

**解：**

```Cpp
#include <iostream>
#include <array>

int main() {

    using namespace std;

    array<double, 3> result;

    cout << "Enter threed result of the 40 meters runing time: \n";
    cin >> result[0];
    cin >> result[1];
    cin >> result[2];

    double ave_result = (result[0] + result[1] + result[2]) / 3;
    cout << "The all three time results are: " << result[0] << ", "
         << result[1] << ", " << result[2] << endl;

    cout << "The average result: " << ave_result << endl;

    return 0;
}

```




