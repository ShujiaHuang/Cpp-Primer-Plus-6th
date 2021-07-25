// Create by Shujia Huang on 2021-07-25
#include <iostream>
#include <array>

int main() {

    using namespace std;

    array<double, 3> result;

    cout << "Enter threed result of the 40 meters runing time: \n";
    cin >> result[0];
    cin >> result[1];
    cin >> result[2];

    double ave_result = (result[0] + result[1] + result[2]) / 3;
    cout << "The all three time results are: " << result[0] << ", "
         << result[1] << ", " << result[2] << endl;

    cout << "The average result: " << ave_result << endl;

    return 0;
}