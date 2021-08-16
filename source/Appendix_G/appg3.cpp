#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Items
{
    double x;
    double y;
    int m;
public:
	Items() : x(0),y(0), m(0){};      // #1
    Items (double xx, double yy, int mm): x(xx),y(yy), m(mm){}; // #2
	void Show() const { cout << x << ", " << y << ", " << m << endl;}
};
int main()
{
	vector<Items> vt(5);

	for_each( vt.begin(), vt.end(), [](const Items & i){i.Show();});

    vt.push_back( Items(8.2, 2.8, 3));  //
	for_each( vt.begin(), vt.end(), [](const Items & i){i.Show();});
	vt.emplace_back( 8.2, 2.8, 3);  //
	for_each( vt.begin(), vt.end(), [](const Items & i){i.Show();});
	cin.get();
}