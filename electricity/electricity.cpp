#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    // TODO
    for (size_t idx_1 = 0; idx_1 < this->getPoleCount(); idx_1++) {

        for (size_t idx_2 = 0; idx_2 < other.getPoleCount(); idx_2++) {

            if (this->getPole(idx_1)->connectedObject->name == other.name && this->getPole(idx_1)->connectedObjectPole == other.getPole(idx_2)->name) return true;
        }
    }
    return false;
}

bool Object::disconnect(const std::string& poleName)
{
    // TODO
    if (this->getPole(poleName)->connectedObjectPole != "") {

        this->getPole(poleName)->connectedObjectPole = "";

        this->getPole(poleName)->connectedObject = nullptr;

        return true;
    }
    else return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    // TODO
    this->getPole(poleName)->connectedObjectPole = otherPoleName;
    this->getPole(poleName)->connectedObject = &other;

    other.getPole(otherPoleName)->connectedObject = this;
    other.getPole(otherPoleName)->connectedObjectPole = poleName;

    return false;
}

Switch::Switch(const std::string& name) : Object(name), A1("sw1"), A2("sw2") {}

Light::Light(const std::string& name_) : Object(name_), A1("l1"), A2("l2") {}

Power::Power(const std::string& name_) : Object(name_), A1("p1"), A2("p2"), A3("p3") {}

const Pole* Switch::getPole(const string& name) const
{
    if (name == A1.name)
        return &A1;
    if (name == A2.name)
        return &A2;
    return nullptr;
}

const Pole* Light::getPole(const string& name) const
{
    if (name == A1.name)
        return &A1;
    if (name == A2.name)
        return &A2;
    return nullptr;
}
const Pole* Power::getPole(const string& name) const
{
    if (name == A1.name)
        return &A1;
    if (name == A2.name)
        return &A2;
    if (name == A3.name)
        return &A3;
    return nullptr;
}

const Pole* Switch::getPole(size_t idx) const
{
    return (getPole("sw" + std::to_string(idx + 1)));
}

const Pole* Light::getPole(size_t idx) const
{
    return (getPole("l" + std::to_string(idx + 1)));
}
const Pole* Power::getPole(size_t idx) const
{
    return (getPole("p" + std::to_string(idx + 1)));
}
int main()
{
    cerr << "________________ " << endl;



    Power p;
    Light l;
    Switch sw;
    p.getName("power");
    l.getName("light");
    sw.getName("switch");
    p.connect("p1", l, "l1");
    l.connect("l2", sw, "sw1");
    sw.connect("sw2", p, "p2");
    cout << "Is sw connected l ?" << "\n" << sw.isConnectedTo(l) << endl;
   
    sw.disconnect("sw1");
    l.disconnect("l2");
    /*
    cout << "Is sw connected l ?" << "\n" << sw.isConnectedTo(l) << endl;
    */
    return 0;
}

// источник -> переключатель -> светильник