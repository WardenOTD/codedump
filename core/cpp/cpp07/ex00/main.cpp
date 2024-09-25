#include "whatever.hpp"
#include <string>

using std::string;

int main(){
	int a = 10, b = 20;
	cout << "a:: " << a << "   b:: " << b << endl;
	cout << "min: " << min(a, b) << endl;
	cout << "max: " << max(a, b) << endl;

	cout << "swapped" << endl;
	swap(a, b);
	cout << "a:: " << a << "   b:: " << b << endl;
	cout << "min: " << min(a, b) << endl;
	cout << "max: " << max(a, b) << endl;

	cout << "same value" << endl;
	b = 20;
	cout << "a:: " << a << "   b:: " << b << endl;
	cout << "min: " << min(a, b) << endl;
	cout << "max: " << max(a, b) << endl;

	float c = 5.5, d = 7.6;
	cout << "c:: " << c << "   d:: " << d << endl;
	cout << "min: " << min(c, d) << endl;
	cout << "max: " << max(c, d) << endl;

	cout << "swapped" << endl;
	swap(c, d);
	cout << "c:: " << c << "   d:: " << d << endl;
	cout << "min: " << min(c, d) << endl;
	cout << "max: " << max(c, d) << endl;

	cout << "same value" << endl;
	d = 7.6;
	cout << "c:: " << c << "   d:: " << d << endl;
	cout << "min: " << min(c, d) << endl;
	cout << "max: " << max(c, d) << endl;

	string e = "woah1";
	string f = "woah2";
	cout << "e:: " << e << "   f:: " << f << endl;
	cout << "min: " << ::min(e, f) << endl;
	cout << "max: " << ::max(e, f) << endl;

	cout << "swapped" << endl;
	swap(e, f);
	cout << "e:: " << e << "   f:: " << f << endl;
	cout << "min: " << ::min(e, f) << endl;
	cout << "max: " << ::max(e, f) << endl;

	cout << "same value" << endl;
	f = "woah2";
	cout << "e:: " << e << "   f:: " << f << endl;
	cout << "min: " << ::min(e, f) << endl;
	cout << "max: " << ::max(e, f) << endl;
	
	return (0);
}
