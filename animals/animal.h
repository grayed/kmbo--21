#pragma once

#include <string>
#include <iostream>

class Animal
{
public:
    void setMass(const float& newMass);

    float getMass() const;

    virtual std::string about() const;

protected:
    Animal();

    float _massInKilos;
};

class Mammal : public Animal
{
public:
    void setAmountOfTeeth(const float& newAmount);

    float getAmountOfTeeth() const;

    virtual std::string about() const override;


protected:
    Mammal();

    unsigned int _amountOfTeeth;
};

class Insect : public Animal
{
public:

    void setAmountOfWings(const unsigned int& newAmount);

    unsigned int getAmountOfWings() const;

    virtual std::string about() const override;

protected:
    Insect();

    unsigned int _amountOfWings;
};

class Cat : public Mammal
{
public:
    enum class color
    {
        grey = 0, yellow, blue, magenta
    };

    Cat();

    void setEyeColor(const color& newColor);

    color getEyeColor() const;

    std::string about() const override;

private:
    color _eyeColor;
};

class Dog : public Mammal
{
public:
    Dog();

    void setBarkVolume(const float& newVolume);

    float getBarkVolume() const;

    std::string about() const override;

private:

    float _barkVolume;
};

class Ladybug : public Insect
{
public:
    Ladybug();

    void setAmountOfDots(const unsigned int& newAmount);

    unsigned int getAmountOfDots() const;

    std::string about() const override;

private:
    unsigned int _amountOfDots;
};

class Bumblebee : public Insect
{
public:
    Bumblebee();

    void setAmountOfLines(const unsigned int& newAmount);

    unsigned int getAmountOfDots() const;

    std::string about() const override;

private:
    unsigned int _amountOfLines;
};

std::ostream& operator<<(std::ostream& out, const Animal& animal);