// Create by Shujia Huang on 2021-07-28
#include <iostream>

int main() {
    using namespace std;

    double daphne_account = 100;
    double cleo_account = 100;

    int year = 0;
    while (cleo_account <= daphne_account) {
        ++year;

        daphne_account += 10;
        cleo_account += cleo_account * 0.05;
    }

    cout << "After " << year << " Years. " 
         << "Cleo's account is " << cleo_account
         << " while more than the one of Daphne which is " 
         << daphne_account << "." << endl;

    return 0;
}
