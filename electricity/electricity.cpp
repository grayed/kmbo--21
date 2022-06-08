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
    , a1("A1")
    , a2("A2")
{
}

Generator::Generator(const std::string& name)
    : Object(name)
    , a1("A1") //фаза - faza
    , a2("A2") //нейтраль - neytral
    , a3("A3") //Земля - Zemlai
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
        return &a1;
    if (idx == 2)
        return &a2;
    return nullptr;
}

const Pole* Light::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
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

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    // TODO: создать цепь из генератора, выключателя и светильника

    Generator g; //A1 - фаза, А2 - нейтрал, А3 - земля
    Light l;
    Switch s;
    // к А1(фазу) подключим переключатель к полюсу А2
    g.connect("A1", s, "A2");
    cout << "is " << (g.isConnectedTo(s) ? "" : "not ") << "connected" << endl;
    //к другому полюсу переключателя подключим А1 подключаем лампу полюсу А2
    s.connect("A1", l, "A2");
    cout << "is " << (s.isConnectedTo(l) ? "" : "not ") << "connected" << endl;
    // подключим лампу другим полюсам к генератору, нейтрал
    g.connect("A2", l, "A1");
    cout << "is " << (s.isConnectedTo(l) ? "" : "not ") << "connected" << endl;
    return 0;
}