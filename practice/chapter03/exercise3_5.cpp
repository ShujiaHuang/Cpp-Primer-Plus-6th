// Create by Shujia Huang on 2021-07-20
#include <iostream>

int main() {
    using namespace std;

    long long population_world, population_China;
    cout << "Enter the world's population: ";
    cin >> population_world;
    cout << "Enter the population of China: ";
    cin >> population_China;

    double rate = double(population_China)/population_world;
    cout << "The population of the China is " << rate * 100
         << "% of the world population." << endl;

    return 0;
}