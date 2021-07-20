// Create by Shujia Huang on 2021-07-20
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