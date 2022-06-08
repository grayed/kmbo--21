#pragma once

#include <iostream>

class Foo {
    int index {};
    std::string name {};
public:
    Foo();
    ~Foo();

    static void *operator new(size_t size);
    static void operator delete(void *pVoid);
};

class Bar : public Foo {
    int index {};
    char prefix {};

public:
    Bar();
    ~Bar();

    static void *operator new(size_t size);
    static void operator delete(void *pVoid);
};

class Buz : public Foo {
    int index;
    float value;

public:
    Buz();
    ~Buz();

    static void *operator new(size_t size) = delete;
    static void operator delete(void *pVoid) = delete;
};