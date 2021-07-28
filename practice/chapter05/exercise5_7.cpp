// Create by Shujia Huang on 2021-07-28
#include <iostream>
#include <string>


int main() {
    using namespace std;

    struct Car {
        string company;
        int year;  
    };

    int car_num = 0;
    cout << "How many cars do you wish to catalog? ";
    cin >> car_num;
    cin.get();

    Car *cars = new Car[car_num];
    for (int i=0; i < car_num; ++i) {
        cout << "Please enter the maker: ";
        cin >> (cars+i)->company;

        cout << "Please enter the year made: ";
        cin >> (cars+i)->year;
    }

    cout << "\nHere is your collection: \n";
    for (int i=0; i < car_num; ++i) {
        cout << cars[i].year << " " << cars[i].company << endl;
    }

    delete [] cars;
    return 0;
}