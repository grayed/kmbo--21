#include "newhacks.h"

using namespace std;

Foo::Foo() {
	str = "My name is Ilya!!!";
	value = 18;

	cout << str << endl << "I am " << value << " years old!!!";
}

Foo::~Foo() {
	cout << "Foo destructor!!!" << endl;
}

void* Foo::operator new(size_t size) {
	auto foo = malloc(size);
	cerr << "Foo operator size: " << size << "; Foo operator address: " << foo << endl;
	return foo;
}

void Foo::operator delete(void* foo) {
	free(foo);
	cerr << "Foo operator was deleted" << endl;
}

Bar::Bar() {
	cout << "Bar constructor!!!" << endl;
}

Bar::~Bar() {
	cout << "Bar destructor!!!" << endl;
}

void* Bar::operator new(size_t size) {
	auto bar = malloc(size);
	cerr << "Foo operator size: " << size << "; Foo operator address: " << bar << endl;
	return bar;
}

void Bar::operator delete(void* bar) {
	free(bar);
	cerr << "Foo operator was deleted" << endl;
}

Buz::Buz() {
	cout << "Buz constructor!!!" << endl;
}

Buz::~Buz() {
	cout << "Buz destructor!!!" << endl;
}

int main()
{
	// объявление объектов в динамической памяти
	Foo* foo = new Foo;
	delete foo;
	Bar* bar = new Bar;
	delete bar;
	// Buz* buz = new Buz;  объявление Buz в динамической памяти запрещено

	// объявление объектов в стэке
	cout << "Foo:" << endl;
	Foo foo1;
	cout << "Bar:" << endl;
	Bar bar1;
	cout << "Buz:" << endl;
	Buz buz1;

	return 0;
}
