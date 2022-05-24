#include "animal.h"

Animal::Animal() : _massInKilos(20)
{
}

void Animal::setMass(const float& newMass)
{
    _massInKilos = newMass;
}

float Animal::getMass() const
{
    return _massInKilos;
}

std::string Animal::about() const
{
    return "mass: " + std::to_string(_massInKilos) + "\n";
}

Mammal::Mammal() : Animal(), _amountOfTeeth(20)
{

}

void Mammal::setAmountOfTeeth(const float& newAmount)
{
    _amountOfTeeth = newAmount;
}

float Mammal::getAmountOfTeeth() const
{
    return _amountOfTeeth;
}

std::string Mammal::about() const
{
    return Animal::about() + "amount of teeth: " + std::to_string(_amountOfTeeth) + "\n";
}

Insect::Insect() : Animal(), _amountOfWings(2)
{

}

void Insect::setAmountOfWings(const unsigned int& newAmount)
{
    _amountOfWings = newAmount;
}

unsigned int Insect::getAmountOfWings() const
{
    return _amountOfWings;
}

std::string Insect::about() const
{
    return Animal::about() + "amount of wings: " + std::to_string(_amountOfWings) + "\n";
}

Cat::Cat() : Mammal(), _eyeColor(color::blue)
{

}

void Cat::setEyeColor(const Cat::color& newColor)
{
    _eyeColor = newColor;
}

Cat::color Cat::getEyeColor() const
{
    return _eyeColor;
}

std::string Cat::about() const
{
    return Mammal::about() + "eye color: " + std::to_string((int) _eyeColor) + "\n";
}

Dog::Dog() : Mammal(), _barkVolume(50)
{

}

void Dog::setBarkVolume(const float& newVolume)
{
    _barkVolume = newVolume;
}

float Dog::getBarkVolume() const
{
    return _barkVolume;
}

std::string Dog::about() const
{
    return Mammal::about() + "bark volume: " + std::to_string(_barkVolume) + "\n";
}

Ladybug::Ladybug() : Insect(), _amountOfDots(3)
{

}

void Ladybug::setAmountOfDots(const unsigned int& newAmount)
{
    _amountOfDots = newAmount;
}

unsigned int Ladybug::getAmountOfDots() const
{
    return _amountOfDots;
}

std::string Ladybug::about() const
{
    return Insect::about() + "amount of dots: " + std::to_string(_amountOfDots) + "\n";
}

Bumblebee::Bumblebee() : Insect(), _amountOfLines(10)
{

}

void Bumblebee::setAmountOfLines(const unsigned int& newAmount)
{
    _amountOfLines = newAmount;
}

unsigned int Bumblebee::getAmountOfDots() const
{
    return _amountOfLines;
}

std::string Bumblebee::about() const
{
    return Insect::about() + "amount of lines: " + std::to_string(_amountOfLines) + "\n";
}

std::ostream& operator<<(std::ostream& out, const Animal& animal)
{
    return out << animal.about() << std::endl;
}


int main()
{
    Bumblebee b;
    std::cout << b;
    return EXIT_SUCCESS;
}