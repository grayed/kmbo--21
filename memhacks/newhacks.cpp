#include <iostream>
#include "newhacks.h"

using namespace std;

Foo::Foo() {
	str = "It's Foo string";
	i = 2;

	cout << "Foo constructer" << endl;
}

Foo::~Foo() {
	cout << "Foo destructor" << endl;
}

void* Foo::operator new(size_t size) {
	auto foo = malloc(size);
	cerr << "Foo object was created, size = " << size << " , address = " << foo << endl;
	return foo;
}

void Foo::operator delete(void* foo) {
	free(foo);
	cerr << "Foo object was deleted" << endl;
}

Bar::Bar() {
	cout << "Bar constructer" << endl;
}

Bar::~Bar() {
	cout << "Bar destructor" << endl;
}

void* Bar::operator new(size_t size) {
	auto bar = malloc(size);
	cerr << "Bar object was created, size = " << size << ", address = " << bar << endl;
	return bar;
}

void Bar::operator delete(void* bar) {
	free(bar);
	cerr << "Bar object was deleted";
}

Buz::Buz() {
	cout << "Buz constructer" << endl;
}

Buz::~Buz() {
	cout << "Buz destructor" << endl;
}

int main()
{
	cout << "стек" << endl << endl;
	cout << "Foo:" << endl;
	Foo foo1;
	cout << endl;

	cout << "Bar:" << endl;
	Bar bar1;
	cout << endl;

	cout << "Buz:" << endl;
	Buz buz1;
	cout << endl << endl;

	

	cout << "куча" << endl << endl;

	cout << "Foo:" << endl;
	Foo *foo2 = new Foo();
	cout << endl;

	cout << "Bar:" << endl;
	Bar *bar2 = new Bar();
	cout << endl;
	// Buz *buz2 = new Buz(); объявление Buz в динамической памяти запрещено

	return 0;
}
