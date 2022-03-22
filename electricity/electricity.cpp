#include <iostream>
using namespace std;

class Object;

struct Pole {
    string name;
    Object *connectedObject;
    string connectedObjectPole;

    Pole(const string &name_) : name(name_), connectedObject(nullptr) {}
};

class Object {
    string name;

protected:
    Object(const string &name_) : name(name_) {}
    Pole* getPole(size_t idx) { /*TODO*/ return nullptr; }
    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}
    Pole* getPole(const string &name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }
    virtual const Pole* getPole(const string &name) const = 0;
    virtual size_t getPoleCount() const = 0;
    bool isConnectedTo(const Object &other) const { /* TODO */ return false; }
    void connect(const string &poleName, const Object &other, const string &otherPoleName) { /* TODO */ }
};

class Switch : public Object {
public:
    Pole a1, a2;
    Switch(const string &name = "") : Object(name), a1("A1"), a2("A2") {}
    virtual size_t getPoleCount() const { return 2; }
    virtual const Pole* getPole(const string &name) const {
        if (name == a1.name) return &a1;
        else if (name == a2.name) return &a2;
        else return nullptr;
    }
protected:
    virtual const Pole* getPole(size_t idx) const { /* TODO */ return nullptr; }
};

int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;
    return 0;
}
