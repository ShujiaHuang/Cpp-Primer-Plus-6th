# 第七章 《函数——C++的编程模块》 编程练习题之我解

## 7.1

**题：** 编写一个程序，不断要求用户输入两个数，直到其中的一个为 0。对于每两个数，程序将使用一个函数来计算它们的调和平均数，
并将结果返回给 `main()``，而后者将报告结果。调和平均数指的是倒数平均值的倒数，计算公式如下:

调和平均数 = 2.0 * x * y / (x+y)

**解：**

```Cpp
#include <iostream>

int main() {
    using namespace std;

    double x = 0, y = 0;
    double h_avg = 0;

    cout << "Enter two numbers: ";
    cin >> x >> y;

    while (x != 0 && y != 0) {
        h_avg = 2 * x * y / (x+y);
        cout << "The harmonic mean of " << x << " and " << y << " is " << h_avg << endl;
        cout << "Enter the next two numbers: ";
        cin >> x >> y;
    }

    return 0;
}
```

## 7.2

**题：** 编写一个程序，要求用户输入最多10个高尔夫成绩，并将其存储在一个数组中。程序允许用户提早结束输入，并在一行上显示所有成绩，
然后报告平均成绩。请使用3个数组处理函数来分别进行输入、显示和计算平均成绩。

**解：**

```Cpp
#include <iostream>

int input(double data[], int max_num) {
    int i = 0;
    std::cout << "Enter up o 10 golf score (-1 to quit): " << std::endl;
    while (std::cin >> data[i]) {
        if (data[i] == -1) {
            --i;
            break;
        }
        ++i;

        if (i == max_num)
            break;
    }

    return (i < max_num) ? i+1 : max_num;
}

double calculate_average(const double data[], int n) {

    double sum = 0;
    for (size_t i(0); i < n; ++i) {
        sum += data[i];
    }

    return sum / n;
}

void output(const double data[], int n) {

    std::cout << "The score are: " << std::endl;
    for (size_t i(0); i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << std::endl;
}

int main() {

    double glf_score[10];
    int n = input(glf_score, 10);
    double avg_score = calculate_average(glf_score, n);
    output(glf_score, n);
    std::cout << "The average is: " << avg_score << std::endl;
    return 0;
}
```

## 7.3

**题：** 下面是一个结构体的声明：

```Cpp
struct box {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
}
```

a. 编写一个函数，按值传递 `box` 结构体，并显示每个成员的值。
b. 编写一个函数，传递 `box` 结构体的地址，并将 volume 成员设置为其他三维长度的乘积。
c. 编写一个使用这两个函数的简单程序。

**解：**

```Cpp
#include <iostream>

typedef struct {
    char maker[40];
    float height;
    float width;
    float length;
    float volume;
} Box;

void output(Box bx) {
    std::cout << "Box maker: " << bx.maker << std::endl;
    std::cout << "Box height: " << bx.height << std::endl;
    std::cout << "Box width: " << bx.width << std::endl;
    std::cout << "Box length: " << bx.length << std::endl;
    std::cout << "Box volume: " << bx.volume << std::endl;
}

void calculate_volume(Box *p_bx) {
    p_bx->volume = p_bx->height * p_bx->width * p_bx->length;
}

int main() {
    Box bx = {"Jay", 0.49, 2.94, 0.49, 0.0};

    output(bx);
    calculate_volume(&bx);

    std::cout << "\n--\n";
    output(bx);

    return 0;
}
```

## 7.4

**题：** 许多彩票发行机构都使用如程序清单7.4所示的简单彩票玩法的变体。在这些玩法中，玩家从一组被称为域号码(field number)
的号码中选择几个。例如，可以从域号码1~47中选择5个号码; 还可以从第二个区间(如1~27)选择一个号码(称为特选号码)。要赢得头奖，必
须正确猜中所有的号码。中头奖的几率是选中所有域号码的几率与选中特选号码几率的乘积。例如，在这个例子中，中头奖的几率是从47个号码
中正确选取5个号码的几率与从27个号码中正确选择1个号码的几率的乘积。请修改程序清单7.4，以计算中得这种彩票头奖的几率。

**解：**

```Cpp
#include <iostream>

long double probability(unsigned numbers, unsigned picks) {
    long double result = 1.0;
    long double n;
    unsigned p;

    for (n = numbers, p = picks; p > 0; n--, p--) {
        result *= n/p;
    }

    return result;
}

int main() {

    unsigned int field1 = 47;
    unsigned int field2 = 27;

    std::cout << "You have no chance in "
              << probability(field1, 5) * probability(field2, 1)
              << " of winning.\n" << std::endl;
    return 0;
}
```

## 7.5

**题：** 定义一个递归函数，接受一个整数参数，并返回该参数的阶乘。

> 前面讲过，3的阶乘写作3!，等于3*2!，依此类推; 而 `0!` 被定义为1。通用的计算公式是，如果n大于零，则n!=n*(n−1)!。
在程序中对该函数进行测试，程序使用循环让用户输入不同的值，程序将报告这些值的阶乘。


**解：**

```Cpp
#include <iostream>

long factorial(int n) {

    if (n == 0) {
        return 1;
    }

    return n * factorial(n-1);
}


int main() {

    using namespace std;

    int n;
    cout << "Enter an integer number: ";
    while (!(cin >> n)) {
        cin.clear();
        while (cin.get() != '\n') {
            continue;
        }
        cout << "Please enter an integer number: ";
    }

    if (n < 0) {
        cout << "Negative number don't have factorial." << endl;
        exit(1);
    }

    long f = factorial(n);
    cout << "The factorial of " << n << " is " << f << endl;
    return 0;
}
```

## 7.6

**题：** 编写一个程序，它使用下列函数:

- `Fill_array()` 将一个 double 数组的名称和长度作为参数。它提示用户输入 double 值，并将这些值存储到数组中。
当数组被填满或用户输入了非数字时，输入将停止，并返回实际输入了多少个数字;
- `Show_array()` 将一个 double 数组的名称和长度作为参数，并显示该数组的内容;
- `Reverse-array()` 将一个 double 数组的名称和长度作为参数，并将存储在数组中的值的顺序反转。

程序将使用这些函数来填充数组，然后显示数组;反转数组，然后显示数组;反转数组中除第一个和最后一个元素之外的所有元素，然后显示数组。


**解：**

```Cpp
#include <iostream>

int Fill_array(double data[], int max_num) {

    std::cout << "Enter double numbers (non-digital to quit): " << std::endl;
    int i = 0;
    while ((i < max_num) && (std::cin >> data[i]))
        ++i;

    // return the size of array
    return i;
}

void Show_array(const double data[], int n) {

    std::cout << "The size of array is: " << n << " and the data is: ";
    for (size_t i(0); i < n; ++i) {
        std::cout << data[i] << " ";
    }
    std::cout << "\n";
}

void Reverse_array(double data[], int n) {

    for (size_t i(0); i < n/2; ++i) {
        double t = data[i];
        data[i] = data[n - 1 - i];
        data[n - 1 - i] = t;
    }

    return;
}

int main() {
    double data[10];
    int n = Fill_array(data, 10);
    Show_array(data, n);
    Reverse_array(data, n);
    Show_array(data, n);

    return 0;
}
```
