#include <iostream>
#include "memhacks.h"

using namespace std;

A::A() : a_s("It's a!"), foo(0) {}

B::B() : b_s("It's b!") {
	for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		data[i] = i * 2;
}

/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(B& b) {
	const A* a = &b, * a2 = a + 1;
	cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cout << "B string is '" << b.getBString() << "'" << endl;
	cout << "B data printData: "; b.printData(cout); cout << endl;
	cout << "B data printData2: "; b.printData2(cout); cout << endl;
}

/// <summary>
/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
/// <returns>Значение B::b_s</returns>
std::string A::getBString() const {
	return *((const string*)(this + 1));
}

std::string B::getBString() const {
    return b_s;
}

float A::getData(int idx) const {
    return ((float*)(this + 2))[idx];
}

float B::getData(int idx) const {
    return data[idx];
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью адресной арифметики.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
void A::printData(std::ostream& os) {
	os << "A string: " << a_s << ", B string: " << getBString() << ", data: ";
    for (int i = 0; i < 7; ++i) os << getData(i) << " ";
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void A::printData2(std::ostream& os) {
	B b = *((B*)(this));
    os << "A string: " << a_s << "', B string: " << b.getBString() << ", data: ";
    for (int i = 0; i < 7; ++i) os << b.getData(i) << " ";
}

int main()
{
	B b;
	printInternals(b);
	return 0;
}
