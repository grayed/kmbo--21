#include <iostream>
using namespace std;

class A {
    string a_s;
    friend int main();
public:
    string getBString() const { /* TODO: return B::b_s value */; }
};
class B : public A {
    string b_s;
    friend int main();
public:
    B() { b_s = "It's b!"; }
};

int main()
{
    B b;
    A *a = &b;
    cout << "b address is " << &b << ", a_s address is " << &b.a_s << ", b_s address is " << &b.b_s << endl;
    cout << "b size is " << sizeof(b) << ", a_s size is " << sizeof(b.a_s) << endl;
    cout << "b_s is '" << a->getBString() << "'" << endl;
	return 0;
}
