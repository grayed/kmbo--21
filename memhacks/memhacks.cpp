#include <iostream>
#include "memhacks.h"

using namespace std;

B::B() : b_s("It's b!") {
	for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
		data[i] = (float)(i * 2);
}
A::A() : a_s("It's a!") { }

std::string A::geta_s(){return a_s;}
std::string B::getb_s(){return b_s;}
float B::getdata(int i){return data[i];}
void A::aAbout(std::ostream& os){
	os << "a_s is - " << geta_s() << '\n';
}
void B::bAbout(std::ostream& os){
	os << "b_s is -" << getb_s() << '\n';
	os << "data = ";
	for(int i = 0;i < 7;i++){
			os << getdata(i) << ' ';
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
	cout << "Address of data is 0x" << b.data << endl;
	cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << endl;
	cout << "B string is '" << b.getBString() << "'" << endl;
	//cout << "B data: "; b.printData(cout); cout << endl;
}

/// <summary>
/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
/// <returns>Значение B::b_s</returns>

std::string A::getBString() const {
	return *((const std::string *)(this+1));
	// TODO
}

float A::getBData(int idx) const{
	return *(((const float *)(this+1))+8+idx);
}

std::string A::getAString() const {
	return *((const std::string *)((const char *)(this+1)-8)-1);
	// TODO
	return "";
}



/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью адресной арифметики.
/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
/// </summary>
void A::printData(std::ostream& os) {
	// TODO
	os << "a_s is - " << getAString() << '\n';
	os << "b_s is - " << getBString() << '\n';
	os << "data = " << ' ';
	for(int i = 0;i < 7;i++){
			os << getBData(i) << ' ';
	}
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>

void B::printData2(std::ostream& os) {
	 aAbout(os);
	 bAbout(os);
}


int main()
{
	A a;
	B b;
	b.printData(std::cout);
	cout << '\n';
	b.printData2(std::cout);
	//printInternals(b);
	//cout << sizeof(char);

	return 0;
}
