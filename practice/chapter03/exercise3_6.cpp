// Create by Shujia Huang on 2021-07-20
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