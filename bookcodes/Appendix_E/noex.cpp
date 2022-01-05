#include <iostream>
#include <string>
#include <cmath>
#include <numeric>
#include <vector>
#include <algorithm>
#include <unordered_set>
using namespace std;
struct S {double a; double b;};
int main()
{
	S a = {1.1,2.2};
	S b = {2.1,4.2};
	S c = {3.1,5.2};

	unordered_set<S*> us;
	us.insert(&a);
	us.insert(&b);
	us.insert(&c);
	for_each(us.begin(),us.end(),[](S* i) {cout << (*i).a << ", ";});
	cout << "\nNext\n";

	
/*	if(pt != vi.end())
		cout  << *pt << endl;
	else
		cout << "not found\n";
	cout << vi.count("cow") << endl;
	cout << vi.count("fondu") << endl;
	cout << endl;
	cout << *vi.lower_bound("cow") << endl;
	cout << *vi.upper_bound("hen") << endl;
	cout << vi.bucket_count() << endl;
	cout << vi.bucket("cow") << endl;
	cout << vi.bucket("starkA") << endl;
	cout << vi.bucket("stark") << endl;*/

	cin.get();
		
}