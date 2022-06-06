#pragma once
#include <iostream>
using namespace std;
class Foo {
    int student;
    double pupil;
public:
    Foo();
    ~Foo();
    static void* operator new(size_t size);
    static void operator delete(void* memory);
};

class Bar : public Foo {
    int clever;
    string stupid;

public:
    Bar();
    ~Bar();

    static void* operator new(size_t size);
    static void operator delete(void* memory);
};

class Buz : public Foo {
    long poltorashka;
    long long shpala;

public:
    Buz();
    ~Buz();

    static void* operator new(size_t size) = delete;
    static void operator delete(void* memory) = delete;
};
