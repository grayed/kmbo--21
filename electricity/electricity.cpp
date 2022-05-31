#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    // TODO
    for (size_t idx_1 = 0; idx_1 < this->getPoleCount(); idx_1++) {

        for (size_t idx_2 = 0; idx_2 < other.getPoleCount(); idx_2++) {

            if (this->getPole(idx_1)->connectedObjectPole == other.getPole(idx_2)->name) return true;

        }
    }
    return false;
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

bool Object::disconnect(const std::string& poleName)
{
    // TODO
    if (this->getPole(poleName)->connectedObjectPole != "") { this->getPole(poleName)->connectedObjectPole = ""; }
    return false;
}

Switch::Switch(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{}

Light::Light(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{}

Power::Power(const std::string& name)
    : Object(name)
    , phase("A1") 
    , neutral("A2") 
    , ground("A3") 
{}

const Pole* Switch::getPole(const string& name) const
{
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
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

const Pole* Power::getPole(const string& name) const
{
    if (name == phase.name)
        return &phase;
    if (name == neutral.name)
        return &neutral;
    if (name == ground.name)
        return &ground;
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

const Pole* Light::getPole(size_t idx) const
{
    if (idx == 1)
        return &a1;
    if (idx == 2)
        return &a2;
    return nullptr;
}

const Pole* Power::getPole(size_t idx) const
{
    if (idx == 1)
        return &phase;
    if (idx == 2)
        return &neutral;
    if (idx == 3)
        return &ground;
    return nullptr;
}


int main()
{
    Switch sw;   // Переключатель
    Power pwr;   // Источник 
    Light lgt;   // Светильник
    //int counter;
    lgt.getPole("lgt_in");
    lgt.getPole("lgt_out");
    pwr.getPole("phase");
    pwr.getPole("ground");
    pwr.getPole("neutral");
    lgt.connect("lgt_in", pwr, "phase");
    lgt.connect("lgt_out", pwr, "neutral");
    /*for (int i = 0; i<100; i++)
    {
        cin >> counter;
        cout << lgt.getPole("lgt_in")->name << lgt.getPole("lgt_out")->name << endl;
        cout << lgt.getPole("lgt_in")->connectedObjectPole << lgt.getPole("lgt_out")->connectedObjectPole << endl;
    };*/
    // TODO: создать цепь из генератора, выключателя и светильника
    return 0;
}

//Power::Power(const std::string& name)

