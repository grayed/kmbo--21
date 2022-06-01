#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (int i = 0; i < getPoleCount(); ++i) {
        auto pole = getPole(i);
        if (pole != nullptr && pole->connectedObject == &other)
            return true;
    }
    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    if (poleName == otherPoleName && &other == this) return false;
    auto pole = getPole(poleName);
    auto otherPole = (Pole*)(other.getPole(otherPoleName));
    if (otherPole == nullptr || otherPole == nullptr) return false;
    pole->connectedObject = (Object*)(&other);
    pole->connectedObjectPole = otherPoleName;
    otherPole->connectedObject = this;
    otherPole->connectedObjectPole = poleName;
    return true;
}

bool Object::disconnect(const std::string& poleName)
{
    auto pole = getPole(poleName);
    if (pole->connectedObjectPole == "")
        return false;
    else {
        pole->connectedObjectPole = "";
        pole->connectedObject = nullptr;
        return true;
    }
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
    return getPole("A" + to_string(idx + 1));
}

Lamp::Lamp(const string &name) 
    : Object(name)
    , a1("A1")
    , a2("A2") 
{
}

const Pole *Lamp::getPole(const string &name) const {
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole *Lamp::getPole(size_t idx) const {
    return getPole("A" + to_string(idx + 1));
}

Generator::Generator(const string &name) 
    : Object(name)
    , a1("A1")
    , a2("A2")
    , a3("A3") 
{
}

const Pole *Generator::getPole(const string &name) const {
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    if (name == a3.name)
        return &a3;
    return nullptr;
}

const Pole *Generator::getPole(size_t idx) const {
    return getPole("A" + to_string(idx + 1));
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    Generator generator; 
    Lamp lamp; 
    Switch sw3;

    generator.connect("A1", lamp, "A1");
    lamp.connect("A2", sw3, "A1");
    cout << "is " << (generator.isConnectedTo(lamp) ? "" : "not ") << "connected" << endl;
    cout << "is " << (lamp.isConnectedTo(sw3) ? "" : "not ") << "connected" << endl;

    generator.disconnect("A1");
    cout << "is " << (generator.isConnectedTo(lamp) ? "" : "not ") << "connected" << endl;

    return 0;
}
