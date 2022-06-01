#include <iostream>
#include "memhacks.h"

B::B() : b_s("It's b!")
{
    for (auto i = 0; i < sizeof(data) / sizeof(data[0]); i++)
        data[i] = i * 2;
}

void printInternals(const B& b)
{
    const A* a = &b, * a2 = a + 1;
    std::cout << "Address of b is 0x" << &b << ", address of b.a_s is 0x" << &b.a_s << ", address of b.b_s is 0x"
              << &b.b_s << std::endl;
    std::cout << "Size of A is " << sizeof(A) << ", size of B is " << sizeof(B) << std::endl;
    std::cout << "B string is '" << b.getBString() << "'" << std::endl;
    //cout << "B data: "; b.printData(cout); cout << endl;
}

std::string B::getBStringV() const
{
    return b_s;
}

std::string A::getBString() const
{
    return *((const std::string*) (this + 1));
}

std::vector<float> B::getBDataV() const
{
    std::vector<float> vec;
    for (int i = 0; i < 7; ++i)
        vec.push_back(data[i]);
    return vec;
}

void A::printData(std::ostream& os)
{
    os << "a_s: " << a_s << " b_s: " << getBString() << " data[] = {";
    for (int i = 0; i < 7; ++i) {
        os << ((float*) ((std::string*) (this + 1) + 1))[i];
        if (i != 6)
            os << ", ";
    }
    os << "}";
}

void A::printData2(std::ostream& os)
{
    os << "a_s: " << a_s << " b_s: " << getBStringV() << " data[] = {";
    auto vec = getBDataV();
    for (auto& i: vec) {
        os << i;
        if (&i != &vec.back())
            os << ", ";
    }
    os << "}";
}

int main()
{
    B b;
    printInternals(b);
    std::cout << "\n\n";
    b.printData(std::cout);
    std::cout << "\n\n";
    b.printData2(std::cout);
    return 0;
}