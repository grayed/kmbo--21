﻿#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    // TODO
    for (size_t idx_1 = 0; idx_1 < this->getPoleCount(); idx_1++) {

        for (size_t idx_2 = 0; idx_2 < other.getPoleCount(); idx_2++) {

            if (this->getPole(idx_1)->name == other.getPole(idx_2)->name) return true;

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
    Switch sw;
    Power pwr;
    Light lgt;
    int counter;
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