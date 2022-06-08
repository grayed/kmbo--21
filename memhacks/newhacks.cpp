#include <iostream>
#include "newhacks.h"
#include "memhacks.h"

using namespace std;

// 1 пункт
void* Foo::operator new(size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    cerr << "operator new[] for Foo(" << size << ") returns " << p << endl;
    return p;
}

void Foo::operator delete(void* p)
{
    cerr << "operator delete for Foo(" << p << ")" << endl;
    free(p);    // ::operator delete(p);
}

// 2 пункт
void* Bar::operator new(size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    cerr << "operator new for Bar(" << size << ") returns " << p << endl;
    return p;
}

void Bar::operator delete(void* p)
{
    cerr << "operator delete for Bar(" << p << ")" << endl;
    free(p);    // ::operator delete(p);
}

// 3 пункт
Foo::Foo() { cerr << "constructed object Foo" << " at " << this << endl; }
Foo::~Foo() { cerr << "deconstructed object Foo" << " at " << this << endl; }

Bar::Bar() { cerr << "constructed object Bar" << " at " << this << endl; }
Bar::~Bar() { cerr << "deconstructed object Bar" << " at " << this << endl; }

Buz::Buz() { cerr << "constructed object Buz" << " at " << this << endl; }
Buz::~Buz() { cerr << "deconstructed object Buz" << " at " << this << endl; }

// 4 пункт
void dynamicMemory() {
    Foo* obj1 = new Foo, * obj2 = new Foo;
    delete obj1;
    delete obj2;

    Bar* obj3 = new Bar;
    delete obj3;
}

void stackMemory() {
    Foo obj1, obj2;
    Bar obj3;
}

// 5 пункт
void* Buz::operator new(size_t size /* размер в байтах */)
{
    throw runtime_error("It's a forbidden action");
}


int main()
{
    cout << "Explore dynamic memory" << endl;
    dynamicMemory();

    cout << "Explore stack memory" << endl;
    stackMemory();

    Buz* b = new Buz;

    return 0;
}
