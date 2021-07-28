// Create by Shujia Huang on 2021-07-28
#include <iostream>
#include <cstring>

int main() {
    using namespace std;

    int word_count = 0;
    char ch[80];
    cout << "Enter a word (type 'done' to stop the program.): \n";
    do {
        cin >> ch;

        if (strcmp(ch, "done") != 0) {
            word_count++;
        }

    } while (strcmp(ch, "done") != 0);

    cout << "\nYou entered a total of " << word_count << " words." << endl;

    return 0;
}