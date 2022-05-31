#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (size_t j = 0; j < getPoleCount(); j++)
    {
        const Pole * selfPole = getPole(j);
        if (selfPole != nullptr && (selfPole->connectedObject) == &other) return true;
    }   

    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    if (poleName == otherPoleName && &other == this) return false;

    Pole * selfPole = getPole(poleName);
    Pole * otherPole = other.getPole(otherPoleName);
    if (otherPole == nullptr || otherPole == nullptr) return false;

    (selfPole->connectedObject) = &other;
    (selfPole->connectedObjectPole) = otherPoleName;
    
    (otherPole->connectedObject) = this;
    (otherPole->connectedObjectPole) = poleName;

    return true;
}

bool Object::disconnect(const std::string& poleName)
{
    Pole * p = getPole(poleName);
    if (p == nullptr) return false;

    (p->connectedObject) = nullptr;
    (p->connectedObjectPole) = "";
    
    return true;
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
    if (idx == 0) return &a1;
    else if (idx == 1) return &a2;
    return nullptr;
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    // TODO: создать цепь из генератора, выключателя и светильника
    Generator g; Light l; Switch sw3;

    g.connect("p", l, "A1");
    l.connect("A2", sw3, "A1");
    cout << "is " << (g.isConnectedTo(l) ? "" : "not ") << "connected" << endl;
    cout << "is " << (l.isConnectedTo(sw3) ? "" : "not ") << "connected" << endl;

    g.disconnect("p");
    cout << "is " << (g.isConnectedTo(l) ? "" : "not ") << "connected" << endl;

    return 0;
}
