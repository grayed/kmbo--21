#pragma once

#include <ostream>
#include <string>
#include <sstream>
#include <iostream>



class A {
protected:
	std::string a_s;
	int foo;
	friend void printInternals(const B&);
public:
	A() : a_s("It's a!") { }
	
	std::string getAString() const {  return *((const std::string*)(this + 1)); }


	float getdataFloat(int i) const { return *((const float*)(this+1)-i); }



	virtual std::string str_A() const {
		std::stringstream ss;
		ss << "String A: " << a_s;
		return ss.str();
	}
};



class B : public A {
protected:
	std::string b_s;
	float data[7];
	friend void printInternals(const B&); // Дружественный метод класса
public:
	B() : b_s("It's b!") {
		for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
			data[i] = (float)i * 2;
	}

	virtual std::string str_B() {
		std::stringstream ss;
		ss << "String B: " << b_s << std::endl;
		ss << "Data : ";
		for (int i = 0;i < 7;i++) {
			ss << data[i] << "; ";
		}
		std::cout << std::endl;
		return ss.str();
	}

	/// <summary>
	/// Извлекает значение <see cref="B::b_s"/> из текущего объекта.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
	/// <returns>Значение B::b_s</returns>
	std::string getBString() const {
		//cerr << "\n1234" << "\n";
		return *((const std::string*)(this + 1));
	} //string 4 bytes

	void printData(std::ostream& os);

	void printData2(std::ostream& os);
};

/// <summary>
/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
/// с помощью виртуальных функций, предусмотренных в классе <see cref="A"/>.
/// </summary>
void B::printData2(std::ostream& os) {
	os << str_A();   // virtual function
	os << str_B();
}



/// <summary>
/// Выводит на экран адреса и размеры объекта типа <see cref="B"/> и его содержимого.
/// Можно модифицировать для собственных отладочных целей.
/// </summary>
/// <param name="b">Изучаемый объект</param>
void printInternals(B& b) { 
	const A* a = &b, *a2 = a + 1; // указатель А* сомтрит на объект производного класса
	std::cout << "umpa lumpa" << "\n";
	std::cout  << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x" << &b.b_s << std::endl;
	std::cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << std::endl;
	std::cout << "B string is '" << b.getBString() << "'" << std::endl;
	std::cout << "B data: "; b.printData(std::cout); std::cout << std::endl;
	std::cout << "B data: "; b.printData2(std::cout); std::cout << std::endl;
}


/// <summary>
	/// Извлекает значения <see cref="A::a_s"/>, <see cref="B::b_s"/> и <see cref="B::data"/>
	/// из текущего объекта и выводит их в текстовом виде в указанный выходной поток
	/// с помощью адресной арифметики.
	/// Подразумевается, что текущий объект на самом деле представлено классом <see cref="B"/>.
	/// </summary>
void B::printData(std::ostream & os)  {
		// TODO
		os << "A string is '" << a_s << "', B string is '" << getBString() << "'" << std::endl;
		for (int i = 0; i < 7; ++i) os << getdataFloat(i) << " ";
	}





