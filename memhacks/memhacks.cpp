#include <iostream>
#include "memhacks.h"
#include <sstream>
using namespace std;
A::A() : a_s("It's a!") { }

B::B() : b_s("It's b!") {
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		data[i] = i * 2;
}
 
void printInternals(const B& b) {
	const A* a = &b, * a2 = a + 1;
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cout << "B string is '" << b.getBString() << "'" << endl;
}

std::string A::getBString() const {return *(( const string *)(this+1)); }

std::string A::getAString() const { return *(( const string *)(this+1)-3); }

float A::getdataFloat(int i) const { return *(( const float *)(this+2)-4+i); }

void printData(std::ostream& os, const A& a, const B& b) {
    os << "A string is '" << b.getAString() << "'" << endl;
    os << "B string is '" << b.getBString() << "'" << endl;
	os << "Data: ";
	for (int i=0;i<7;i++){
	        os << b.getdataFloat(i) << "; ";
	}
}


void B::printData2(std::ostream& os) {
	os << aboutA();
	os << aboutB();
}
using namespace std;
int main()
{
	B b;
    A a;
	printInternals(b);
    cout << "MEMHACKS:" << endl;
    printData(cout,a,b);
    cout << endl << "STANDART:" << endl;
	b.printData2(cout);
	return 0;
}
