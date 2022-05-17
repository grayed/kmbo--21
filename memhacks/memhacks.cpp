#include <iostream>
#include "memhacks.h"

using namespace std;

B::B() : b_s("It's b!") {
	for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++) {
		data[i] = i*2;
	}
}

/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(B& b) {
	A* a = &b;
	b.printData2(cout);
	cout << endl;
	b.printData(cout);
	cout << endl;
}

/// <summary>
/// Извлекает значение <see cref="B	::b_s"/> из текущего объекта.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
/// <returns>Значение B::b_s</returns>
std::string A::getBString() const {
	return *(const string*)(this + 1);
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью адресной арифметики.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
void A::printData(std::ostream& os) {
	string b_s = getBString();
	os << a_s << ", " << foo << ",  " << b_s << ", ";
	const float * first = (const float*)((const string*)(this + 1) + 1);
	for (int i = 0; i < 7; i++) {
		os << (first[i]) << ", ";
	}
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void A::printData2(std::ostream& os) {
	os << a_s << ", " << foo << ", " << getBs() << ", ";
	float* data = getBData();
	for (int i = 0; i < 7; i++ ) {
		os << data[i] << ", ";
	}
}

int main()
{
	B b;
	printInternals(b);
	return 0;
}