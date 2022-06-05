#include <iostream>
#include "newhacks.h"

//1
void* Foo::operator new(size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    std::cerr << "operator new[] for Foo(" << size << ") returns " << p << std::endl;
    return p;
}

void Foo::operator delete(void *p)
{
    std::cerr << "operator delete for Foo(" << p << ")" << std::endl;
    free(p);    // ::operator delete(p);
}

//2
void* Bar::operator new(size_t size /* размер в байтах */)
{
    auto p = malloc(size);      // ::operator new(size);
    std::cerr << "operator new for Bar(" << size << ") returns " << p << std::endl;
    return p;
}

void Bar::operator delete(void *p)
{
    std::cerr << "operator delete for Bar(" << p << ")" << std::endl;
    free(p);    // ::operator delete(p);
}

//3
Foo::Foo() { std::cerr << "constructed object Foo" << " at " << this << std::endl;}
Foo::~Foo() { std::cerr << "deconstructed object Foo" << " at " << this << std::endl;}

Bar::Bar() { std::cerr << "constructed object Bar" << " at " << this << std::endl;}
Bar::~Bar() { std::cerr << "deconstructed object Bar" << " at " << this << std::endl;}

Buz::Buz() { std::cerr << "constructed object Buz" << " at " << this << std::endl;}
Buz::~Buz() { std::cerr << "deconstructed object Buz" << " at " << this << std::endl;}

//4
 void dynamicMemory() {
	Foo *obj1 = new Foo,  *obj2 = new Foo;
	delete obj1;
	delete obj2;

	Bar *obj3 = new Bar;
	delete obj3;
 }
 
 void stackMemory() {
	Foo obj1, obj2;
	Bar obj3;
 }

 //5
 void* Buz::operator new(size_t size /* размер в байтах */)
{
    throw std::runtime_error("It's a forbidden action");
}

int main()
{
	std::cout << "Explore dynamic memory" << std::endl;
 	dynamicMemory();

	std::cout << "Explore stack memory" << std::endl;
	stackMemory();

	Buz *b = new Buz;

	return 0;
}
