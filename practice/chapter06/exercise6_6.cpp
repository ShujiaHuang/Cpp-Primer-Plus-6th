// Create by Shujia Huang on 2021-08-03
#include <iostream>
#include <string>


int main() {

    using namespace std;

    const int Grand_Amount = 10000; 

    struct Patron {
        string name;
        double amount;
    };

    int contribute_num = 0;
    cout << "Enter the number of contributor: ";
    cin >> contribute_num;
    cin.get();  // 读取输入流中的回车符

    Patron *p_contribution = new Patron [contribute_num];
    for (int i = 0; i < contribute_num; ++i) {
        cout << "Enter the name of " << i + 1 << " contributor: ";
        getline(cin, p_contribution[i].name);

        cout << "Enter the amount of donation: ";
        cin >> p_contribution[i].amount;
        cin.get();  // 读取输入流中的回车符
    }

    unsigned int grand_amount_n = 0;
    cout << "\nGrand patron: " << endl;
    for (int i = 0; i < contribute_num; ++i) {

        if (p_contribution[i].amount > Grand_Amount) {
            cout << "Contributor name: " << p_contribution[i].name << "\n"
                 << "Contributor amount: " << p_contribution[i].amount << endl;
            ++grand_amount_n;
        }
    }

    if (grand_amount_n == 0) {
        cout << "None" << endl;
    }

    bool is_empty = true;
    cout << "\nPatrons: " << endl;
    for (int i=0; i < contribute_num; ++i) {
        cout << "Contributor name: " << p_contribution[i].name << "\n"
             << "Contributor amount: " << p_contribution[i].amount << endl;

        is_empty = false;
    }

    if (is_empty) {
        cout << "** None **" << endl;
    }

    delete [] p_contribution;

    return 0;
}

