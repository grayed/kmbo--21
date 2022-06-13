#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (size_t i = 0; i < getPoleCount(); i++)
    {
       if(getPole(i)->connectedObject == &other) return true;
    }
        
    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    if (getPole(poleName) == nullptr  || getPole(poleName)->name == otherPoleName) return false;
    getPole(poleName)->connectedObject = &other;
    getPole(poleName)->connectedObjectPole = otherPoleName;

    return true;
}

bool Object::disconnect(const std::string& poleName)
{
    getPole(poleName)->connectedObject = nullptr;
    getPole(poleName)->connectedObjectPole = nullptr;

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
    if (idx == 0) {
        return &a1;
    }
    else if (idx == 1) {
        return &a2;
    }
    else {
        return nullptr;
    }
}

const Pole* Lamp::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole* Lamp::getPole(size_t idx) const
{
    if (idx == 0) {
        return &a1;
    }
    else if (idx == 1) {
        return &a2;
    }
    else {
        return nullptr;
    }
}

const Pole* Generator::getPole(const string& name) const
{
    if (name == p.name) //phase
        return &p;
    if (name == n.name) //neutral
        return &n;
    if (name == e.name) //earth
        return &e;
    return nullptr;
}

const Pole* Generator::getPole(size_t idx) const
{
    if (idx == 0) {
        return &p;
    }
    else if (idx == 1) {
        return &n;
    }
    else if (idx == 2) {
        return &e;
    }
     
    return nullptr;
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
   //cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    Generator g; Lamp l; Switch s;

    g.connect("Phase", s, "A1");
    s.connect("A2", l, "A1");
    l.connect("A2", g, "Neutral");


    cout << "is " << (g.isConnectedTo(s) ? "" : "not ") << "connected" << endl;
    cout << "is " << (s.isConnectedTo(l) ? "" : "not ") << "connected" << endl;
    cout << "is " << (l.isConnectedTo(g) ? "" : "not ") << "connected" << endl;


    return 0;
}
