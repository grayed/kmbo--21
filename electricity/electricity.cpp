#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (int i = 1; i <= getPoleCount(); i++) {
        for (int j = 1; j <= other.getPoleCount(); j++) {
            if (getPole(i)->connectedObjectPole == other.getPole(j)->name && getPole(i)->name != other.getPole(j)->name)
                return true;
        }
    }
    return false;
}

bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)
{
    if (poleName != otherPoleName) {
        for (int i = 1; i <= getPoleCount(); i++)
        {
            other.getPole(i)->connectedObjectPole = poleName; // strcpy()?
            //strcpy(other.getPole(i)->connectedObjectPole, poleName);
        }
        return true;
    }
    return false;
}

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

const Pole* Switch::getPole(size_t idx) const //
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
    
    Light svj1, svj2;
    svj1.connect("A2", svj2, "A1");
    cout << "is " << (svj1.isConnectedTo(svj2) ? "" : "not ") << "connected" << endl;
    
    // TODO: создать цепь из генератора, выключателя и светильника

    return 0;
}

const Pole* Light::getPole(const std::string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole* Light::getPole(size_t idx) const
{
    for (size_t i = 0; i < getPoleCount(); i++)
        if (i == idx) {
            return getPole(idx);
        }
    return nullptr;
}