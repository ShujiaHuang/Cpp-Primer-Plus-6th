// Create by Shujia Huang on 2021-08-04
#include <iostream>
#include <fstream>
#include <string>


int main() {

    using namespace std;
    const int Grand_Amount = 10000;
    string file_name; 
    ifstream in_file_handle;

    struct Patron {
        string name;
        double amount;
    };

    int contribute_num = 0;
    cout << "Enter a file name: ";

    getline(cin, file_name);  // 读一整行，行末回车符排除
    in_file_handle.open(file_name.c_str());
    in_file_handle >> contribute_num;
    in_file_handle.get();  // 读掉空白(包括滞留在行末的回车符)

    Patron *p_contribution = new Patron [contribute_num];
    for (int i = 0; i < contribute_num; ++i) {
        /*
         * 4 Sam Stone
         * 2000
         * Freida Flass
         * 100500
         * Tammy Tubbs
         * 5000
         * Rich Raptor
         * 55000
         *
         */
        getline(in_file_handle, p_contribution[i].name);
        in_file_handle >> p_contribution[i].amount;
        in_file_handle.get();   // 读掉空白(包括滞留在行末的回车符)
    }
    in_file_handle.close();

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
