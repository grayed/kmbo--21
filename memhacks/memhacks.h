#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);
	virtual std::string getB_s() const { return " "; };
	virtual std::string getDataStr() const { return " "; };

public:
	std::string getAString() const;
	std::string getBString() const;
	float getdataFloat(int i) const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);

	std::string getA_s() const;

	A();
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:
	std::string getB_s() const override;
	std::string getDataStr() const override;

	B();
};

void printInternals(const B& b);
