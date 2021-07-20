// Create by Shujia Huang on 2021-07-20

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