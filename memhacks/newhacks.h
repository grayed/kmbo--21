#pragma once
#include <iostream>
#include <string>
#include <sys/types.h>
#include <vector>

using namespace std;

class Foo {
	string str;
	int x;
public: 
	Foo(){
		str = "It's Foo string!";
		int x = 7;
		cout << "Foo Constructor" << "\n";
	}
	~Foo() {
		cout << "Foo Destructor worked" << "\n";
	}

	void* operator new(size_t size) {
		auto s = malloc(size); 
		cerr << "Foo: operator new(" << size << ") adress: " << s << endl;
		return s;
	}

	void operator delete(void* s) {
		free(s);
		cerr << "Foo: operator delete(" << s << ")" << endl;
	}

	virtual void show_adress()
	{
		cout << "Creat object Foo by adress:" << this << endl; 
	}
};


class Bar : public Foo {
	char data[10];
	double value;
public: 
	Bar() {
		cout << "Bar Constructor" << "\n";
	}

	~Bar() {
		cout << "Bar Destructor worked" << "\n";
	}
	void* operator new (size_t size) {
		auto s = malloc(size);
		cerr << "Bar: operator new(" << size << ") adress: " << s << endl;
		return s;
	}

	void operator delete(void *v) {
		free(v);
		cerr << "Bar: operator delete(" << v << ")" << endl;
	}

	void show_adress()
	{
		cout << "Creat object Bar  by adress:" << this << endl;
	}
};


class Buz : public Foo{
	char data[10];
	string str;
protected:
	void* operator new(size_t size) {
		auto p = malloc(size);
		cerr << "Buz: operator new(" << size << ") adress: " << p << endl;
		return p;
	}
public:
	Buz() {
		cout << "Buz Constructor" << "\n";
	}
	~Buz() {
		cout << "Buz Destructor worked" << "\n";
	}
	void operator delete(void *s) {
		free(s);
		cout << "Buz: operator delete(" << s << ")" << endl;
	}


	void show_adress()
	{
		cout << "Creat object Buz by adress:" << this << endl;
	}
};