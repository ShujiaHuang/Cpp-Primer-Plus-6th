// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <string>

int main() {

    using namespace std;
    string first_name, last_name;
    string final_name;

    cout << "Enter your first name: ";
    getline(cin, first_name);

    cout << "Enther your last name: ";
    getline(cin, last_name);

    final_name = last_name + ", " + first_name;

    cout << "Here's the information in a single string: " << final_name << endl;

    return 0;
}