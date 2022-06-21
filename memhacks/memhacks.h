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
	
	std::string geta_s();
	virtual void aAbout(std::ostream& os);

	int getbefore() const;
	float getBData(int idx) const;
	std::string getBString() const ;
	std::string getAString() const ;
	std::string* getBString_adr() const;
	void printData(std::ostream& os);
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:

	void printData2(std::ostream& os);
	virtual void bAbout(std::ostream& os);
	std::string getb_s();
	float getdata(int i);

	B();
};

void printInternals(const B& b);
