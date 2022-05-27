#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

using namespace std;
class B;

class A {
	string a_s;
	int foo;
	friend void printInternals(const B&);
	friend void printInternals(B&);
public:
	A();

	string getAString() const { return *((const std::string*)((const float*)(this + 1) - 12)); }

	string getBString() const {
		return  *((const std::string*)(this + 1));
	}


	//доступ к элементам массива
	float getdataFloat(int i) { return ((float*)(this + 2) - 4)[i]; }

	virtual std::string About_A() const {
		std::stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
};



class B : public A {
	std::string b_s;
	float data[7];
	friend void printInternals(const B&);
	friend void printInternals(B&);// Дружественный метод класса
public:
	B();
	/// <summary>
	/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	/// <returns>Значение B::b_s</returns>


	virtual std::string About_B() {
		std::stringstream ss;
		ss << "String B: " << b_s << endl;
		ss << "Data : ";
		for (int i = 0; i < 7; i++) {
			ss << data[i] << "; ";
		}
		cout << endl;
		return ss.str();
	}




	void printData2(std::ostream& os);
	void printData(std::ostream& os);
};

void printInternals(B& b){}