#include "memhacks.h"

using namespace std;


int main()
{
	A a;
	B b;
	cerr << " . . . Start executing . . ." << endl;
	cerr << "-------------------" << endl;
	cout << &a << "\n" << &b << "\n";
	printInternals(b);
	cout << "MEMHACKS:" << endl;
	b.printData(cout);
	cout << endl << "Using virtual functions:" << endl;
	b.printData2(cout);
	return 0;
}