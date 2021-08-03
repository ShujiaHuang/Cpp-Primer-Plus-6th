// Create by Shujia Huang on 2021-08-03
#include <iostream>
#include <array>


int main() {
    using namespace std;
    
    const unsigned int size = 10;
    array<double, size> donation;

    double sum_value = 0;
    unsigned int large_avg = 0, n = 0;

    cout << "Enter 10 double value or type non-digital value to exit: ";
    while ((n < size) && (cin >> donation[n])) {
        
        sum_value += donation[n];
        ++n;
    }

    double avg = sum_value / n;
    for (int i=0; i < n; i++) {

        if (donation[i]>avg)
            ++large_avg;
    }

    cout << "The average value is: " << avg
         << ", there are " << large_avg
         << " larger than average value." << endl;

    return 0;
}