// Create by Shujia Huang on 2021-07-20
#include <iostream>

int main() {

    using namespace std;

    long total_seconds;

    cout << "Enter the number of seconds: ";
    cin >> total_seconds;

    int days = total_seconds / 86400;
    int hours = (total_seconds % 86400) / 3600;
    int minutes = ((total_seconds % 86400) % 3600) / 60;
    int seconds = ((total_seconds % 86400) % 3600) % 60;

    cout << total_seconds << "seconds = " 
         << days << " days, " 
         << hours << " hours, "
         << minutes << " minutes, "
         << seconds << " seconds." << endl;

    return 0;
}