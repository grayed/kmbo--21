#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    size_t n = (this)->getPoleCount();
    for(size_t i = 0;i < n;i++){
      if(((this->getPole(i+1))->connectedObject) == &other) return true;
    }
    // TODO
    return false;
}

bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)
{
    if(this->isConnectedTo(other)) return false;
    else {
    //disconnect to this
    Object* nowConnectThis = (this->getPole(poleName))->connectedObject;
    string nwCnctThs = (this->getPole(poleName))->connectedObjectPole;
    if (nowConnectThis != nullptr) {
        (nowConnectThis->getPole(nwCnctThs))->connectedObject = nullptr;
        (nowConnectThis->getPole(nwCnctThs))->connectedObjectPole = "";
        (this->getPole(poleName))->connectedObject = const_cast<Object*>(&other);
        (this->getPole(poleName))->connectedObjectPole = otherPoleName;
    } //connect to this
    else {
      (this->getPole(poleName))->connectedObject = const_cast<Object*>(&other);
      (this->getPole(poleName))->connectedObjectPole = otherPoleName;
    }

    //disconnect to other
    Object* nowConnectOther = (other.getPole(otherPoleName))->connectedObject;
    string nwCnctOthr = (other.getPole(otherPoleName))->connectedObjectPole;
    Pole* othr = const_cast<Pole*>(other.getPole(otherPoleName));
    if (nowConnectOther != nullptr){
        (nowConnectOther->getPole(nwCnctOthr))->connectedObject = nullptr;
        (nowConnectOther->getPole(nwCnctOthr))->connectedObjectPole = "";
        othr->connectedObject = this;
        othr->connectedObjectPole = poleName;
    } //connect to other
    else{
      othr->connectedObject = this;
      othr->connectedObjectPole = poleName;
    }

    return true;
    }
}

Switch::Switch(const std::string& name)
    : Object(name)
    , s1("S1")
    , s2("S2")
{
}

Lamp::Lamp(const std::string& name)
    :Object(name)
    , l1("L1")
    , l2("L2")
{
}

Generator::Generator(const std::string& name)
    :Object(name)
    , p("Plus")
    , m("Minus")
    , g("Ground")
{
}

const Pole* Switch::getPole(const string& name) const
{
    if (name == s1.name)
        return &s1;
    if (name == s2.name)
        return &s2;
    return nullptr;
}
const Pole* Lamp::getPole(const string& name) const
{
    if (name == l1.name)
        return &l1;
    if (name == l2.name)
        return &l2;
    return nullptr;
}
const Pole* Generator::getPole(const string& name) const
{
    if (name == p.name)
        return &p;
    if (name == m.name)
        return &m;
    if (name == g.name)
        return &g;
    return nullptr;
}
const Pole* Switch::getPole(size_t idx) const
{
    if (idx == 1)
        return &s1;
    if (idx == 2)
        return &s2;
    // TODO
    return nullptr;
}
const Pole* Lamp::getPole(size_t idx) const
{
    if (idx == 1)
        return &l1;
    if (idx == 2)
        return &l2;
    // TODO
    return nullptr;
}
const Pole* Generator::getPole(size_t idx) const
{
    if (idx == 1)
        return &p;
    if (idx == 2)
        return &m;
    if (idx == 3)
        return &g;
    return nullptr;
}



int main()
{
    Switch sw, sw2;
    sw.connect("S2", sw2, "S1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;

    Switch sw0;
    Lamp l;
    Generator g;
    sw0.connect("S1", l,"L1");
    l.connect("L2",g,"Plus");
    g.connect("Minus",sw0,"S2");
    if(sw0.isConnectedTo(g) && sw0.isConnectedTo(l)) cout << "Switch is connected\n";
    else cout << "Switch is not connected";
    if(l.isConnectedTo(g) && l.isConnectedTo(sw0)) cout << "Lamp is connected\n";
    else cout << "Lamp is not connected";
    if(g.isConnectedTo(l) && g.isConnectedTo(sw0)) cout << "Generator is connected\n";
    else cout << "Generator is not connected";
    // TODO: создать цепь из генератора, выключателя и светильника

    return 0;
}
