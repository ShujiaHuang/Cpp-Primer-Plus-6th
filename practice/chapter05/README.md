# 第五章 《循环和关系表达式》 编程练习题之我解

## 5.1

**题：** 编写一个要求用户输入两个整数的程序。该程序将计算并输出这两个整数之间（包括这两个整数）所有整数的和。这里假设先输入较小的整数。例如，用户输入的是2和9，则程序将指出2～9之间所有整数的和为44。


**解：**

```Cpp
#include <iostream>

int main() {
    using namespace std;
    int number1, number2;

    cout << "Enter the first number: ";
    cin >> number1;

    cout << "Enter the second number: ";
    cin >> number2;

    if (number1 > number2) {
        int tmp;
        tmp = number1;
        number1 = number2;
        number2 = tmp;
    }

    int s = 0;
    for (int num=number1; num < number2+1; ++num) {
        s += num;
    }

    cout << "Sum the number from " << number1 << " to " << number2 
         << ", sum = " << s << endl;

    return 0;
}

```


## 5.2

**题：** 使用 `array` 对象（而不是数组）和 `long double`（而不是 `long long`）重新编写程序清单5.4，并计算 100! 的值。

**解：**

```Cpp
#include <iostream>
#include <array>


const int ar_size = 100;
int main() {
    using namespace std;

    array<long double, ar_size> factorials;

    factorials[0] = factorials[1] = 1;
    for (int i = 2; i < ar_size+1; ++i) {

        factorials[i] = i * factorials[i-1];
    }

    for (int i = 0; i < ar_size + 1; ++i) {

        cout << i << "! = " << factorials[i] << "\n";
    }
    cout << endl;

    return 0;
}

```


## 5.3

**题：** 编写一个要求用户输入数字的程序。每次输入后，程序都将报告到目前为止，所有输入的累计和。当用户输入 0 时，程序结束。


**解：**

```Cpp
#include <iostream>


int main() {
    using namespace std;

    double s = 0;
    double ch;

    while (1) {

        cout << "Enter a number (int/double) (0 to exit): ";
        cin >> ch;

        if (ch == 0) {
            break;
        }

        s += ch;
        cout << "Until now, the sum of the number you inputed is: " 
             << s << endl;
    }

    return 0;
}

```


## 5.4

**题：** Daphne以10%的单利投资了100美元。也就是说，每一年的利润都是投资额的10%，即每年10美元。而Cleo以5%的复利投资了100美元。也就是说，利息是当前存款（包括获得的利息）的5%，Cleo在第一年投资100美元的盈利是5%—得到了105美元。下一年的盈利是105美元的5%—即5.25美元，依此类推。请编写一个程序，计算多少年后，Cleo的投资价值才能超过Daphne的投资价值，并显示此时两个人的投资价值。


**解：**

```Cpp
#include <iostream>

int main() {
    using namespace std;

    double daphne_account = 100;
    double cleo_account = 100;

    int year = 0;
    while (cleo_account <= daphne_account) {
        ++year;

        daphne_account += 10;
        cleo_account += cleo_account * 0.05;
    }

    cout << "After " << year << " Years. " 
         << "Cleo's account is " << cleo_account
         << " while more than the one of Daphne which is " 
         << daphne_account << "." << endl;

    return 0;
}

```


## 5.5

**题：** 假设要销售《C++ For Fools》一书。请编写一个程序，输入全年中每个月的销售量（图书数量，而不是销售额）。程序通过循环，使用初始化为月份字符串的 `char *` 数组（或 `string` 对象数组）逐月进行提示，并将输入的数据储存在一个int数组中。然后，程序计算数组中各元素的总数，并报告这一年的销售情况。


**解：**

```Cpp

#include <iostream>
#include <string>

int main() {
    using namespace std;

    string months[12] = {"Jan", "Feb", "Mar", "Apr", 
                         "May", "Jun", "Jul", "Aug", 
                         "Sep", "Oct", "Nov", "Dec"};
    int sell[12];
    int total_sales = 0;

    cout << "Enter the sales of book <<C++ for Fools>> each month." << endl;
    for (int i=0; i < 12; ++i) {

        cout << months[i] << ":";
        cin >> sell[i];

        total_sales += sell[i];
    }

    cout << "\nThe total sales is " << total_sales << endl;
    for (int i=0; i < 12; ++i) {

        cout << months[i] << ": " << sell[i] << endl;
    }


    return 0;
}
```

## 5.6

**题：** 完成编程练习5，但这一次使用一个二维数组来存储输入——3年中每个月的销售量。程序将报告每年销售量以及三年的总销售量。


**解：**

