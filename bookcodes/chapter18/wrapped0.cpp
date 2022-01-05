// wrapped0.cpp  -- using a function wrapper
#include "somedefs.h"
#include <iostream>
#include <math.h>
#include <functional>

double dub(double x) {return 2.0*x;}

int main()
{
	using std::cout;
	using std::endl;
	using std::function;
    typedef function<double(double)> fdd;
    double y = 1.21;
    function<double(double)> ef1 = dub;
    function<double(double)> ef2 = std::sqrt;
    function<double(double)> ef3 = Fq(10.0);
    function<double(double)> ef4 = Fp(10.0);
    function<double(double)> ef5 =  [](double u) {return u*u;};
    function<double(double)> ef6 =  [](double u) {return u+u/2.0;};
    cout << use_f(y, function<double(double)>(dub)) << endl;
    cout << use_f(y, fdd(sqrt)) << endl;
    cout << use_f(y, ef3) << endl;
    cout << use_f(y, ef4) << endl;
    cout << use_f(y, ef5) << endl;
    cout << use_f(y, ef6) << endl;

    std::cin.get();
    return 0;
}
