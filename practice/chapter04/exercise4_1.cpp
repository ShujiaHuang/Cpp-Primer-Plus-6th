// Create by Shujia Huang on 2021-07-25
#include <iostream>


int main() {

    using namespace std;

    char first_name[40];
    char last_name[40];
    char grade_letter;
    int age;

    cout << "What is your first name: ";
    cin.getline(first_name, 40);

    cout << "What is your last name: ";
    cin.getline(last_name, 40);

    cout << "What letter grade do you deserve: ";
    cin >> grade_letter;

    cout << "What is your age: ";
    cin >> age;

    cout << "Name: " << last_name << ", " << first_name << endl;
    cout << "Grade: " << char(grade_letter+1) << "\n";
    cout << "Age: " << age << endl;

    return 0;
}