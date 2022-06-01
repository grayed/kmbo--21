#pragma once

#include <iostream>

class Foo {
    int cat;
    float frog;
public:
    Foo();
    ~Foo();

    static void *operator new(size_t size);
    static void operator delete(void *pVoid);
};

class Bar : public Foo {
    int turtle;
    std::string dog;

public:
    Bar();
    ~Bar();

    static void *operator new(size_t size);
    static void operator delete(void *pVoid);
};

class Buz : public Foo {
    float snake;
    short rhinoceros;

public:
    Buz();
    ~Buz();

    static void *operator new(size_t size) = delete;
    static void operator delete(void *pVoid) = delete;
};