// Create by Shujia Huang on 2021-07-28
#include <iostream>
#include <string>

int main() {
    using namespace std;

    string months[12] = {"Jan", "Feb", "Mar", "Apr", 
                         "May", "Jun", "Jul", "Aug", 
                         "Sep", "Oct", "Nov", "Dec"};
    int sell[12];
    int total_sales = 0;

    cout << "Enter the sales of book <<C++ for Fools>> each month." << endl;
    for (int i=0; i < 12; ++i) {

        cout << months[i] << ":";
        cin >> sell[i];

        total_sales += sell[i];
    }

    cout << "\nThe total sales is " << total_sales << endl;
    for (int i=0; i < 12; ++i) {

        cout << months[i] << ": " << sell[i] << endl;
    }


    return 0;
}