#include <iostream>
#pragma once

class Foo {
    std::string str;
    int i;

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
