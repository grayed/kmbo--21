include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const
{
// TODO
return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
// TODO
return false;
}

bool Object::disconnect(const std::string& poleName)
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
cout « "is " « (sw.isConnectedTo(sw2) ? "" : "not ") « "connected" « endl;

// TODO: создать цепь из генератора, выключателя и светильника

return 0;
}
