#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals( B&);

public:
	std::string getBString() const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);

	virtual std::string getBs() const {};
	virtual float * getBData() {};
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals( B&);

public:
	B();

	std::string getBs() const { return b_s; }
	float * getBData() { return data; }
};

void printInternals( B& b);
