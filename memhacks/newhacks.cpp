#include <iostream>
#include "newhacks.h"
using namespace std;

Foo::Foo() : student(), pupil() { cerr << "Вызван конструктор " << this << endl; }
Foo::~Foo() { cerr << "Вызван деструктор " << this << endl; }
void* Foo::operator new(size_t size) {
    void* pVoid = malloc(size);
    cerr << "Выполняется оператор new(" << size << ") returns " << pVoid << endl;
    return pVoid;
}
void Foo::operator delete(void* memory) {
    cerr << "Выполняется оператор delete(" << memory << ")" << endl;
    free(memory);
}
Bar::Bar() : clever(), stupid() { cerr << "Вызван конструктор " << this << endl; }
Bar::~Bar() { cerr << "Вызван деструктор" << this << endl; }
void* Bar::operator new(size_t size) {
    void* pVoid = malloc(size);
    cerr << "Выполняется оператор new(" << size << ") returns " << pVoid << endl;
    return pVoid;
}
void Bar::operator delete(void* memory) {
    cerr << "Выполняется оператор delete(" << memory << ")" << endl;
    free(memory);
}
Buz::Buz() : poltorashka(), shpala() { cerr << "Вызван конструктор" << this << endl; }
Buz::~Buz() { cerr << "Вызван деструктор" << this << endl; }

int main()
{
    setlocale(LC_ALL, "Russian");
    Foo foo_test = Foo();
    Bar bar_test = Bar();
    Buz buz_test = Buz();
    Foo* foo_test2 = new Foo();
    Bar* bar_test2 = new Bar();
    delete(foo_test2);
    delete(bar_test2);
    return 0;
}