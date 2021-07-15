// myfirst.cpp--displays a message

#include <iostream>                           // a PREPROCESSOR directive
int main()                                    // function header
{                                             // start of function body
    using namespace std;                      // make definitions visible
    cout << "Come up and C++ me some time.";  // message
    cout << endl;                             // start a new line
    cout << "You won't regret it!" << endl;   // more output
// If the output window closes before you can read it,
// add the following code:
    // cout << "Press any key to continue." <<endl;
	// cin.get();                                                   
    return 0;                                 // terminate main()
}                                             // end of function body
