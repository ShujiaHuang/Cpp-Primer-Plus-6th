// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <string>

struct CandyBar
{
    std::string name;
    double weight;
    int calories;
};


int main() {

    using namespace std;

    CandyBar candbar[3] = {
        {"Mocha Munch", 2.3, 350},
        {"Big Rabbit", 5, 300},
        {"Joy Boy", 4.1, 430}
    };

    cout << "The name of the CandyBar: " << candbar[0].name << "\n"
         << "The weight of the candy: " << candbar[0].weight << "\n"
         << "The calories information: " << candbar[0].calories << "\n\n";

    cout << "The name of the CandyBar: " << candbar[1].name << "\n"
         << "The weight of the candy: " << candbar[1].weight << "\n"
         << "The calories information: " << candbar[1].calories << "\n\n";

    cout << "The name of the CandyBar: " << candbar[2].name << "\n"
         << "The weight of the candy: " << candbar[2].weight << "\n"
         << "The calories information: " << candbar[2].calories << endl;

    return 0;
}