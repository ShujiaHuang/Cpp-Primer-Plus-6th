// Create by Shujia Huang on 2021-07-19

#include <iostream>

double light_years2astromonical_unit(double light_years) {

    return light_years * 63240;
}


int main() {

    using namespace std;

    double light_years;
    cout << "nter the number of light years: ";
    cin >> light_years;

    cout << light_years
         << " light years = "
         << light_years2astromonical_unit(light_years)
         << " astromonical units." << endl;

    return 0;
}