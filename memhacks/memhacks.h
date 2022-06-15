#pragma once

#include <ostream>
#include <string>

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);

public:
	std::string getBString() const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);

	virtual const std::string* getString() const {
		return &a_s;
	};
	virtual const float* getData() const {}
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:
	B();
	virtual const std::string* getString() const {
		return &b_s;
	}
	virtual const float* getData() const {
		return data;
	}
};

void printInternals(const B& b);
