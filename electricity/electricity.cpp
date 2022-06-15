#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (int i = 0; i < getPoleCount(); i++) {
        for (int j = 0; j < other.getPoleCount(); j++) {
            if (getPole(i)->connectedObjectPole == other.getPole(j)->name && getPole(i)->connectedObject == const_cast<Object*>(&other))
                return true;
        }
    }
    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    if (poleName == otherPoleName && &other == this)
        return false;

    Pole* pole1 = getPole(poleName);
    Pole* pole2 = getPole(otherPoleName);

    if (!pole1 || !pole2)
        return false;

    pole1->connectedObject = const_cast<Object*>(&other);
    pole1->connectedObjectPole = otherPoleName;

    pole2->connectedObject = this;
    pole2->connectedObjectPole = poleName;

    return true;
}

bool Object::disconnect(const std::string& poleName)
{
    Pole* pole = getPole(poleName);

    if (!pole || pole->connectedObjectPole.empty() || !pole->connectedObject)
        return false;
    
    auto otherPoleName = pole->connectedObjectPole;
    auto otherPole = pole->connectedObject->getPole(otherPoleName);

    pole->connectedObjectPole = "";
    pole->connectedObject = nullptr;
    otherPole->connectedObject = nullptr;
    otherPole->connectedObjectPole = "";

    return true;
}

Switch::Switch(const std::string& name) : Object(name), a1("A1"), a2("A2") {}

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
    if (idx == 1)
        return &a1;
    if (idx == 2)
        return &a2;
    return nullptr;
}

Light::Light(const std::string& name) : Object(name), a1("A1"), a2("A2") {}

const Pole* Light::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole* Light::getPole(size_t idx) const
{
    if (idx == 1)
        return &a1;
    if (idx == 2)
        return &a2;
    return nullptr;
}

const Pole* Generator::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    if (name == a3.name)
        return &a3;
    return nullptr;
}

const Pole* Generator::getPole(size_t idx) const
{
    if (idx == 1)
        return &a1;
    if (idx == 2)
        return &a2;
    if (idx == 3)
        return &a3;
    return nullptr;
}

int main()
{
    Switch sw1, sw2;
    sw1.connect("A2", sw2, "A1");
    cout << "is " << (sw1.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    Generator gen("Generator");
    Switch sw("Switch");
    Light l("Light");

    gen.connect("A1", sw, "A2");
    sw.connect("A1", l, "A2");
    l.connect("A1", gen, "A1");

    cout << "is " << (sw.isConnectedTo(l) ? "" : "not ") << "connected" << endl;
    gen.disconnect("A2");
    cout << "is " << (gen.isConnectedTo(sw) ? "" : "not ") << "connected" << endl;

    return 0;
}
