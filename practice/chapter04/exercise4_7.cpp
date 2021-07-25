// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <string>

struct Pizza
{
    std::string company;
    double diameter;
    double weight;
    
};

int main() {
    using namespace std;

    Pizza pizza;
    cout << "Enter the pizza company: ";
    getline(cin, pizza.company);

    cout << "Enter the diameter of pizza: ";
    cin >> pizza.diameter;

    cout << "Enter the weight of pizza: ";
    cin >> pizza.weight;

    cout << "\nHere is the pizza information: \n"
         << "Company: " << pizza.company << "\n"
         << "Diameter: " << pizza.diameter << "\n"
         << "Weight: " << pizza.weight << endl;

    return 0;
}