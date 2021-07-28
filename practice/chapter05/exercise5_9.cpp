#include <iostream>
#include <string>

int main() {
    using namespace std;

    int word_count = 0;
    string ch;
    cout << "Enter a word (type 'done' to stop the program.): \n";
    do {
        cin >> ch;

        if (ch != "done") {
            word_count++;
        }

    } while (ch != "done");

    cout << "\nYou entered a total of " << word_count << " words." << endl;

    return 0;
}