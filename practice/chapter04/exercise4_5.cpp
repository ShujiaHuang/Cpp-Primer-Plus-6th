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

    CandyBar snack = {"Mocha Munch", 2.3, 350};  // 初始化结构体

    cout << "The name of the CandyBar: " << snack.name << "\n";
    cout << "The weight of the candy: " << snack.weight << "\n";
    cout << "The calories information: " << snack.calories << endl;

    return 0;
}

