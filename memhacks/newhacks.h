﻿#pragma once

#include <sys/types.h>

using namespace std;

class Foo {
    int cost;
    bool fixed;

public:

    Foo();
    ~Foo();

    int getCost() const { return cost; }
    bool isFixed() const { return fixed; }

    void setCost(const int c) { cost = c; }
    void setFixed(const bool f) { fixed = f; }

    static void* operator new(size_t size);
    static void  operator delete(void* p);
};

class Bar : public Foo {
public:
    Bar();
    ~Bar();

    static void* operator new(size_t size);
    static void  operator delete(void* p);
};

class Buz : public Foo {
public:
    Buz();
    ~Buz();
    static void* operator new(size_t size);
};

void* Foo::operator new(size_t size /* размер в байтах */)
{
    auto p = std::malloc(size);      // ::operator new(size);
    cerr<< "operator new[] for Foo(" << size << ") returns " << p << endl;
    return p;
}

void Foo::operator delete(void* p)
{
    cerr<< "operator delete for Foo(" << p << ")" << endl;
    free(p);    // ::operator delete(p);
}


void* Bar::operator new(size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    cerr << "operator new for Bar(" << size << ") returns " << p << endl;
    return p;
}

void Bar::operator delete(void* p)
{
    cerr<< "operator delete for Bar(" << p << ")" << endl;
    free(p);    // ::operator delete(p);
}


Foo::Foo() { cerr<< "constructed object Foo" << " at " << this << endl; }
Foo::~Foo() { cerr<< "deconstructed object Foo" << " at " << this << endl; }

Bar::Bar() { cerr<< "constructed object Bar" << " at " << this << endl; }
Bar::~Bar() { cerr<< "deconstructed object Bar" << " at " << this << endl; }

Buz::Buz() { cerr<< "constructed object Buz" << " at " << this << endl; }
Buz::~Buz() { cerr<< "deconstructed object Buz" << " at " << this << endl; }

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

void* Buz::operator new(size_t size /* размер в байтах */)
{
    throw runtime_error("It's a forbidden action");
}
