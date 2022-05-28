#include <iostream>
#include "electricity.h"

using namespace std;

bool Object::isConnectedTo(const Object& other) const {
    for (int i = 0; i < getPoleCount(); ++i) {
        auto pole = getPole(i);
        if (pole != nullptr && pole->connectedObject == &other)
            return true;
    }
    return false;
}

bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName) {
    if (poleName == otherPoleName && &other == this)
        return false;

    auto pole = getPole(poleName);
    auto otherPole = (Pole*)(other.getPole(otherPoleName));

    pole->connectedObject = (Object*)(&other);
    pole->connectedObjectPole = otherPoleName;
    otherPole->connectedObject = this;
    otherPole->connectedObjectPole = poleName;

    return true;
}

bool Object::disconnect(const std::string &poleName) {
    auto pole = getPole(poleName);
    if (pole->connectedObjectPole.empty())
        return false;
    else {
        pole->connectedObjectPole = "";
        pole->connectedObject = nullptr;
        return true;
    }
}

Switch::Switch(const std::string& name) : Object(name), a1("A1"), a2("A2") {}

const Pole* Switch::getPole(const string& name) const {
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole* Switch::getPole(size_t idx) const {
    return getPole("A" + to_string(idx + 1));
}

Light::Light(const string &name) : Object(name), a1("A1"), a2("A2") {}

const Pole *Light::getPole(const string &name) const {
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    return nullptr;
}

const Pole *Light::getPole(size_t idx) const {
    return getPole("A" + to_string(idx + 1));
}

Generator::Generator(const string &name) : Object(name), a1("A1"), a2("A2"), a3("A3") {}

const Pole *Generator::getPole(const string &name) const {
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
    if (name == a3.name)
        return &a3;
    return nullptr;
}

const Pole *Generator::getPole(size_t idx) const {
    return getPole("A" + to_string(idx + 1));
}

int main() {
    Generator gen = Generator("Generator 1");
    Switch sw = Switch("Switch 1");
    Light light = Light("Light 1");

    gen.connect("A1", sw, "A1");
    sw.connect("A2", light, "A1");
    gen.connect("A2", light, "A2");

    cout << "is " << (gen.isConnectedTo(sw) ? "" : "not ") << "connected" << endl;

    return 0;
}
