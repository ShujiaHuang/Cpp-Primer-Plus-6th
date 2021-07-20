# 第 3 章 《处理数据》 编程练习题之我解

## 3.1

**题：** 编写一个小程序，要求用户使用一个整数指出自己的身高（单位为英寸），然后将身高转换为英尺和英寸。该程序使用下划线字符来指示输入位置。另外，使用一个const符号常量来表示转换因子。

**解:**

```Cpp

#include <iostream>


const int Foot2inch = 12;

int main() {

    using namespace std;

    int input_height = 0;
    cout << "Please input you height in inch: __\b\b";
    cin >> input_height;

    int height_foot = input_height / Foot2inch;
    int height_inch = input_height % Foot2inch;

    cout << "Your height in inch is: " << input_height 
         << "; transforming in foot and inch is: " 
         << height_foot << " foot "
         << height_inch << " inch." << endl;

    return 0;
}

```


## 3.2

**题：** 编写一个小程序，要求以几英尺几英寸的方式输入其身高，并以磅为单位输入其体重。（使用3个变量来存储这些信息。）该程序报告其BMI（Body Mass Index，体重指数）。为了计算BMI，该程序以英寸的方式指出用户的身高（1英尺为12英寸），并将以英寸为单位的身 高转换为以米为单位的身高（1英寸=0.0254米）。然后，将以磅为单位 的体重转换为以千克为单位的体重（1千克=2.2磅）。最后，计算相应的BMI—体重（千克）除以身高（米）的平方。用符号常量表示各种转 换因子。

**解：**

```Cpp
#include <iostream>

const int Foot2Inch = 12;
const double Inch2Meter = 0.0254;
const double Kg2Pound = 2.2;

double BMI(double weight, double height) {

    return weight/(height*height);
}

int main() {

    using namespace std;

    double height_foot = 0;
    double height_inch = 0;
    double weight_pound = 0;

    cout << "Please enter your height in foot and Inch2Meter." << endl;
    cout << "Enter the foot of height: __\b\b";
    cin >> height_foot;

    cout << "Enter the inch of height: __\b\b";
    cin >> height_inch;

    cout << "Please enter your weight in pound: __\b\b";
    cin >> weight_pound;

    double height_meter = (height_foot * Foot2Inch + height_inch) * Inch2Meter;
    double weight_kg = weight_pound / Kg2Pound;
    double bmi = BMI(weight_kg, height_meter);

    cout << "Your BMI is: " << bmi << endl;

    return 0;
}

```


## 3.3

**题：** 编写一个程序，要求用户以度、分、秒的方式输入一个纬度，然后以度为单位显示该纬度。1度为60分，1分等于60秒，请以符号常量的方式表示这些值。对于每个输入值，应使用一个独立的变量存储它。 下面是该程序运行时的情况：

```bash

Enter a latitude in degree, minutes, and seconds:
First, enter the degree: 37
Next, enter the minutes of arc: 51
Finally, enter the seconds of arc: 19

37 degrees, 51 minutes, 19 seconds = 37.8553 degrees.

```

**解：**

```Cpp

#include <iostream>


int main() {

    using namespace std;

    double degree, minutes, seconds;

    cout << "Enter a latitude in degree, minutes and seconds." << endl;
    cout << "First, enter the degree: ";
    cin >> degree;

    cout << "Next, enter the minutes of arc: ";
    cin >> minutes;

    cout << "Finally, enter the seconds of arc: ";
    cin >> seconds;

    double degree2 = degree + minutes/60 + seconds/3600;
    cout << degree << " degrees, " << minutes << " minutes, "
         << seconds << " seconds = " << degree2 << endl;

    return 0;
}

```


## 3.4

**题：** 编写一个程序，要求用户以**整数**方式输入秒数（使用long或long long变量存储），然后以天、小时、分钟和秒的方式显示这段时间。使用符号常量来表示每天有多少小时、每小时有多少分钟以及每分钟有多 少秒。该程序的输出应与下面类似：

```bash
Enter the number of seconds: 31600000
31600000 seconds = 365 days, 17 hours, 46 minutes, 40 seconds.

```

**解：**

```Cpp

#include <iostream>

int main() {

    using namespace std;

    long total_seconds;

    cout << "Enter the number of seconds: ";
    cin >> total_seconds;

    int days = total_seconds / 86400;
    int hours = (total_seconds % 86400) / 3600;
    int minutes = ((total_seconds % 86400) % 3600) / 60;
    int seconds = ((total_seconds % 86400) % 3600) % 60;

    cout << total_seconds << "seconds = " 
         << days << " days, " 
         << hours << " hours, "
         << minutes << " minutes, "
         << seconds << " seconds." << endl;

    return 0;
}

```


## 3.5

**题：** 编写一个程序，要求用户输入全球当前的人口和中国当前的人口（或其他国家的人口）。将这些信息存储在long long变量中，并让程序显示中国（或其他国家）的人口占全球人口的百分比。该程序的输出 应与下面类似：

```bash
Enter the world's population: 7850176700
Enther the population of China: 1411780000
The population of the China is 17.9841% of the world population.

```

**解：**

```Cpp

#include <iostream>

int main() {
    using namespace std;

    long long population_world, population_China;
    cout << "Enter the world's population: ";
    cin >> population_world;
    cout << "Enter the population of China: ";
    cin >> population_China;

    double rate = double(population_China)/population_world;
    cout << "The population of the China is " << rate * 100
         << "% of the world population." << endl;

    return 0;
}

```


## 3.6 

**题：** 编写一个程序，要求用户输入驱车里程（英里）和使用汽油量（加仑），然后指出汽车耗油量为一加仑的里程。如果愿意，也可以让程序要求用户以公里为单位输入距离，并以升为单位输入汽油量，然后 指出欧洲风格的结果—即每100公里的耗油量（升）。

**解：**

```Cpp

#include <iostream>

int main() {
    using namespace std;
    double kilometer, oil_liter;

    cout << "Enter the distance that you've dirver in kilometer: ";
    cin >> kilometer;

    cout << "Enter the comsumption of oil: ";
    cin >> oil_liter;

    double kilometer_per_liter = kilometer / oil_liter;
    cout << "The average fuel comsumption is " 
         << 100 / kilometer_per_liter << " L/100km" << endl;
}

```


## 3.7

**题：** 编写一个程序，要求用户按欧洲风格输入汽车的耗油量（每100公里消耗的汽油量（升）），然后将其转换为美国风格的耗油量—每加仑多少英里。

> 注意，除了使用不同的单位计量外，美国方法（距离/燃 料）与欧洲方法（燃料/距离）相反。100公里等于62.14英里，1加仑等于3.875升。因此，19mpg大约合12.4l/100km，27mpg大约合 8.71/100km。 

**解：**

```Cpp

#include <iostream>

int main() {
    using namespace std;

    const double Km2Mile = 0.6214;
    const double Gallon2Litre = 3.875;

    double fuel_comsuption_en = 0.0;
    cout << "Enter the fuel comsuption in European standard: ";
    cin >> fuel_comsuption_en;

    double fuel_comsuption_us = (100 * Km2Mile) / (fuel_comsuption_en/Gallon2Litre);
    cout << "The fuel comsuption in US standard is " << fuel_comsuption_us 
         << " Miles/Gallon (mpg)." << endl;  

    return 0;
}

```

