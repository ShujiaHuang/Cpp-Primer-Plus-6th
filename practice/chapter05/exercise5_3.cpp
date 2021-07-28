// Create by Shujia Huang on 2021-07-28
#include <iostream>


int main() {
    using namespace std;

    double s = 0;
    double ch;

    while (1) {

        cout << "Enter a number (int/double) (0 to exit): ";
        cin >> ch;

        if (ch == 0) {
            break;
        }

        s += ch;
        cout << "Until now, the sum of the number you inputed is: " 
             << s << endl;
    }

    return 0;
}