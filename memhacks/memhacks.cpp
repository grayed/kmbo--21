#include <iostream>
#include <sstream>
#include "memhacks.h"

using namespace std;

A::A() : a_s("It's a!") {}

B::B() : b_s("It's b!") {
	for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		data[i] = i * 2;
	}
}

/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(const B& b) {
	const A* a = &b, * a2 = a + 1;
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cout << "A string is '" << b.getAString() << "'" << endl;
	cout << "B string is '" << b.getBString() << "'" << endl;
}

string A::getAString() const { 
	return *((const string*) ((const long*) (this) + 1));
}

/// <summary>
/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>S
/// <returns>Значение B::b_s</returns>
std::string A::getBString() const { return *((const string*) (this + 1)); }

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью адресной арифметики.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>

float A::getdataFloat(int i) const { return ((float*)(this + 2) - 4)[i]; }

void A::printData(std::ostream& os) {
	os << getAString() + " " + getBString() + " {";
	for (int i = 0; i < 7; ++i) {
		os << getdataFloat(i);
		if (i != 6) os << ", ";
	}
	os << "}" << endl;
}

string A::getA_s() const { return a_s; }
string B::getB_s() const { return b_s; }
string B::getDataStr() const {
	stringstream ss;
	ss << "{ ";

	for (int i = 0; i < 7; ++i) {
		ss << data[i];
		if (i != 6) ss << "," << " ";
	}
	ss << '}';

	return ss.str();
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void A::printData2(std::ostream& os) {
	os << getA_s() << " " << getB_s() << " " << getDataStr() << endl;
}

int main()
{
	B b;
	printInternals(b);
	b.printData(cout);
	b.printData2(cout);
	return 0;
}
