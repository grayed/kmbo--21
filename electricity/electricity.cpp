#include "electricity.h"
#include <iostream>

Pole* Pole::getNewInstance()
{
    _poles.emplace_back(new Pole);
    return _poles.back();
}

void Pole::connect(Pole& pole)
{
    if (_connectedId == pole.getId())
        return;
    if (_connectedId)
        disconnect();
    _connectedId = pole.getId();
    pole.connect(*this);
}

void Pole::disconnect()
{
    unsigned int connectedId = _connectedId;
    _connectedId = 0;
    if (connectedId)
        for (auto& pole: _poles)
            if (pole->getId() == connectedId)
                pole->disconnect();
}

Pole::ID Pole::getId() const
{
    return _id;
}

Pole::ID Pole::getConnectedId() const
{
    return _connectedId;
}

bool Pole::send(const std::string& command)
{
    if (!_connectedId)
        return false;
    for (auto& pole: _poles)
        if (pole->getId() == _connectedId)
            pole->getCommand(command);
    return true;
}

void Pole::getCommand(const std::string& command)
{
    if (!_connectedId)
        return;
    if (!command.empty())
        if (_hasCallback)
            _callback(command);
}

Pole::Pole()
{
    _id = ++_total;
}

Pole::~Pole()
{
    disconnect();

    for (size_t i = 0; i < _poles.size(); ++i)
        if (_poles[i] == this) {
            std::swap(_poles[i], _poles.back());
            _poles.pop_back();
            break;
        }
}

void Pole::setCallback(std::function<void(const std::string&)> callback)
{
    _callback = std::move(callback);
    _hasCallback = true;
}

const std::string& Object::getName() const
{
    return _name;
}

bool Object::connect(const Object& object)
{
    if (isConnectedTo(object))
        return true;
    Pole* freePole = nullptr;
    for (auto& pole: _poles)
        if (!pole->getConnectedId())
            freePole = pole;
    if (!freePole)
        return false;
    Pole* pole = object.getFreePole();
    if (!pole)
        return false;
    freePole->connect(*pole);
}

void Object::disconnect(const Object& object)
{
    if (!isConnectedTo(object))
        return;
    for (auto& a: _poles)
        for (auto& b: object.getPoles())
            if (a->getConnectedId() == b->getId())
                a->disconnect();
}

bool Object::isConnectedTo(const Object& object) const
{
    for (auto& a: getPoles())
        for (auto& b: object.getPoles())
            if (a == b)
                return true;
    return false;
}

std::vector<Pole*> Object::getPoles() const
{
    return _poles;
}

Pole* Object::getFreePole() const
{
    for (auto& pole: _poles)
        if (!pole->getConnectedId())
            return pole;
    return nullptr;
}

Pole* Object::getPoleConnectedTo(const Object& object) const
{
    for (auto& a: _poles)
        for (auto& b: object.getPoles())
            if (a->getConnectedId() == b->getId())
                return a;
    return nullptr;
}

Object::Object(const std::string& name, unsigned int polesAmount) : _name(name)
{
    for (unsigned int i = 0; i < polesAmount; ++i)
        _poles.emplace_back(Pole::getNewInstance());
}

Switch::Switch(const std::string& name) : Object(name, 2)
{
    auto poles = getPoles();

    poles[0]->setCallback([&poles](const std::string& command) {
        poles[1]->send(command);
    });

    poles[1]->setCallback([&poles](const std::string& command) {
        poles[0]->send(command);
    });
}

void Switch::toggle()
{
    for (auto& pole: getPoles()) {
        if (isOn)
            pole->send("off");
        else
            pole->send("on");
    }
    isOn = !isOn;
}

Light::Light(const std::string& name) : Object(name, 2)
{
    for (auto& pole: getPoles())
        pole->setCallback([this](const std::string& command) {
            if (command == "on")
                std::cout << "Lights \"" << getName() << "\" are now on\n";
            else if (command == "off")
                std::cout << "Lights \"" << getName() << "\" are now off\n";
            else
                std::cout << "Unknown command\n";
        });
}

Generator::Generator(const std::string& name) : Object(name, 3)
{}

int main()
{
    Generator g("Generator");

    Switch s1("s1");
    Switch s2("s2");
    Switch s3("s3");

    Light l1("l1");
    Light l2("l2");
    Light l3("l3");

    g.connect(s1);
    g.connect(s2);
    g.connect(s3);

    s1.connect(l1);
    s2.connect(l2);
    s3.connect(l3);

    s2.toggle();
    std::cout << "\n";

    for (int i = 0; i < 3; ++i) {
        s1.toggle();
        s2.toggle();
        s3.toggle();
        std::cout << "\n";
    }
}