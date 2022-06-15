#include <iostream>
#include "newhacks.h"

using namespace std;

void* Foo:: operator new[](size_t size)
{
    auto p = ::operator new(size);
    cerr<<"operator new[](" << size << ") returns" << p << endl;
    return p;
}

void Foo:: operator delete[](void *p)
{
    cerr<<"operator delete[](" << p << ")" << endl;
    ::operator delete(p);
}

void* Bar:: operator new[](size_t size)
{
    auto p = ::operator new(size);
    cerr<<"operator new[](" << size << ") returns" << p << endl;
    return p;
}

void Bar:: operator delete[](void *p)
{
    cerr<<"operator delete[](" << p << ")" << endl;
    ::operator delete(p);
}

Foo::Foo() {cerr << "constructed Foo" << " at " << this << endl;}
Foo::~Foo() {cerr << "deconstructed Foo" << " at " << this << endl;}

Bar::Bar() {cerr << "constructed Bar" << " at " << this << endl;}
Bar::~Bar() {cerr << "deconstructed Bar" << " at " << this << endl;}

Buz::Buz() {cerr << "constructed Buz" << " at " << this << endl;}
Buz::~Buz() {cerr << "deconstructed Buz" << " at " << this << endl;}

void dMemory() 
{
	Foo *obj_1 = new Foo,  *obj_2 = new Foo;
	delete obj_1;
	delete obj_2;

	Bar *obj_3 = new Bar;
	delete obj_3;
 }

 void sMemory() 
 {
	Foo obj_1, obj_2;
	Bar obj_3;
 }

 void* Buz::operator new[](size_t size)
{
    throw runtime_error("The action banned");
}

int main()
{
    cout<< "Research of dynamic memory" << endl;
    dMemory();
    cout<< "Research of stack memory" << endl;
    sMemory();
    Buz *b = new Buz;
    return 0;
}



