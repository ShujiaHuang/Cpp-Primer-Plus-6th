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

template<typename...Args>
  void dumb(int i, Args... args)
  {
	  cout << i << endl;
	  Items(args...).Show();
  }
int main()
{
	dumb(10, 2.2,4.4,1);
}