#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
vector<string> input;
string temp;
while (cin >> temp && temp != "quit")
    input.push_back(temp);
vector<string>::iterator want=
    find(input.begin(), input.end(), string("bonus"));
if (want != input.end())
{
    vector<string>::reference r = *want;
    r = "bogus";
}
for_each(input.begin(), input.end(), [](string s){cout << s << ", ";});
cin.get();
cin.get();
}
