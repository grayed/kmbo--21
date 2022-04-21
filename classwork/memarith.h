#include <string>

class A {
    std::string a_s;
    int foo;

    friend int main();  // for debugging display purposes

public:
    std::string getBString() const { return *((const std::string *)(this + 1)); }
    float getBData(int idx) const { return ((const float *)((const std::string *)(this + 1)))[idx]; }
};

class B : public A {
    std::string b_s;
    float data[7];

    friend int main();  // for debugging display purposes

public:
    B() { b_s = "It's b!"; }
};

// | class B
// | class A  | self   |
// | a_s; foo | b_s    |
// адрес b_s = адрес b плюс смещение b_s относительно начала b = адрес b плюс размер A
