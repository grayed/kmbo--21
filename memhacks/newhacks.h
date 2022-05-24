#pragma once

class Foo
{
public:
    Foo();

    ~Foo();

    static void* operator new(size_t size);

    static void* operator new[](size_t size);

    static void operator delete(void* p);

    static void operator delete[](void* p);

private:
    inline static uint32_t _lastId = 0;
    uint32_t _id;
    float _data;
};

class Bar : public Foo
{
public:
    Bar();

    ~Bar();

    static void* operator new(size_t size);

    static void* operator new[](size_t size);

    static void operator delete(void* p);

    static void operator delete[](void* p);
};

class Buz : public Foo
{
public:
    Buz();

    ~Buz();

    static void* operator new(size_t size) = delete;

    static void* operator new[](size_t size) = delete;

    static void operator delete(void* p) = delete;

    static void operator delete[](void* p) = delete;
};