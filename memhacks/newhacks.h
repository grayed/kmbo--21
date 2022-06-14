#pragma once

#include <sys/types.h>
#include <cstdlib>
#include <iostream>

class Foo {
    int id;
    char a{};
public:
    Foo(int a = 0, char b = ' ') {
        std::cout << "Default constructor Foo:\n";
        id = a;
        a = b;
    };

    ~Foo() {
        std::cout << "Default destructor Foo:\n";
    };

    int get_id() const { return id; }

    char get_char() const { return a; }

    static void *operator new(size_t size) {
        std::cout << "Operator new for Foo:\n";
        auto m = malloc(size);
        return m;
    };

    static void operator delete(void *m) {
        std::cout << "Operator delete for Foo:\n";
        free(m);
    };
};

class Bar : public Foo {
    int id1;
public:
    Bar(int a = 0) {
        std::cout << "Default constructor for Bar:\n";
        id1 = a;
    };

    ~Bar() {
        std::cout << "Default destructor for Bar:\n";
    };

    static void *operator new(size_t size) {
        std::cout << "Operator new for Bar:\n";
        auto m = malloc(size);
        return m;
    };

    static void operator delete(void *m) {
        std::cout << "Operator delete for Bar:\n";
        free(m);
    };
};

class Buz : public Foo {
    int id2;
public:
    Buz(int a = 0) {
        std::cout << "Default constructor for Buz:\n";
        id2 = a;
    };

    ~Buz() {
        std::cout << "Default destructor for Buz:\n";
    };
    static void *operator new(size_t size) {
        std::cout << "Operator new for Buz:\n";
        auto m = malloc(size);
        return m;
    };

    static void operator delete(void *m) {
        std::cout << "Operator delete for Buz:\n";
        free(m);
    };
};