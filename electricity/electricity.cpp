#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    if (other.getPoleCount() > 1) {
        return true;
    }
    else{
        return false;
    }
}

struct Pole {
    string name;
    Object *connectedObject;
    string connectedObjectPole;

    Pole(const string &name_) : name(name_), connectedObject(nullptr) {}
};

class Object {
    string name;

protected:
    Object(const string &name_) : name(name_) {}
    Pole* getPole(size_t idx) { /*TODO*/ return nullptr; }
    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}
    Pole* getPole(const string &name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }
    virtual const Pole* getPole(const string &name) const = 0;
    virtual size_t getPoleCount() const = 0;
    bool isConnectedTo(const Object &other) const { /* TODO */ return false; }
    void connect(const string &poleName, const Object &other, const string &otherPoleName) { /* TODO */ }
};

const Pole* Switch::getPole(size_t idx) const
{
    for (size_t i = 0; i < getPoleCount();i++)
        if (i==idx) {
            return getPole(idx);
        }
    return nullptr;
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;
    return 0;
}

//Power::Power(const std::string& name)

