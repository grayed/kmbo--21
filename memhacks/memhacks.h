#pragma once
using namespace std;
#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

class B;

class A {
	string a_s;
	int foo;
	friend void printInternals(const B&);
	friend void printInternals(B&);
public:
	A() : a_s("It's a!"), foo(0) { }

	string getAString() const { return *((const string*)((const float*)(this + 1) - 12)); } //hurray!!!

	string getBString() const {
		return  *((const string*)(this + 1));
	}


	float getdataFloat(int i) { return ((float*)(this + 2) - 4)[i]; }

	virtual string str_A() const {
		stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
};



class B : public A {
	string b_s;
	float data[7];
	friend void printInternals(const B&);
	friend void printInternals(B&);// Дружественный метод класса
public:
	B() : b_s("It's b!") {
		for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
			data[i] = (float)i * 2;
	}

	virtual string str_B() {
		stringstream ss;
		ss << "String B: " << b_s << std::endl;
		ss << "Data : ";
		for (int i = 0; i < 7; i++) {
			ss << data[i] << "; ";
		}
		std::cout << std::endl;
		return ss.str();
	}

	void printData2(std::ostream& os) {
		os << str_A();
		os << str_B();
	}
	void printData(std::ostream& os) {
		os << "A string is '" << getAString() << "', B string is '" << getBString() << "'" << std::endl;
		for (int i = 0; i < 7; ++i) os << getdataFloat(i) << " ";
	}

};

void printInternals(B& b) {
	const A* a = &b, * a2 = a + 1; // указатель А* сомтрит на объект производного класса
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << std::endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << std::endl;
	cout << "B string is '" << b.getBString() << "'" << std::endl;
	cout << "B data: "; b.printData(std::cout); std::cout << std::endl;
	cout << "B data: "; b.printData2(std::cout); std::cout << std::endl;
}
