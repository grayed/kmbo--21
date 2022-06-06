#include "electricy.h"
#include <iostream>
class Generator : public Object {
public:
    Pole phase, neural, earth;

    Generator(const std::string& name = "") : Object(name), phase("p"), neural("n"), earth("e") {}

    virtual size_t getPoleCount() const { return 3; }

    virtual const Pole* getPole(const std::string& name) const {
        if (name == phase.name) { return &phase; }
        else if (name == neural.name) { return &neural; }
        else if (name == earth.name) { return &earth; }

        return nullptr;
    }
protected:
    virtual const Pole* getPole(size_t idx) const {
        if (idx == 0) { return &phase; }
        else if (idx == 1){return &neural;}
        else if (idx == 2) { return &earth; }

        return nullptr;
    }
};