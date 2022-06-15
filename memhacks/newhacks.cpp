#include <iostream>
#include <vector>
#include "newhacks.h"

using namespace std;
void printInfofoo(foo a)
{
    cerr << "foo: Creat object in stack in adress:" << &a << endl;
}
void printInfoBar(Bar a)
{
    cerr << "Bar: Creat object in stack in adress:" << &a << endl;
}
void printInfoBuz(Buz a)
{
    cerr << "Buz: Creat object in stack in adress:" << &a << endl;
}
void* foo::operator new(size_t size)
{
    typeof(malloc(size)) p = malloc(size);
    cerr << "foo: operator new(" << size << ") adress: " << p << endl;
    return p;
}
void foo::operator delete(void* p)
{
    free(p);
    cerr << "foo: operator delete(" << p << ")" << endl;
}

void* Bar::operator new(size_t size)
{
    typeof(malloc(size)) p = malloc(size);
    cerr << "Bar: operator new(" << size << ") adress: " << p << endl;
    return p;
}
void Bar::operator delete(void* p)
{
    free(p);
    cerr << "Bar: operator delete(" << p << ")" << endl;
}
void* Buz::operator new(size_t size)
{
    typeof(malloc(size)) p = malloc(size);
    cerr << "Buz: operator new(" << size << ") adress: " << p << endl;
    return p;
}
void Buz::operator delete(void* p)
{
    free(p);
    cerr << "Buz: operator delete(" << p << ")" << endl;
}
int main(){
    foo *obj1 = new foo;
    delete obj1;
    obj1 =new foo;
    delete obj1;
    Bar *obj2 = new Bar;
    delete obj2;
    obj2 = new Bar;
    delete obj2;
    
    foo obj12,obj13;
    printInfofoo(obj12);
    printInfofoo(obj13);
    Bar obj22,obj23;
    printInfoBar(obj22);
    printInfoBar(obj23);
    Buz obj32,obj33;
    printInfoBuz(obj32);
    printInfoBuz(obj33);
    return 0;
}