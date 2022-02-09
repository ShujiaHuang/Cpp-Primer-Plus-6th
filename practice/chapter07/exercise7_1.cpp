//
// Created by Shujia Huang on 2/9/22.
//
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

