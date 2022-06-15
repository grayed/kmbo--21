#pragma once
#include <string>
class Object;

struct Pole {
    std::string name;
    Object* connectedObject;>
    std::string connectedObjectPole;
    Pole(const std::string& name_) : name(name_), connectedObject(nullptr) {}
};

class Object {
    std::string name;

protected:
    Object(const std::string& name_) : name(name_) {}
    Pole* getPole(size_t idx) {return nullptr; }
    virtual const Pole* getPole(size_t idx) const = 0;

public:
    virtual ~Object() {}
    const std::string& getName() const { return name; }
    void getName(const std::string& newName) { name = newName; }
    Pole* getPole(const std::string& name) { return const_cast<Pole*>(const_cast<const Object*>(this)->getPole(name)); }
    virtual const Pole* getPole(const std::string& name) const = 0;
    virtual size_t getPoleCount() const = 0;
    bool isConnectedTo(const Object& other) const;
    bool connect(const std::string& poleName, Object& other, const std::string& otherPoleName);
    bool disconnect(const std::string& poleName);
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
