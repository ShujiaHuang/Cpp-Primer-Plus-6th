# 第 2 章 《开始学习C++》 编程练习题之我解

## 2.1

**题：** 编写一个C++程序，它显示您的姓名和地址。

**解：**

```Cpp
#include <iostream>

int main() {

    using namespace std;

    cout << "Hi there, I'm Shujia Huang from Shenzhen, Guangdong, China" << endl;
    return 0;
}

```


## 2.2

**题：** 编写一个C++程序，它要求用户输入一个以 long 为单位的距离， 然后将它转换为码（yard，一long 等于 220 码）。
    
**解：**


```Cpp

#include <iostream>

int main() {

    using namespace std;

    int distance=0, yard;
    cout << "Please input a distance numebr in the unit of Long: ";
    cin >> distance;
    yard = distance * 220;

    cout << "The distance tranform in yards is: " << yard << endl;

    return 0;
}

```

## 2.3

**题：** 编写一个C++程序，它使用 3 个用户定义的函数（包括main()），并生成下面的输出：

```bash

Three blind mice
Three blind mice
See how they run
See how they run

```
其中一个函数要调用两次，该函数生成前两行；另一个函数也被调用两次，并生成其余的输出。


**解：**


```Cpp

#include <iostream>

using namespace std;

void blind_mice() {
    cout << "Three blind mice." << endl;
    return;
}

void how_they_run() {
    cout << "See how they run" << endl;
    return;
}

int main() {

    blind_mice();
    blind_mice();

    how_they_run();
    how_they_run();
    return 0;
}

```


## 2.4

**题：** 编写一个程序，让用户输入其年龄，然后显示该年龄包含多少个月，如下所示：

```bash
Enter your age: 29

```

**解：**

```Cpp
#include <iostream>

int main() {

    using namespace std;

    int years, months;
    cout << "Enter your age: ";
    cin >> years;

    months = years * 12;
    cout << years << " years is " << months << " monthes." << endl;  
    return 0;
}

```


## 2.5

**题：** 编写一个程序，其中的main( )调用一个用户定义的函数（以摄氏温度值为参数，并返回相应的华氏温度值）。该程序按下面的格式要 求用户输入摄氏温度值，并显示结果：

```bash
Please enter a Celsius value: 20

20 degrees Celsius is 68 degrees Fahrenheit.

```

转换公式：华氏温度 = 1.8×摄氏温度 + 32.0


**解：**

```Cpp

#include <iostream>


double celsiu2fahrenit(double celsius) {
    return 1.8 * celsius + 32.0;
}


int main() {

    using namespace std;

    double celsius;
    cout << "Please enter a celsius value: ";
    cin >> celsius;

    cout << celsius << " degrees Celsius is " 
         << celsiu2fahrenit(celsius) << " degrees Fahrenheit." << endl;

    return 0;
}

```


## 2.6

**题：** 编写一个程序，其main( )调用一个用户定义的函数（以光年值为参数，并返回对应天文单位的值）。该程序按下面的格式要求用户输 入光年值，并显示结果：

```bash

Enter the number of light years: 4.2

4.2 light years = 265608 astromonical units.

```
天文单位是从地球到太阳的平均距离（约150000000公里或93000000英里），光年是光一年走的距离（约10万亿公里或6万亿英里）（除太阳外，最近的恒星大约离地球4.2光年）。请使用double类型，转换公式为：1光年=63240天文单位.


**解：**

```Cpp

#include <iostream>


double light_years2astromonical_unit(double light_years) {

    return light_years * 63240;
}


int main() {

    using namespace std;

    double light_years;
    cout << "nter the number of light years: ";
    cin >> light_years;

    cout << light_years 
         << " light years = " 
         << light_years2astromonical_unit(light_years)
         << " astromonical units." << endl;

    return 0;
}

```

## 2.7

**题：** 编写一个程序，要求用户输入小时数和分钟数。在 main() 函数中，将这两个值传递给一个void函数，后者以下面这样的格式显示这两个值：

```bash

Enter the number of hours: 9
Enter the number of minutes: 28

Time: 9:28

```

**解：**

```Cpp

#include <iostream>

using namespace std;


void display_time(double hours, double minutes) {

    cout << "Time: " << hours << ":" << minutes << endl;

    return;
}

int main() {    

    double hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    display_time(hours, minutes);

    return 0;
}

```






