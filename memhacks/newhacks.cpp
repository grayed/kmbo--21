#include <iostream>
#include "newhacks.h"

using namespace std;

Foo::Foo() : cat(), frog() { cerr << "constructed object Foo at " << this << endl; }
Foo::~Foo() { cerr << "destructed object Foo at " << this << endl; }

void *Foo::operator new(size_t size) {
    void *pVoid = malloc(size);
    cerr << "operator new(" << size << ") returns " << pVoid << endl;
    return pVoid;
}

void Foo::operator delete(void *pVoid) {
    cerr << "operator delete(" << pVoid << ")" << endl;
    free(pVoid);
}

Bar::Bar() : turtle(), dog() { cerr << "constructed object Bar at " << this << endl; }
Bar::~Bar() { cerr << "destructed object Bar at " << this << endl; }

void *Bar::operator new(size_t size) {
    void *pVoid = malloc(size);
    cerr << "operator new(" << size << ") returns " << pVoid << endl;
    return pVoid;
}

void Bar::operator delete(void *pVoid) {
    cerr << "operator delete(" << pVoid << ")" << endl;
    free(pVoid);
}

Buz::Buz() : snake(), rhinoceros() { cerr << "constructed object Buz at " << this << endl; }
Buz::~Buz() { cerr << "destructed object Buz at " << this << endl; }

int main()
{
    Foo foo_stack = Foo();
    Bar bar_stack = Bar();
    Buz buz_stack = Buz();

    Foo* foo_heap = new Foo();
    Bar* bar_heap = new Bar();
    //Buz* buz_heap = new Buz(); => Error

    delete(foo_heap);
    delete(bar_heap);
    //delete(buz_heap); => Error
	return 0;
}