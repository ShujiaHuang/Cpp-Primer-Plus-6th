// Create by Shujia Huang on 2021-08-03
#include <iostream>
#include <cctype>


int main() {
    using namespace std;
    char ch;

    cout << "Enter any charater: ";
    while ((ch=cin.get()) != '@') {

        if (isdigit(ch)) {
            continue;
        } else if (islower(ch)) {
            ch = toupper(ch);
        } else if (isupper(ch)) {
            ch = tolower(ch);
        }

        cout << ch;

    }

    cout << "** done **" << endl;

    return 0;
}