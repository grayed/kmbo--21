#include <iostream>
#include "newhacks.h"

using namespace std;

Foo::Foo(): apples("Apples"){
	n = 10;
    cerr << "Foo object is constructed " << apples << " at " << this << endl;
}
Foo::~Foo(){
    cerr << "Foo object is destructed " << apples << " at " << this << endl;
}
void* Foo::operator new[](size_t size /* размер в байтах */){
    auto p = malloc(size);      // ::operator new(size);
    cerr << "Foo's operator new[](" << size << ") " << " works " << "and returns " << p << endl;
    return p;
}
void Foo::operator delete[](void *p){
    cerr << "Foo operator delete[](" << p << ")" << " works" << endl;
    free(p);    // ::operator delete(p);
}



Bar::Bar(): oranges("Oranges"){
		kg = 3.5;
    cerr << "Bar object is constructed " << oranges << " at " << this << endl;
}
Bar::~Bar(){
    cerr << "Bar object is destructed " << oranges << " at " << this << endl;
}
void* Bar::operator new[](size_t size /* размер в байтах */){
    auto p = malloc(size);      // ::operator new(size);
    cerr << "Bar's operator new[](" << size << ") " << " works " << "and returns " << p << endl;
    return p;
}
void Bar::operator delete[](void *p){
    cerr << "Bar's operator delete[](" << p << ")" << " works" << endl;
    free(p);    // ::operator delete(p);
}


Buz::Buz(): bananas("Bananas"){
		ripe = true;
    cerr << "Buz object is constructed " << bananas << " at " << this << endl;
}

Buz::~Buz(){
    cerr << "Buz object is destructed " << bananas << " at " << this << endl;
}



int main()
{
	//на стеке
	Foo apls1,apls2;
	Bar orng1,orng2;//вызывается также конструктор и диструктор родительского класса
	Buz bnns1,bnns2;//вызывается также конструктор и диструктор родительского класса
	//диструктор вызвается в после исполнения программы
	cout << '\n';
	//в динамической памяти
	Foo *apple1 = new Foo;
	delete apple1;
	Bar *orange1 = new Bar; //вызывается оператор new - родттельского класса ---> оператор new наследника
	delete orange1; //вызывается оператор оператор delete наследника --->  оператор delete - родттельского класса

	//Buz *bananas1 = new Buz;// запретили создание в динамической памяти
	//delete bananas1;
	cout << '\n';
	//общее то что при уничтожении наследни --> родитель
	//при создании родитель --> наследник
	Foo *apples2 = new Foo[4]; //происходит последовательный вызов конструктора
	delete apples2; // последовательный вызов диструктора
	Bar *oranges2 = new Bar[4];
	delete oranges2;
	//Buz *bananas2 = new Buz[4]; - не перегружали
	//delete bananas2;
	cout << '\n';
	return 0;
}