```Cpp
#include <iostream>
#include <string>


int main() {
    using namespace std;

    string months[12] = {"Jan", "Feb", "Mar", "Apr", 
                         "May", "Jun", "Jul", "Aug", 
                         "Sep", "Oct", "Nov", "Dec"};
    int sells[3][12];
    int total_sales[3] = {0, 0, 0};

    for (int i=0; i<3; ++i) {

        cout << "Enter " << i+1 << " year(s) sales of book <<C++ for Fools>> each month." << endl;
        for (int j=0; j<12; ++j) {
            cout << months[j] << ": ";
            cin >> sells[i][j];

            total_sales[i] += sells[i][j];

        }
    }

    for (int i=0; i<3; ++i) {
        cout << i+1 << " year(s) total sales is " 
             << total_sales[i] << endl;
    }

    cout << "There years total sales is " 
         << total_sales[0] + total_sales[1] + total_sales[2] << endl;

    return 0;
}

```


## 5.7

**题：** 设计一个名为 `car` 的结构体，用它存储下述有关汽车的信息：生产商（存储在字符数组或 `string` 对象中的字符串）、生产年份（整数）。编写一个程序，向用户询问有多少辆汽车。随后，程序使用new来创建一个由相应数量的 `car` 结构体组成的动态数组。接下来，程序提示用户输入每辆车的生产商（可能由多个单词组成）和年份信息。请注意，这需要特别小心，因为它将交替读取数值和字符串（参见第4章）。最后，程序将显示每个结构的内容。该程序的运行情况如下:

How many cars do you wish to catalog? 2
Car #1: 
Please enter the maker: Hudson Hornet
Please enter the year made: 1952
Car #2:
Please enter the maker: Kaiser
Please enter the year made: 1951
Here is your collection:
1952 Hudson Hornet
1951 Kaiser


**解：**

```Cpp
#include <iostream>
#include <string>


int main() {
    using namespace std;

    struct Car {
        string company;
        int year;  
    };

    int car_num = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> car_num;
    cin.get()  // 读取输入流末尾的回车

    Car *cars = new Car[car_num];
    for (int i=0; i < car_num; ++i) {
        cout << "Please enter the maker: ";
        cin >> (cars+i)->company;

        cout << "Please enter the year made: ";
        cin >> (cars+i)->year;
    }

    cout << "\nHere is your collection: \n";
    for (int i=0; i < car_num; ++i) {
        cout << cars[i].year << " " << cars[i].company << endl;
    }

    delete [] cars;
    return 0;
}
```


## 5.8

**题：** 编写一个程序，它使用一个 `char`数组和循环，每次读取一个单词，直到用户输入 `done` 为止。随后，该程序指出用户输入了多少个单词（不包括done在内）。下面是该程序的运行情况：

Enter words (type 'done' to stop):
anteater birthday category dumpster
envy finagle genometry done for sure

You entered a total of 7 words.

> 您应在程序中包含头文件 `cstring`，并使用函数 `strcmp()` 来进行比较测试。


**解：**

```Cpp
#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    int word_count = 0;
    char ch[80];
    cout << "Enter a word (type 'done' to stop the program.): \n";
    do {
        cin >> ch;

        if (strcmp(ch, "done") != 0) {
            word_count++;
        }

    } while (strcmp(ch, "done") != 0);

    cout << "\nYou entered a total of " << word_count << " words." << endl;

    return 0;
}

```



## 5.9

**题：** 编写一个满足前一个练习中描述的程序，但使用 `string` 对象而不是字符数组。请在程序中包含头文件 `string`，并使用关系运算符来进行 比较测试。


**解：**

```Cpp
#include <iostream>
#include <string>

int main() {
    using namespace std;

    int word_count = 0;
    string ch;
    cout << "Enter a word (type 'done' to stop the program.): \n";
    do {
        cin >> ch;

        if (ch != "done") {
            word_count++;
        }

    } while (ch != "done");

    cout << "\nYou entered a total of " << word_count << " words." << endl;

    return 0;
}

```


## 5.10

**题：** 编写一个使用嵌套循环的程序，要求用户输入一个值，指出要显示多少行。然后，程序将显示相应行数的星号，其中第一行包括一个星号，第二行包括两个星号，依此类推。每一行包含的字符数等于用户指定的行数，在星号不够的情况下，在星号前面加上句点。该程序的运 行情况如下：

Enter number of rows: 5
Output: 
....*
...**
..***
.****
*****


**解:**

```Cpp
#include <iostream>

int main() {

    using namespace std;
    int line_num = 0;

    cout << "Enter the number of rows: ";
    cin >> line_num;

    cout << "Output:" << endl;
    for (int i = line_num; i > 0; --i) {

        for (int j = i-1; j > 0; --j) {
            cout << ".";
        }
        for (int j = line_num - (i-1); j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}

```



