#include <iostream>
#include "memhacks.h"

using namespace std;

A::A() : a_s("It's a!"), foo(0) {}

B::B() : b_s("It's b!") {
	for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		data[i] = (float)i * 2;
}

void printInternals(const B& b) {
	const A* a = &b, * a2 = a + 1;
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cout << "B string is '" << b.getBString() << "'" << endl;
	cout << "B data "; a->printData(cout); cout << endl;
	cout << "B data "; a->printData2(cout); cout << endl;
}

@@ - 27, 7 + 30, 19 @@ void printInternals(const B & b) {

	std::string A::getBString() const {
		return dynamic_cast<const B*>(this)->getBString();
	}

	std::string B::getBString() const {
		return b_s;
	}

	float A::getData(int idx) const {
		return dynamic_cast<const B*>(this)->getData(idx);
	}

	float B::getData(int idx) const {
		return data[idx];
	}
}