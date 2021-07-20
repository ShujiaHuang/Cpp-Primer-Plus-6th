// Create by Shujia Huang on 2021-07-20
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