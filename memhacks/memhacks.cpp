#include "memhacks.h"

using namespace std;


/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(B& b) {
	const A* a = &b, * a2 = a + 1; // указатель А* сомтрит на объект производного класса
	std::cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << std::endl;
	std::cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << std::endl;
	std::cout << "B string is '" << b.getBString() << "'" << std::endl;
	std::cout << "B data: "; b.printData(std::cout); std::cout << std::endl;
	std::cout << "B data: "; b.printData2(std::cout); std::cout << std::endl;
}

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void B::printData2(std::ostream& os) {
	os << str_A();   // virtual function
	os << str_B();
}



int main()
{
	A a;
	B b;
	cout << &a << "\n" << &b << "\n";
	printInternals(b);
	cout << "MEMHACKS:" << endl;
	b.printData(cout);
	cout << endl << "STANDART:" << endl;
	b.printData2(cout);
	return 0;
}