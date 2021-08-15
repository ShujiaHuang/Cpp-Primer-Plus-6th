// newexcp.cpp -- the bad_alloc exception
#include <iostream>
#include <new>
#include <cstdlib>  // for exit(), EXIT_FAILURE
using namespace std;

struct Big
{
    double stuff[20000];
};

int main()
{
    Big * pb;
 
    pb = new (std::nothrow) Big[10000]; // 1,600,000,000 bytes
	if (pb == NULL)
	{
		cout << "Could not allocate memory. Bye.\n";
		cin.get();
		exit(EXIT_FAILURE);
	}
  
    cout << "Memory successfully allocated\n";
    pb[0].stuff[0] = 4;
    cout << pb[0].stuff[0] << endl;
    delete []  pb;
    // cin.get();
    return 0; 
}
