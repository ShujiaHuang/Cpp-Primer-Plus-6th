# 第六章 《分支语句和逻辑运算符》 编程练习题之我解

## 6.1

**题：** 编写一个程序，读取键盘输入，直到遇到 `@`符号为止，并回显输入（数字除外），同时将大写字符转换为小写，将小写字符转换为大 写（别忘了`cctype`函数系列）。


**解：**

```Cpp
#include <iostream>
#include <cctype>


int main() {
    using namespace std;
    char ch;

    cout << "Enter any charater: ";
    while ((ch=cin.get()) != '@') {

        if (isdigit(ch)) {
            continue;
        } else if (islower(ch)) {
            ch = toupper(ch);
        } else if (isupper(ch)) {
            ch = tolower(ch);
        }

        cout << ch;

    }

    cout << "** done **" << endl;

    return 0;
}
```


## 6.2

**题：** 编写一个程序，最多将10个 `donation` 值读入到一个 `double` 数组中（如果您愿意，也可使用模板类 `array` ）。程序遇到非数字输入时将结束输入，并报告这些数字的平均值以及数组中有多少个数字大于平均值。


**解：**

```Cpp
#include <iostream>
#include <array>


int main() {
    using namespace std;
    
    const unsigned int size = 10;
    array<double, size> donation;

    double sum_value = 0;
    unsigned int large_avg = 0, n = 0;

    cout << "Enter 10 double value or type non-digital value to exit: ";
    while ((n < size) && (cin >> donation[n])) {
        
        sum_value += donation[n];
        ++n;
    }

    double avg = sum_value / n;
    for (int i=0; i < n; i++) {

        if (donation[i]>avg)
            ++large_avg;
    }

    cout << "The average value is: " << avg
         << ", there are " << large_avg
         << " larger than average value." << endl;

    return 0;
}

```


## 6.3

**题：** 编写一个菜单驱动程序的雏形。该程序显示一个提供4个选项的菜单——每个选项用一个字母标记。如果用户使用有效选项之外的字母进行响应，程序将提示用户输入一个有效的字母，直到用户这样做为止。然后，该程序使用一条 `switch` 语句，根据用户的选择执行一个简单操作。该程序的运行情况如下：

```bash
Please enter one of the following choices:

c) carnivore    p) pianist
t) tree         g) game
f

Please enter a c, p, t, or g: q
A maple is a tree.

```

**解：**

```Cpp
#include <iostream>

int main() {

    using namespace std;
    cout << "Please enter one of the following choice: \n";
    cout << "c) carnivore\tp) pianist.\n"
         << "t) tree\tg) game" << endl;

    bool exit = false;
    char c;
    while (!exit && (cin >> c)) {

        switch (c) {
            case 'c': 
                cout << "Tiger is a carnivore." << endl;
                exit = true;
                break;
            case 'p':
                cout << "Mozart is a great pianst." << endl;
                exit = true;
                break;
            case 't':
                cout << "A maple is a tree." << endl;
                exit = true;
                break;
            case 'g':
                cout << "Supper Mario is a great game." << endl;
                exit = true;
                break;

            default:
                cout << "Please enter c, p, t, or g: q" << endl;
                break;
        }
    }
    return 0;
}

```


## 6.4

**题：** 加入 `Benevolent Order of Programmer` 后，在BOP大会上，人们便可以通过加入者的真实姓名、头衔或秘密BOP姓名来了解他（她）。请编写一个程序，可以使用真实姓名、头衔、秘密姓名或成员偏好来列出成员。编写该程序时，请使用下面的结构：

```Cpp
// Benevolent order of programmers strcture

struct bop {
    char fullname[strsize]; // real name
    char title[strsize];    // job title
    char bopname[strsize];  // secret BOP name
    int preference;         // 0 = fullname, 1 = title, 2 = bopname
};

```

该程序创建一个有上述结构体组成的小型数组，并将其初始化为适当的值。另外，该程序使用一个循环，让用户在下面的选项中进行选择：

```bash
a. display by name     b. display by title
c. display by bopname  d. display by preference
q. quit
```

注意，`display by preference` 并不意味着显示成员的偏好，而是意味着根据成员的偏好来列出成员。例如，如果偏好号为 1，则选择 d 将显示成员的头衔。该程序的运行情况如下：

```bash
Benevolent order of Programmers report.

a. display by name     b. display by title
c. display by bopname  d. display by preference
q. quit

Enter your choices: a
Wimp Macho
Raki Rhodes
Celia Laiter
Hoppy Hipman
Pat Hand

Next choice： d   
Wimp Macho
Junior Programmer
MIPS
Analyst Trainee
LOOPY

Next choice: q
Bye!

```


**解：**


