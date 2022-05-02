#include "newhacks.h"

Foo::Foo() : index(), name() { std::cerr << "constructed object Foo at " << this << std::endl; }
Foo::~Foo() { std::cerr << "destructed object Foo at " << this << std::endl; }

void *Foo::operator new(size_t size) {
    void *pVoid = std::malloc(size);
    std::cerr << "operator new(" << size << ") returns " << pVoid << std::endl;
    return pVoid;
}

void Foo::operator delete(void *pVoid) {
    std::cerr << "operator delete(" << pVoid << ")" << std::endl;
    std::free(pVoid);
}

Bar::Bar() : index(), prefix() { std::cerr << "constructed object Bar at " << this << std::endl; }
Bar::~Bar() { std::cerr << "destructed object Bar at " << this << std::endl; }

void *Bar::operator new(size_t size) {
    void *pVoid = std::malloc(size);
    std::cerr << "operator new(" << size << ") returns " << pVoid << std::endl;
    return pVoid;
}

void Bar::operator delete(void *pVoid) {
    std::cerr << "operator delete(" << pVoid << ")" << std::endl;
    std::free(pVoid);
}

Buz::Buz() : index(), value() { std::cerr << "constructed object Buz at " << this << std::endl; }
Buz::~Buz() { std::cerr << "destructed object Buz at " << this << std::endl; }

int main()
{
    Foo foo_stack = Foo();
    Bar bar_stack = Bar();
    Buz buz_stack = Buz();

    Foo* foo_heap = new Foo();
    Bar* bar_heap = new Bar();
    //Buz* buz_heap = new Buz(); - error

    delete(foo_heap);
    delete(bar_heap);
    //delete(buz_heap); - error
	return 0;
}
