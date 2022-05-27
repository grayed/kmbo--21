#include "memhacks.h"

using namespace std;
A::A() : a_s("It's a!"), foo(0) { };

B::B() : b_s("It's b!") {
	for (int i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		data[i] = i * 2;
}

void printInternals(B& b) {
	const A* a = &b, * a2 = a + 1; 
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << std::endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << std::endl;
	cout << "B string is '" << b.getBString() << "'" << std::endl;
	cout << "B data: "; b.printData(std::cout); std::cout << std::endl;
	cout << "B data: "; b.printData2(std::cout); std::cout << std::endl;
}

void printData(std::ostream& os, const A& a, const B& b) {
	os << "A string is '" << b.getAString() << "'" << endl;
	os << "B string is '" << b.getBString() << "'" << endl;
	os << "Data: ";
	for (int i = 0; i < 7; i++) {
		os << b.getdataFloat(i) << "; ";
	}
}

void B::printData2(std::ostream& os) {
	os << About_A();
	os << About_B();
}


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