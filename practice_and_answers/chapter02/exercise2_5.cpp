// Create by Shujia Huang on 2021-07-19

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
