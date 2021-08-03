// Create by Shujia Huang on 2021-08-03
#include <iostream>
#include <cctype>
#include <string>


int main() {

    using namespace std;

    unsigned int vowels = 0;
    unsigned int consonants = 0;
    unsigned int other = 0;
    string input;

    cout << "Enter words (q to quit): " << endl;
    while (cin >> input) {
        if (input == "q")
            break;

        if (isalpha(input[0])) {
            switch(toupper(input[0])) {

                case 'A':;
                case 'E':;
                case 'I':;
                case 'O':;
                case 'U':
                    ++vowels;
                    break;

                default:
                    ++consonants;
                    break;
            }
        } else {
            ++other;
        }
    }

    cout << vowels << " words beginning with vowels.\n"
         << consonants << " words beginning with consonants.\n"
         << other << " words beginning with other letter." << endl;

    return 0;
}
