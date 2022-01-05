#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

template<typename Bag>
typename Bag::value_type min(const Bag & b)
{
    typename Bag::const_iterator it;
    typename Bag::value_type m = *b.begin();
    for (it = b.begin(); it != b.end(); ++it)
        if (*it < m)
            m = *it;
    return m;
}

int main()
{
vector<int> temperatures;
int temp;
while (cin >> temp && temp >-274)
    temperatures.push_back(temp);
int coldest = min(temperatures);
for_each(temperatures.begin(), temperatures.end(), [](int s){cout << s << ", ";});
cout << endl << coldest << endl;
cin.get();
cin.get();
}
