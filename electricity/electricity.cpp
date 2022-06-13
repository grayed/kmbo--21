#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    // TODO
    for (int i = 1; i <= getPoleCount(); i++) {
        for (int j = 1; j <= other.getPoleCount(); j++) {
            if (getPole(i)->connectedObjectPole == other.getPole(j)->name && getPole(i)->connectedObject == const_cast<Object*>(&other))
                return true;
        }
    }
    return false;
}

bool Object::disconnect(const std::string& poleName)
{
    //TODO
    if (getPole(poleName)->connectedObject != nullptr) {
        getPole(getPole(poleName)->connectedObjectPole)->connectedObject = nullptr;
        getPole(getPole(poleName)->connectedObjectPole)->connectedObjectPole = "";
        getPole(poleName)->connectedObject = nullptr;
        getPole(poleName)->connectedObjectPole = "";
        return true;
    }
    return false;
}

bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)
{
    disconnect(poleName);
    disconnect(otherPoleName);
    getPole(poleName)->connectedObject = const_cast<Object*>(&other);
    getPole(poleName)->connectedObjectPole = otherPoleName;
    Pole* p = const_cast<Pole*>(other.getPole(otherPoleName));
    p->connectedObjectPole = poleName;
    p->connectedObject = const_cast<Object*>(this);
    return true;
}


Switch::Switch(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{
}

Light::Light(const std::string& name)
    : Object(name)
    , l1("A1")
    , l2("A2")
{
}

Generator::Generator(const std::string& name)
    : Object(name)
    , g1("A1") //фаза - faza
    , g2("A2") //нейтраль - neytral
    , g3("A3") //Земля - Zemlai
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
    // TODO
    if (idx == 1)
        return &a1;
    if (idx == 2)
        return &a2;
    return nullptr;
}



const Pole* Light::getPole(size_t idx) const
{

    if (idx == 1)
        return &l1;
    if (idx == 2)
        return &l2;
    return nullptr;
}

const Pole* Light::getPole(const string& name) const
{
    if (name == l1.name)
        return &l1;
    if (name == l2.name)
        return &l2;
    return nullptr;
}

const Pole* Generator::getPole(size_t idx) const
{

    if (idx == 1)
        return &g1;
    if (idx == 2)
        return &g2;
    if (idx == 3)
        return &g3;
    return nullptr;
}

const Pole* Generator::getPole(const string& name) const
{
    if (name == g1.name)
        return &g1;
    if (name == g2.name)
        return &g2;
    if (name == g3.name)
        return &g3;
    return nullptr;
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    // TODO: создать цепь из генератора, выключателя и светильника

    Generator gen; 
    Light light;
    Switch s;
    gen.connect("A1", s, "A2");
    cout << "is " << (gen.isConnectedTo(s) ? "" : "not ") << "connected" << endl;
    s.connect("A1", light, "A2");
    cout << "is " << (s.isConnectedTo(light) ? "" : "not ") << "connected" << endl;
    gen.connect("A2", light, "A1");
    cout << "is " << (s.isConnectedTo(light) ? "" : "not ") << "connected" << endl;
    return 0;
}