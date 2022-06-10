#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (int i = 0; i < getPoleCount(); ++i) {
        for (int j = 0; j < other.getPoleCount(); ++j) {
            if (getPole(i)->connectedObjectPole == other.getPole(j)->name && getPole(i)->connectedObject == const_cast<Object*>(&other))
                return true;
        }
    }
    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    Pole* myPole = getPole(poleName);
    Pole* otherPole = other.getPole(otherPoleName);

    if (!myPole || !otherPole) return false;

    myPole->connectedObject = const_cast<Object*>(&other);
    myPole->connectedObjectPole = otherPoleName;

    otherPole->connectedObject = this;
    otherPole->connectedObjectPole = poleName;

    return true;
}

bool Object::disconnect(const std::string& poleName)
{
    // TODO
    return false;
}

Switch::Switch(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{
}

const Pole* Switch::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole* Switch::getPole(size_t idx) const
{
    switch (idx) {
    case 0:
        return &a1;
    case 1:
        return &a2;
    default:
        return nullptr; 
    }
}

const Pole* Generator::getPole(const std::string &name) const {
    if (name == p1.name)
        return &p1;
    if (name == p2.name)
        return &p2;
    if (name == p3.name)
        return &p3;
    return nullptr;
}

const Pole* Generator::getPole(size_t idx) const
{
    switch (idx) {
    case 0:
        return &p1;
    case 1:
        return &p2;
    case 2:
        return &p3;
    default:
        return nullptr; 
    }
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    // TODO: создать цепь из генератора, выключателя и светильника
    Generator g;
    Switch s;
    Light l;

    cout << g.connect("P1", s, "A1") << endl;
    cout << s.connect("A2", l, "A1") << endl;

    return 0;
}
