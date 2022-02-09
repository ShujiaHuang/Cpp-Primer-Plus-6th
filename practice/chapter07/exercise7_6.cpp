//
// Created by Shujia Huang on 2/9/22.
//
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
