#include <iostream>
#include "newhacks.h"

using namespace std;


Foo::Foo() { cerr << "constructed object Foo at " << this << endl; }
Foo::~Foo() { cerr << "deconstructed object Foo at " << this << endl; }
void* Foo::operator new(size_t size) {
    auto p = malloc(size);
    cerr << "operator new(" << size << ") returns " << p << endl;
    return p;
}
void  Foo::operator delete(void* p) {
    cerr << "operator delete(" << p << ")" << endl;;
    free(p);
}



Bar::Bar() { cerr << "constructed object Bar at " << this << endl; }
Bar::~Bar() { cerr << "deconstructed object Bar at " << this << endl; }
void* Bar ::operator new(size_t size) {
    auto p = malloc(size);
    cerr << "operator new(" << size << ") returns " << p << endl;
    return p;
}
void  Bar ::operator delete(void* p) {
    cerr << "operator delete(" << p << ")" << endl;;
    free(p);
}


Buz::Buz() { cerr << "constructed object Buz at " << this << endl; }
Buz::~Buz() { cerr << "deconstructed object Buz at " << this << endl; }
void* Buz ::operator new(size_t size) {
    throw runtime_error("Buz object in dynamic memory");
}



int main()
{
    cout << "Dynamic memory:" << endl;

    auto example1 = new Foo;
    delete example1;

    auto example2 = new Bar;
    delete example2;

    auto example3 = new Bar;
    delete example3;

    //auto example8 = new Buz;

    cout << "Stack:" << endl;
    Foo example4;
    Foo example5;

    Bar example6;

    Buz example7;
}