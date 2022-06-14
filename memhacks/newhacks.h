#pragma once

#include <iostream>

using namespace std;

class Foo {
    string str;
    int value;

public:
    Foo();
    ~Foo();

    void* operator new(size_t size);
    void operator delete(void* foo);
};

class Bar : public Foo {
public: 
    Bar();
    ~Bar();

    void* operator new(size_t size);
    void operator delete(void* bar);
};

class Buz : public Foo {
    void* operator new(size_t size);

public:
    Buz();
    ~Buz();
};