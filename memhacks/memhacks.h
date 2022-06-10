#pragma once
using namespace std;
#include <ostream>
#include <string>
#include <sstream>
#include <iostream>

class B;

class A {
	string a_s;
	int foo;
	friend void printInternals(const B&);
	friend void printInternals(B&);
public:
	A() : a_s("It's a!"), foo(0) { }

	string getAString() const { return *((const string*)((const float*)(this + 1) - 12)); } //hurray!!!

	string getBString() const {
		return  *((const string*)(this + 1));
	}


	//доступ к элементам массива
	float getdataFloat(int i) { return ((float*)(this + 2) - 4)[i]; }

	virtual string str_A() const {
		stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
};



class B : public A {
	string b_s;
	float data[7];
	friend void printInternals(const B&);
	friend void printInternals(B&);// Дружественный метод класса
public:
	B() : b_s("It's b!") {
		for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
			data[i] = (float)i * 2;
	}
	/// <summary>
	/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	/// <returns>Значение B::b_s</returns>

	virtual string str_B() {
		stringstream ss;
		ss << "String B: " << b_s << std::endl;
		ss << "Data : ";
		for (int i = 0; i < 7; i++) {
			ss << data[i] << "; ";
		}
		std::cout << std::endl;
		return ss.str();
	}

	void printData2(std::ostream& os);
	/// <summary>
	/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
	/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
	/// с помощью адресной арифметики.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	void printData(std::ostream& os) {
		os << "A string is '" << getAString() << "', B string is '" << getBString() << "'" << std::endl;
		for (int i = 0; i < 7; ++i) os << getdataFloat(i) << " ";
	}

};