```Cpp
#include <iostream>


int main() {

    using namespace std;

    const int strsize = 80;
    struct Bop {
        char fullname[strsize]; // real name
        char title[strsize];    // job title
        char bopname[strsize];  // secret BOP name
        int preference;         // 0 = fullname, 1 = title, 2 = bopname
    };

    const int size = 5;
    const Bop bops[size] = {
        {"Wimp Macho", "bbb", "c", 0},
        {"Raki Rhodes", "2XXXX", "3XXXXX", 1},
        {"Celia Laiter", "2AAAA", "3AAAAA", 2},
        {"Hoppy Hipman", "2BBBB", "3BBBBB", 0},
        {"Pat Hand", "4CCCC", "3CCCCC", 1}
    };

    cout << "Benevolent order of Programmers report.\n";
    cout << "a. display by name     b. display by title\n"
         << "c. display by bopname  d. display by preference\n"
         << "q. quit" << endl;

    char ch;
    while (cin >> ch) {

        if (ch == 'q') { 
            break; 
        }

        for (int i=0; i < size; ++i) {

            switch (ch) {
                case 'a':
                    cout << bops[i].fullname << "\n";
                    break;
                case 'b':
                    cout << bops[i].title << "\n";
                    break;
                case 'c':
                    cout << bops[i].bopname << "\n";
                    break;
                case 'd':
                    cout << bops[i].preference << "\n";
                    break;

                default:
                    break;
            }
        }

        cout << "Next choice: ";
    }
    cout << "** Done **" << endl;
    return 0;
}

```


## 6.5

**题：** 在 `Neutronia` 王国，货币单位是 `tvarp`，收入所得税的计算方式如下：

- 5000 tvarps：不收税;
- 5001～15000 tvarps：10%;
- 15001～35000 tvarps：15%;
- 35000 tvarps以上：20%;

例如，收入为 `38000 tvarps` 时，所得税为 `5000 * 0.00 + 10000 * 0.10 + 20000 * 0.15 + 3000 * 0.20`，
即 `4600 tvarps`。请编写一个程序，使用循环来 要求用户输入收入，并报告所得税。当用户输入负数或非数字时，循环将结束。


**解：**

```Cpp
#include <iostream>

int main() {
    using namespace std;
    const double tax_rate1 = 0.1;
    const double tax_rate2 = 0.15;
    const double tax_rate3 = 0.20;

    double income = 0.0, tax = 0.0;
    cout << "Please enter your income: ";
    while ((cin >> income) && (income > 0)) {

        if (income <= 5000) {
            tax = 0.0;
        } else if (income <= 15000 ) {

            tax = (income - 5000) * tax_rate1;
        } else if (income <= 35000) {

            tax = (15000 - 5000) * tax_rate1 + (income - 15000) * tax_rate2;
        } else {
            tax = (15000 - 5000) * tax_rate1 + (35000 - 15000) * tax_rate2 + (income - 35000) * tax_rate3;
        }

        cout << "Income = " << income << ", tax = " << tax << endl;
        cout << "Please enter your income again or enter a negative value to quit: ";
    }

    return 0;
}

```


## 6.6

**题：** 编写一个程序，记录捐助给 “维护合法权利团体” 的资金。该程序要求用户输入捐献者数目，然后要求用户输入每一个捐献者的姓名和款项。这些信息被储存在一个动态分配的结构体数组中。每个结构体有两个成员：用来储存姓名的字符数组（或 `string`对象）和用来存储款项的 `double`成员。读取所有的数据后，程序将显示所有捐款超过 10000 的捐款者的姓名及其捐款数额。

该列表前应包含一个标题，指出下面的捐款者是重要捐款人 Grand Patrons。然后，程序将列出其他的捐款者，该列表要以 `Patrons` 开头。如果某种类别没有捐款者，则程序将打印单词 `none`。该程序只显示这两种类别，而不进行排序。


**解：**

```Cpp
#include <iostream>
#include <string>


int main() {

    using namespace std;

    const int Grand_Amount = 10000; 

    struct Patron {
        string name;
        double amount;
    };

    int contribute_num = 0;
    cout << "Enter the number of contributor: ";
    cin >> contribute_num;
    cin.get();  // 读取输入流中的回车符

    Patron *p_contribution = new Patron [contribute_num];
    for (int i = 0; i < contribute_num; ++i) {
        cout << "Enter the name of " << i + 1 << " contributor: ";
        getline(cin, p_contribution[i].name);

        cout << "Enter the amount of donation: ";
        cin >> p_contribution[i].amount;
        cin.get();  // 读取输入流中的回车符
    }

    unsigned int grand_amount_n = 0;
    cout << "\nGrand patron: " << endl;
    for (int i = 0; i < contribute_num; ++i) {

        if (p_contribution[i].amount > Grand_Amount) {
            cout << "Contributor name: " << p_contribution[i].name << "\n"
                 << "Contributor amount: " << p_contribution[i].amount << endl;
            ++grand_amount_n;
        }
    }

    if (grand_amount_n == 0) {
        cout << "None" << endl;
    }

    bool is_empty = true;
    cout << "\nPatrons: " << endl;
    for (int i=0; i < contribute_num; ++i) {
        cout << "Contributor name: " << p_contribution[i].name << "\n"
             << "Contributor amount: " << p_contribution[i].amount << endl;

        is_empty = false;
    }

    if (is_empty) {
        cout << "** None **" << endl;
    }

    return 0;
}

```


