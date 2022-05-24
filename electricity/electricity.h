#pragma once

#include <vector>
#include <string>
#include <functional>

class Pole
{
public:
    using ID = unsigned short;

    static Pole* getNewInstance();

    void connect(Pole& pole);

    void disconnect();

    ID getId() const;

    ID getConnectedId() const;

    bool send(const std::string& command);

    void getCommand(const std::string& command);

    void onUpdate();

    void setCallback(std::function<void(const std::string& command)> callback);

private:
    Pole();

    ~Pole();

    inline static ID _total = 0;
    ID _id;
    ID _connectedId = 0;
    inline static std::vector<Pole*> _poles;
    bool _hasCallback = false;
    std::function<void(const std::string&)> _callback;
};

class Object
{
public:
    const std::string& getName() const;

    bool connect(const Object& object);

    void disconnect(const Object& object);

    bool isConnectedTo(const Object& object) const;

    std::vector<Pole*> getPoles() const;

    Pole* getFreePole() const;

    Pole* getPoleConnectedTo(const Object& object) const;

private:
    std::string _name;
    std::vector<Pole*> _poles;

protected:
    Object(const std::string& name, unsigned int polesAmount);
};

class Switch : public Object
{
public:
    Switch(const std::string& name);

    void toggle();

private:
    bool isOn = false;
};

class Light : public Object
{
public:
    Light(const std::string& name);
};

class Generator : public Object
{
public:
    Generator(const std::string& name);
};