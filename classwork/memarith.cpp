#include <iostream>
#include "memarith.h"

using namespace std;

int main()
{
    B b;
    A *a = &b;
    cout << "b address is " << &b << ", a_s address is " << &b.a_s << ", b_s address is " << &b.b_s << endl;
    cout << "b size is " << sizeof(b) << ", a_s size is " << sizeof(b.a_s) << endl;
    cout << "b_s is '" << a->getBString() << "'" << endl;
    return 0;
}
