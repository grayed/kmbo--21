#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
    for (int i=1;i<=getPoleCount();i++){
        for (int j=1;j<=other.getPoleCount();j++){
            if (getPole(i)->connectedObjectPole==other.getPole(j)->name && getPole(i)->connectedObject == const_cast<Object*>(&other))
                return true;
        }
    }
    return false;
}

bool Object::connect(const std::string& poleName, const Object& other, const std::string& otherPoleName)
{
    if (poleName!=otherPoleName){
        disconnect(poleName);
        disconnect(otherPoleName);
        getPole(poleName)->connectedObject=const_cast<Object*>(&other);
        getPole(poleName)->connectedObjectPole=otherPoleName;
        getPole(otherPoleName)->connectedObjectPole=poleName;
        getPole(otherPoleName)->connectedObject=const_cast<Object*>(this);
        return true;
    }
    return false;
}

bool Object::disconnect(const std::string& poleName)
{
    if (getPole(poleName)->connectedObject!=nullptr)
    {
        getPole(getPole(poleName)->connectedObjectPole)->connectedObject = nullptr;
        getPole(getPole(poleName)->connectedObjectPole)->connectedObjectPole = "";
        getPole(poleName)->connectedObject=nullptr;
        getPole(poleName)->connectedObjectPole="";
        return true;
    }
    return false;
}

Switch::Switch(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{}
Light::Light(const std::string & name)
    : Object(name)
    , a1("A1")
    , a2("A2")
{}
Generator::Generator(const std::string & name)
    : Object(name)
    , a1("A1") //Faza ~ фаза
    , a2("A2") //Neytral ~ нейтраль
    , a3("A3") //Zemly ~ земля
{}

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
    if (idx==1)
        return &a1;
    if (idx==2)
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

const Pole* Light::getPole(size_t idx) const
{ 
    if (idx==1)
        return &a1;
    if (idx==2)
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
    if (idx==1)
        return &a1;
    if (idx==2)
        return &a2;
    if (idx==3)
        return &a3;
    return nullptr;
}
int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;
    sw.disconnect("A2");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;
    //создать цепь из генератора, выключателя и светильника
    Switch sw1;
    Light lamp;
    Generator gen;  //A1-фаза, А2-нейтраль А3-земля
    gen.connect("A1",sw1,"A2"); // к фазе подключаем переключатель к полюсу А2
    cout << "is " << (gen.isConnectedTo(sw1) ? "" : "not ") << "connected" << endl;
    sw1.connect("A1",lamp,"A2"); // к другому полюсу перключателя (А1) подключаем лампу полюсуом А2
    cout << "is " << (sw1.isConnectedTo(lamp) ? "" : "not ") << "connected" << endl;
    gen.connect("A2",lamp,"A1"); // подключили лампу другим полюсом к генературу, нейтрали.
    cout << "is " << (gen.isConnectedTo(lamp) ? "" : "not ") << "connected" << endl;
    return 0;
}
