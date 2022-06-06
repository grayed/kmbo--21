#pragma once
#include <string>
using namespace std;
class Object;

struct Pole {
    string name;
    Object* connectedObject;
    string connectedObjectPole;

    Pole(const std::string& name_) : name(name_), connectedObject(nullptr) {}
};



class Object{
    string name;
protected:
    Object(const std::string& name_) : name(name_) {}

    Pole* getPole(size_t idx) { return nullptr; }
    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}

    const std::string& getName() const { return name; }
    void getName(const std::string& newName) { name = newName; }

    Pole* getPole(const std::string& name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }


    virtual const Pole* getPole(const std::string& name) const = 0;

    virtual size_t getPoleCount() const = 0;
    bool isConnectedTo(const Object& other) const;
    bool connect(const std::string& poleName, const Object& other, const std::string& otherPoleName);
};
class Switch : public Object {
public:
    Pole a1, a2;

    Switch(const std::string& name = "");

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const std::string& name) const;

protected:
    virtual const Pole* getPole(size_t idx) const;
};

class Light : public Object {
public:
    Pole a1, a2;

    Light(const std::string& name = "") : Object(name), a1("A1"), a2("A2") {}

    virtual size_t getPoleCount() const { return 2; }

    virtual const Pole* getPole(const std::string& name) const {
        if (name == a1.name) { return &a1; }
        else if (name == a2.name) {return &a2;}

        return nullptr;
    }
protected:
    virtual const Pole* getPole(size_t idx) const {
        if (idx == 0) {return &a1;}
        else if (idx == 1) { return &a2; }

        return nullptr;
    }
};

class Generator : public Object {
public:
    Pole phase, neural, earth;

    Generator(const std::string& name = "") : Object(name), phase("p"), neural("n"), earth("e") {}

    virtual size_t getPoleCount() const { return 3; }

    virtual const Pole* getPole(const std::string& name) const {
        if (name == phase.name) {return &phase;}
        else if (name == neural.name) {return &neural; }
        else if (name == earth.name) { return &earth; }

        return nullptr;
    }
protected:
    virtual const Pole* getPole(size_t idx) const {
        if (idx == 0) return &phase;
        else if (idx == 1) { return &neural; }
        else if (idx == 2) { return &earth; }

        return nullptr;
    }
};
