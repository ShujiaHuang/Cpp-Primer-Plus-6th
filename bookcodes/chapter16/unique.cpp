#include <iostream>
#include <string>
#include <memory>
using namespace std;

unique_ptr<string> demo(const char * s)
{
    unique_ptr<string> temp(new string(s));
    return temp;
}

int main()
{
    unique_ptr<string> ps1, ps2;
    ps1 = demo("Uniquely special");
    ps2 = move(ps1);                 // enable assignment
    ps1 = demo(" and more");
    cout << *ps2 << *ps1 << endl;

    // cin.get();
    return 0;
}