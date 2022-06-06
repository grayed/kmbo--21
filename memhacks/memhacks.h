#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;
	friend void printInternals(B&);
public:
	A();
	std::string getBString() const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);
	virtual std::string* getBStr() = 0;
	virtual float* getBData() = 0;
};

class B : public A {
	std::string b_s;
	float data[7];
	friend void printInternals(B&);
public:
	B();
	virtual std::string* getBStr() { return &b_s; }
	virtual float* getBData() { return data; }
};

void printInternals(B& b);
