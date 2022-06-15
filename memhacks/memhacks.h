#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);

public:
	A();
	std::string getBString() const;
	virtual std::string get_s() const { return a_s; }
	virtual float *getData(){ return 0; }
 	void printData(std::ostream& os);
	void printData2(std::ostream& os);
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:
	B();
	std::string get_s() const override { return b_s; }
	float *getData() override { float* pdata = data; return pdata; }
};

void printInternals(const B& b);
