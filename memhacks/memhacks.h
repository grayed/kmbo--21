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
	virtual std::string GETBString() const;
    virtual float GETData(int idx) const;

	void printData(std::ostream& os);
	void printData2(std::ostream& os);
};

class B : public A {
	std::string b_s;
    float data[7]{};

	friend void printInternals(const B&);

public:
	B();
    float  GETData(int idx) const override;
    std::string GETBstring() const override;
};

void printInternals(const B& b);
