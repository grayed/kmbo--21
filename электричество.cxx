
#include<string>
#include<iostream>


using namespace std;

class Object;

@@ -50,7 +54,15 @@ class Object {
    
    Pole* getPole(size_t idx) { /* TODO */ return nullptr; }
    Pole* getPole(size_t idx) {
        if (idx > getPoleCount()) {
            std::string str = "O" + std::to_string(idx);
            return getPole(str);
        }
        else {
            return nullptr;
        }
    };

    
@@ -63,7 +75,7 @@ class Object {
    virtual ~Object() {}

    const std::string& getName() const { return name; }
    void getName(const std::string &newName) { name = newName; }
    void getName(const std::string& newName) { name = newName; }

@@ -114,13 +126,12 @@ class Object {
    
    bool disconnect(const std::string& poleName);
};


class Switch : public Object {
public:
    Pole a1, a2;
    Pole A1, A2;

    Switch(const std::string& name = "");

@@ -132,6 +143,39 @@ class Switch : public Object {
    virtual const Pole* getPole(size_t idx) const;
};


class Power : public Object {
public:
    Pole A1, A2, A3;

    Power(const std::string& name = "");

    virtual size_t getPoleCount() const { return 3; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};


class Light : public Object {
public:
    Pole A1, A2;

    bool st = false;

    Light(const std::string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};





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
bool Object::disconnect(const std::string& poleName)
{

    return false;
    if (getPole(poleName)->connectedObjectPole != "") {

        getPole(poleName)->connectedObjectPole = "";
        this->getPole(poleName)->connectedObject = nullptr;
        return true;
    }
    else return false;
}

bool Object::disconnect(const std::string& poleName)
bool Object::connect(const std::string& poleName, Object& other, const std::string& otherPoleName)
{
    // TODO
    this->getPole(poleName)->connectedObjectPole = otherPoleName;
    this->getPole(poleName)->connectedObject = &other;

    other.getPole(otherPoleName)->connectedObject = this;
    other.getPole(otherPoleName)->connectedObjectPole = poleName;

    return false;
}

Switch::Switch(const std::string& name)
    : Object(name)
    , a1("A1")
    , a2("A2")
Switch::Switch(const std::string& name) : Object(name), A1("A1"), A2("A2") {}

Light::Light(const std::string& name_) : Object(name_), A1("A1"), A2("A2") {}

Power::Power(const std::string& name_) : Object(name_), A1("A1"), A2("A2"), A3("A3") {}

const Pole* Switch::getPole(const string& name) const
{
    if (name == A1.name)
        return &A1;
    if (name == A2.name)
        return &A2;
    return nullptr;
}

const Pole* Switch::getPole(const string& name) const
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
    if (name == a1.name)
        return &a1;
    if (name == a2.name)
        return &a2;
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
    // TODO
    return nullptr;
    return (getPole("A" + std::to_string(idx + 1)));
}

const Pole* Light::getPole(size_t idx) const
{
    return (getPole("A" + std::to_string(idx + 1)));
}
const Pole* Power::getPole(size_t idx) const
{
    return (getPole("A" + std::to_string(idx + 1)));
}
int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected!" << endl;


    Power p;
    Light l;
    Switch sw3;



    p.connect("A1", l, "A1");
    l.connect("A2", sw, "A1");
    cout << "is " << (p.isConnectedTo(l) ? "" : "not ") << "connected!" << endl;
    cout << "is " << (l.isConnectedTo(sw3) ? "" : "not ") << "connected!" << endl;

    p.disconnect("A1");
    cout << "is " << (p.isConnectedTo(l) ? "" : "not ") << "connected!" << endl;

    return 0;
}
