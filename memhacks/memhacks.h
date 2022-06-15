#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);

public:
	std::string getAString() const;
	std::string getBString() const;
	float getdataFloat(int i) const;

	virtual std::string strA() const;

	A();
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:
	B();

	virtual std::string strB() const;

	void printData(std::ostream& os);
	void printData2(std::ostream& os);
};

void printInternals(const B& b);