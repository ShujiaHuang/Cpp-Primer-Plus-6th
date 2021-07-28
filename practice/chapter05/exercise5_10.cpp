// Create by Shujia Huang on 2021-07-28
#include <iostream>

int main() {

    using namespace std;
    int line_num = 0;

    cout << "Enter the number of rows: ";
    cin >> line_num;

    cout << "Output:" << endl;
    for (int i = line_num; i > 0; --i) {

        for (int j = i-1; j > 0; --j) {
            cout << ".";
        }
        for (int j = line_num - (i-1); j > 0; --j) {
            cout << "*";
        }
        cout << "\n";
    }

    return 0;
}