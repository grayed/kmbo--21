#pragma once
#include <sys/types.h>

class Foo
{
    bool next_id;
    int id;

public:
    Foo();
    ~Foo();
    int getId() const {return id;}
    bool isNext_id() const {return next_id;}
    
    void setId(const int e) {id = e;}
    void setNext_id(const bool n) {next_id = n;}
    
    static void* operator new[](size_t size);
    static void operator delete[](void *p);   
};

class Bar : public Foo 
{
    public:
        Bar();
        ~Bar();

        static void* operator new[](size_t size);
        static void  operator delete[](void *p);
};

class Buz : public Foo 
{
    public:
        Buz();
        ~Buz();

        static void* operator new[](size_t size);
}; 
