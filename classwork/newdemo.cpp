#include <iostream>
#include "newdemo.h"

using namespace std;

int Cls::next_id;

Cls::Cls()
    : id(++next_id)
{
    cerr << "constructed object #" << id << " at " << this << endl;
}

Cls::~Cls()
{
    cerr << "destructed object #" << id << " at " << this << endl;
}

void* Cls::operator new[](size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    cerr << "operator new[](" << size << ") returns " << p << endl;
    return p;
}

void Cls::operator delete[](void *p)
{
    cerr << "operator delete[](" << p << ")" << endl;
    free(p);    // ::operator delete(p);
}

Cls* DoSmth(size_t count) {
    return new Cls[count];
}

void FinishSmth(Cls *objs) {
    delete[] objs;
}

int main() {
    // testing new/delete
    Cls *obj = new Cls, *obj2 = new Cls;
    delete obj;
    delete obj2;
    obj = new Cls;
    obj2 = new Cls;
    delete obj2;
    delete obj;

    // testing new[]/delete[]
    Cls *objs = DoSmth(10);
    cerr << "Cls is " << sizeof(Cls) << " bytes size" << endl;
    cerr << "size_t is " << sizeof(size_t) << " bytes size" << endl;
    cerr << "working with " << objs << "..." << endl;
    FinishSmth(objs);

    return 0;
}
