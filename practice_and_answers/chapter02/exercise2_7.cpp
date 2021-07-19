// Create by Shujia Huang on 2021-07-19

#include <iostream>

using namespace std;


void display_time(double hours, double minutes) {

    cout << "Time: " << hours << ":" << minutes << endl;

    return;
}

int main() {

    double hours, minutes;
    cout << "Enter the number of hours: ";
    cin >> hours;

    cout << "Enter the number of minutes: ";
    cin >> minutes;

    display_time(hours, minutes);

    return 0;
}