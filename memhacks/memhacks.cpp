#include "memhacks.h"

using namespace std;

int main()
{
	A a;
	B b;
	cout << &a << "\n" << &b << "\n";
	printInternals(b);
	cout << "MEMHACKS:" << endl;
	b.printData(cout);
	cout << endl << "STANDART:" << endl;
	b.printData2(cout);
	return 0;
}
