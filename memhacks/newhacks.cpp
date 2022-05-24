#include <iostream>
#include "newhacks.h"

Foo::Foo() : _id(++_lastId), _data(42.f)
{
    std::cerr << "constructed object #" << _id << " at " << this << std::endl;
}

Foo::~Foo()
{
    std::cerr << "destructed object #" << _id << " at " << this << std::endl;
}

void* Foo::operator new(size_t size)
{
    auto p = malloc(size);
    std::cerr << "operator new(" << size << ") returns " << p << std::endl;
    return p;
}

void* Foo::operator new[](size_t size)
{
    auto p = malloc(size);
    std::cerr << "operator new[](" << size << ") returns " << p << std::endl;
    return p;
}

void Foo::operator delete(void* p)
{
    std::cerr << "operator delete(" << p << ")" << std::endl;
    free(p);
}

void Foo::operator delete[](void* p)
{
    std::cerr << "operator delete[](" << p << ")" << std::endl;
    free(p);
}

Bar::Bar()
{
    std::cerr << "Bar constructor" << std::endl;
}

Bar::~Bar()
{
    std::cerr << "Bar destructor" << std::endl;
}

void* Bar::operator new(size_t size)
{
    auto p = malloc(size);
    std::cerr << "operator new(" << size << ") returns " << p << " but this is Bar" << std::endl;
    return p;
}

void* Bar::operator new[](size_t size)
{
    auto p = malloc(size);
    std::cerr << "operator new[](" << size << ") returns " << p << " but this is Bar" << std::endl;
    return p;
}

void Bar::operator delete(void* p)
{
    std::cerr << "operator delete(" << p << ") but this is Bar" << std::endl;
    free(p);
}

void Bar::operator delete[](void* p)
{
    std::cerr << "operator delete[](" << p << ") but this is Bar" << std::endl;
    free(p);
}

Buz::Buz()
{
    std::cerr << "Buz constructor" << std::endl;
}

Buz::~Buz()
{
    std::cerr << "Buz destructor" << std::endl;
}

int main()
{
    // Foo
    {
        Foo foo;
        Foo* foo1 = new Foo;
        delete foo1;
        Foo* foo2 = new Foo[2];
        delete[] foo2;
    }
    std::cerr << std::endl;

    // Bar
    {
        Bar bar;
        Bar* bar1 = new Bar;
        delete bar1;
        Bar* bar2 = new Bar[2];
        delete[] bar2;
    }
    std::cerr << std::endl;

    // Buz
    {
        Buz buz;
#if 0
        // This will not compile
        Buz* buz1 = new Buz;
        delete buz1;
        Buz* buz2 = new Buz[2];
        delete[] buz2;
#endif
    }
}