#pragma once
#include <string>
#include <sys/types.h>


class Foo
{
    std::string apples;
    int n;

public:
    Foo();
    ~Foo();

    static void* operator new[](size_t size);
    static void operator delete[](void *p);
};

class Bar : public Foo{
  std::string oranges;
  float kg;

public:
  Bar();
  ~Bar();

  static void* operator new[](size_t size);
  static void operator delete[](void *p);
};

class Buz : public Foo{
  std::string bananas;
  bool ripe;
  static void* operator new[](size_t size);
  static void* operator new(size_t size);
public:
  Buz();
  ~Buz();

  static void operator delete[](void *p);
};
