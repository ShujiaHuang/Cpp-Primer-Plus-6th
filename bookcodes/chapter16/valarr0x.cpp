#include <iostream>
#include <valarray>
#include <algorithm>
#include <cstdlib>
const int size = 10;
int main()
{
	using namespace std;

	valarray<double> numbers(size);
    int i;
    for (i = 0; i < size; i++)
        numbers[i] = rand() + i * 1.23;

   for (i = 0; i < size; i++)
        cout << numbers[i] << ' ';
   cout << endl;
   sort(begin(numbers), end(numbers));
   for (i = 0; i < size; i++)
        cout << numbers[i] << ' ';
   cout << endl;
   // cin.get();
   return 0;
}
