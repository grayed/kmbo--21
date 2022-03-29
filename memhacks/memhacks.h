#pragma once

#include <ostream>
#include <string>

/*
1) Реализовать функцию A::getBString(), возвращающую значение B::b_s(подразумевается, 
что объект, для которого вызывается, является объектом типа B).
Используйте знание о расположении объектов в памяти.
2) Реализовать A::printData(), выводящую в поток текствое представление A::a_s, B::b_s и B::data с помощью A::getBString() и аналогичных техник.
3) Реализовать A::printData2(), выводящую в поток текствое представление A::a_s, B::b_s и B::data с помощью виртуальных функций.
*/

class B;	// чтобы можно было объявить printInternals() как friend в классе A

class A {
	std::string a_s;
	int foo;

	friend void printInternals(const B&);

public:
	std::string getBString() const;
	void printData(std::ostream& os);
	void printData2(std::ostream& os);
};

class B : public A {
	std::string b_s;
	float data[7];

	friend void printInternals(const B&);

public:
	B();
};

void printInternals(const B& b);
