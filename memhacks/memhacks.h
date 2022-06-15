#pragma once

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
	A() : a_s("It's a!"), foo(0) { }

	string getAString() const { return *((const string*)((const float*)(this) + 2)); } 
	string getBString() const {
		return  *((const string*)(this + 1));
	}


	
	float getdataFloat(size_t i) { return ((float*)(this + 2) - 4)[i]; }

	virtual string aboutA() const {
		stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
};



class B : public A {
	string b_s;
	float data[7];
	friend void printInternals(const B&);
	friend void printInternals(B&);
public:
	B() : b_s("It's b!") {
		for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++)
			data[i] = (float)i * 2;
	}
	/// <summary>
	/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	/// <returns>Значение B::b_s</returns>


	virtual string aboutB() {
		stringstream ss;
		ss << "String B: " << b_s << endl;
		ss << "Data : ";
		for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); i++) { ss << data[i] << "; "; }
		cout << endl;
		return ss.str();
	}




	void printData2(ostream& os);
	/// <summary>
	/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
	/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
	/// с помощью адресной арифметики.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	void printData(ostream& os) { 
		os << "A string is '" << getAString() << " ', B string is ' " << getBString() << " ' " << endl;
		for (size_t i = 0; i < sizeof(data) / sizeof(data[0]); ++i) os << getdataFloat(i) << " ";
	}

};

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void B::printData2(ostream& os) {
	os << aboutA();   
	os << aboutB();
}


/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(B& b) {
	const A* a = &b, * a2 = a;
	cerr << "-------------------" << endl;
	cerr << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << std::endl;
	cerr << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cerr << "B string is '" << b.getBString() << "'" << endl;
	cerr << "B data: "; b.printData(cout); cerr << endl;
	cerr << "B data: "; b.printData2(cout); cerr << endl;
	cerr << "-------------------" << endl;
}
