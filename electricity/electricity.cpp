#include <iostream>
#include "electricity.h"

using namespace std;
/*
1) Реализовать const Pole* Switch::getPole(size_t idx) const.
2) Реализовать Pole* Object::getPole(size_t idx).
3) Реализовать bool Object::isConnectedTo(const Object& other) const.
4) Реализовать bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName).
5) Реализовать класс светильника Light с двумя полюсами.
6) Реализовать класс генератора с тремя полюсами(фаза, нейтраль, земпя).
7) В функции main() построить цепь из генератора, выключателя и светильника.
*/
bool Object::isConnectedTo(const Object& other) const
{
    // TODO
    return false;
}

bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)
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
    // TODO
    return nullptr;
}

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    // TODO: создать цепь из генератора, выключателя и светильника

    return 0;
}
