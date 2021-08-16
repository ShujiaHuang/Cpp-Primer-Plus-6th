// wrapped2.cpp -- callable types and templates
#include <iostream>
#include <math.h>
#include <functional>
using namespace std;

template <typename T>
T use_f(T v,  std::function<T(T)> f)
{
    static int count = 0;
    count++;
    cout << "  use_f count = " << count << ", &count = " << &count << endl;
    return f(v);
}

class Fp
{
private:
    double z_;
public:
    Fp(double z = 1.0) : z_(z) {}
    double operator()(double p) { return z_*p; }
};
 class Fq
{
private:
    double z_;
public:
    Fq(double z = 1.0) : z_(z) {}
    double operator()(double q) { return z_+ q; }
};

double dub(double x) {return 2.0*x;}

int main()
{
    double y = 1.21;
    cout << "Function pointer dub:\n";
	cout << "  " << use_f<double>(y, dub) << endl;
    cout << "Function pointer sqrt:\n";
	cout << "  " << use_f<double>(y, sqrt) << endl;
    cout << "Function object Fp:\n";
	cout << "  " << use_f<double>(y, Fp(5.0)) << endl;
    cout << "Function object Fq:\n";
	cout << "  " << use_f<double>(y, Fq(5.0)) << endl;
    cout << "Lambda expression 1:\n";
	cout << "  " << use_f<double>(y, [](double u) {return u*u;}) << endl;
    cout << "Lambda expression 2:\n";
	cout << "  " << use_f<double>(y, [](double u) {return u+u/2.0;}) << endl;
  
    cin.get();
    return 0;
}