## 6.7

**题：** 编写一个程序，它每次读取一个单词，直到用户输入 `q`。然后，该程序指出有多少个单词以元音打头，有多少个单词以辅音打头，还有多少个单词不属于这两类。为此，方法之一是，使用 `isalpha()` 来区分以字母和其他字符打头的单词，然后对于通过了 `isalpha()` 测试的单词，使用 `if` 或 `switch` 语句来确定哪些以元音打头。

该程序的运行情况如下：


```bash
Enter words (q to quit):
The 12 awesome oxen ambled
quietly across 15 meters of lawn. q

5 words beginning with vowels
4 words beginning with consonants
2 others

```

**解：**

```Cpp
#include <iostream>
#include <cctype>
#include <string>


int main() {

    using namespace std;

    unsigned int vowels = 0;
    unsigned int consonants = 0;
    unsigned int other = 0;
    string input;

    cout << "Enter words (q to quit): " << endl;
    while (cin >> input) {
        if (input == "q")
            break;

        if (isalpha(input[0])) {
            switch(toupper(input[0])) {

                case 'A':;
                case 'E':;
                case 'I':;
                case 'O':;
                case 'U':
                    ++vowels;
                    break;

                default:
                    ++consonants;
                    break;
            }
        } else {
            ++other;
        }
    }

    cout << vowels << " words beginning with vowels.\n"
         << consonants << " words beginning with consonants.\n"
         << other << " words beginning with other letter." << endl;

    return 0;
}

```


## 6.8

**题：** 编写一个程序，它打开一个文件文件，逐个字符地读取该文件，直到到达文件末尾，然后指出该文件中包含多少个字符。


**解：**

```Cpp
#include <iostream>
#include <fstream>
#include <string>


int main() {
    using namespace std;

    string fn;
    ifstream in_file_handle;

    unsigned int n = 0;
    char ch;

    cout << "Enter a file name: ";
    getline(cin, fn);

    in_file_handle.open(fn.c_str());
    while ((ch = in_file_handle.get()) != EOF) {
        ++n;
    }
    in_file_handle.close();

    cout << "There are " << n << " characters in " 
         << fn << " file." << endl;

    return 0;
}

```


## 6.9

**题：** 完成编程练习6，但从文件中读取所需的信息。该文件的第一项 应为捐款人数，余下的内容应为成对的行。在每一对中，第一行为捐款人姓名，第二行为捐款数额。即该文件类似于下面：

```bash
4 Sam Stone
2000
Freida Flass
100500
Tammy Tubbs
5000
Rich Raptor
55000
```

**解：**

```Cpp
#include <iostream>
#include <fstream>
#include <string>


int main() {

    using namespace std;
    const int Grand_Amount = 10000;
    string file_name; 
    ifstream in_file_handle;

    struct Patron {
        string name;
        double amount;
    };

    int contribute_num = 0;
    cout << "Enter a file name: ";

    getline(cin, file_name);
    in_file_handle.open(file_name.c_str());
    in_file_handle >> contribute_num;
    in_file_handle.get();  // 读取空白

    Patron *p_contribution = new Patron [contribute_num];
    for (int i = 0; i < contribute_num; ++i) {
        /*
         * 4 Sam Stone
         * 2000
         * Freida Flass
         * 100500
         * Tammy Tubbs
         * 5000
         * Rich Raptor
         * 55000
         *
         */
        getline(in_file_handle, p_contribution[i].name);
        in_file_handle >> p_contribution[i].amount;
        in_file_handle.get();   // 读掉空白(包括滞留在行末的回车符)
    }
    in_file_handle.close();

    unsigned int grand_amount_n = 0;
    cout << "\nGrand patron: " << endl;
    for (int i = 0; i < contribute_num; ++i) {

        if (p_contribution[i].amount > Grand_Amount) {
            cout << "Contributor name: " << p_contribution[i].name << "\n"
                 << "Contributor amount: " << p_contribution[i].amount << endl;
            ++grand_amount_n;
        }
    }

    if (grand_amount_n == 0) {
        cout << "None" << endl;
    }

    bool is_empty = true;
    cout << "\nPatrons: " << endl;
    for (int i=0; i < contribute_num; ++i) {
        cout << "Contributor name: " << p_contribution[i].name << "\n"
             << "Contributor amount: " << p_contribution[i].amount << endl;

        is_empty = false;
    }

    if (is_empty) {
        cout << "** None **" << endl;
    }

    delete [] p_contribution;
    return 0;
}


```


