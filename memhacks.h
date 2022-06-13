#pragma once
#include <ostream>
#include <string>

class B;	
class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B& b);

public:
	A();

	virtual std::string getBString() const;
	virtual float getData(int idx) const;

	void printData(std::ostream& os) const;
	void printData2(std::ostream& os) const;
};

class B : public A {
	std::string b_s;
	float data[7]{};

	friend void printInternals(const B& b);

public:
	B();

	float getData(int idx) const override;
	std::string getBString() const override;
};

void printInternals(const B& b);