#include <iostream>
#include "newhacks.h"

using namespace std;

int Foo::next_id;

Foo::Foo()
    : id(++next_id)
{
    cerr << "create object ---> " << id << " at " << this << endl;
}

Foo::~Foo()
{
    cerr << "delete object ---> " << id << " at " << this << endl;
}




void* Foo::operator new[](size_t size)
{
    auto p = malloc(size);      
    cerr << "operator new[](" << size << ") returns " << p << endl;
    return p;
}

void Foo::operator delete[](void* p)
{
    cerr << "operator delete[](" << p << ")" << endl;
    free(p);    
}

Foo* create_foo(size_t count) {
    return new Foo[count];
}

void destruction_foo(Foo* objs) {
    delete[] objs;
}


Bar::Bar()
    :Foo()
{
    base = new float(2);
}

Bar::~Bar()
    
{
    delete base;
}

Buz::Buz()
    :Foo()
{
    set = new float(2);
}

Buz::~Buz()

{
    delete set;
}

void* Bar::operator new[](size_t size)
{
    auto p = malloc(size);
    cerr << "operator new[](" << size << ") returns " << p << endl;
    return p;
}

void Bar::operator delete[](void* p)
{
    cerr << "operator delete[](" << p << ")" << endl;
    free(p);
}

int main() {
    cerr << ". . . start executing . . ." << endl;
    //Foo
    Foo* obj = new Foo, * obj2 = new Foo; 
    delete obj;
    delete obj2;
    obj = new Foo; 
    obj2 = new Foo;
    delete obj2;
    delete obj;

    //Bar
    Bar* obj11 = new Bar, * obj22 = new Bar;
    delete obj11;
    delete obj22;
    obj11 = new Bar;
    obj22 = new Bar;
    delete obj22;
    delete obj11;



    

    return 0;
}