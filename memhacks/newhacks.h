#pragma once

#include <iostream>
#include <string>
#include <sys/types.h>
#include <string>


class foo
{
   int x;
   std:: string str="Hello world";
public:
   static void* operator new (size_t size);
   static void operator delete (void *p);
};

class Bar : foo
{
   char data[20];
   bool t;
public:
   static void* operator new (size_t size);
   static void operator delete (void *p);
};
class Buz : foo
{
   double y;
   float b;
public:
   static void operator delete (void *p);
private:
   static void* operator new (size_t size);
};