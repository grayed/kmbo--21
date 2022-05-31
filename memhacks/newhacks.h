#pragma once
#include <sys/types.h>

class Foo
{
    static int next_id;
    int id;

public:
    Foo();
    ~Foo();

    static void* operator new[](size_t size);
    static void  operator delete[](void* p);
};


class Buz: public Foo
{
    float *set;
protected:
    Buz();
    ~Buz();
};

class Bar : public Foo
{
    float *base;

public:
    Bar();
    ~Bar();

    static void* operator new[](size_t size);
    static void  operator delete[](void* p);
};