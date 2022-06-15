#include <ostream>
#include <string>

#include <sstream>
using namespace std;
class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);

public:
    A();
    std::string getAString() const;
	std::string getBString() const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);
	float getdataFloat(int i) const;
	virtual string aboutA() const {
	    stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
	void printData(std::ostream& os, const A& a, const B& b);
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);
	float data[7];

public:
	B();
	string get_b_s(){return b_s;}
	float get_data(int i){return data[i];}
	virtual string aboutB() {
	    stringstream ss;
		ss << "String B: " << get_b_s() << endl;
		ss << "Data : ";
		for (int i=0;i<7;i++){
			ss << get_data(i) << "; ";
		}
		cout << endl;
		return ss.str();
	}
	void printData2(std::ostream& os);
};

void printInternals(const B& b);
void printInternals(const B& b); 
