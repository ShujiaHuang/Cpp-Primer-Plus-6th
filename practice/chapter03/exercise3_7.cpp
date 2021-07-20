// Create by Shujia Huang on 2021-07-20
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