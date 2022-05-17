#pragma once

#include <sys/types.h>

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
        static void  operator delete(void *p);
};

class Bar : public Foo {
    public:
        Bar();
        ~Bar();

        static void* operator new(size_t size);
        static void  operator delete(void *p);
};

class Buz : public Foo {
    public:
        Buz();
        ~Buz();
        static void* operator new(size_t size);
};