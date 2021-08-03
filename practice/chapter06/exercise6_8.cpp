// Create by Shujia Huang on 2021-08-04
#include <iostream>
#include <fstream>
#include <string>


int main() {
    using namespace std;

    string fn;
    ifstream in_file_handle;

    unsigned int n = 0;
    char ch;

    cout << "Enter a file name: ";
    getline(cin, fn);

    in_file_handle.open(fn.c_str());
    while ((ch = in_file_handle.get()) != EOF) {
        ++n;
    }
    in_file_handle.close();

    cout << "There are " << n << " characters in " 
         << fn << " file." << endl;

    return 0;
}