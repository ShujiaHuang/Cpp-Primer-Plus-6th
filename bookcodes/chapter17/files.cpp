// files.cpp -- saving to a file
#include <iostream> // not needed for many systems
#include <fstream>
#include <string>
#include <sstream>

int main()
{
    using namespace std;
    string filename = "file";

 
 
// create output stream object for new file and call it fout
	int i;
	for (i = 0; i < 140; i++)
	{
		   ostringstream outstr;   // manages a string stream
		   outstr << filename << i;
		string fname = outstr.str();
        ofstream fout(fname.c_str());
		if (!fout.is_open())
			break;
		fout << "For your eyes only!\n";        // write to file
        fout.close();           // close file
		fout.clear();
	}
	cout << "i: " << i << endl;
    // std::cin.get();
    // std::cin.get();
    return 0; 
}
