#include <iostream>
#include "newhacks.h"

using namespace std;

//Создание объектов классов на стеке
void testStack() {
	Foo x;
	Bar y;
	Buz z;
}

void testDynamic_memory() {
	Foo* a = new Foo;
	delete(a);
	Bar* b = new Bar;
	delete(b);
	/* 
	Buz* c = new Buz;
	delete(c);
	Ошибка, т.к. перегруженные операторы new и delete приватные
	*/
}

int main()
{
	testStack();
	testDynamic_memory();
	return 0;
}
