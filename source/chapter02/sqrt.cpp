// sqrt.cpp -- using the sqrt() function

#include <iostream>
#include <cmath>    // or math.h

int main()
{
    using namespace std;
   
    double area;
    cout << "Enter the floor area, in square feet, of your home: ";
    cin >> area;
    double side;
    side = sqrt(area);
    cout << "That's the equivalent of a square " << side 
         << " feet to the side." << endl;
    cout << "How fascinating!" << endl;
	// cin.get();
	// cin.get();
    return 0;
}
