#include "animal.h"
#include <sstream>
#include <string>
#include <iostream>
using namespace std;

class  Animal 
{
    private:
        int Age; //Years
    public:
        float height; //Meters
        void setAge(int getAge) { Age = NewAge; }
        int getAge() const { return Age; }
        virtual string about() const;
};
string Animal::about() const 
{
        stringstream ss;
        ss << "Age = " << " " << Age;
        return ss.str();
}

class Mammal : public Animal 
{
    private:
        float PawLength; //centimeters
    public:
        void setPawLength(float NewPawLength) { PawLength = NewPawLength; }
        float getPawLength() const { return PawLength; }
        virtual string about() const;
};
string Mammal::about() const 
{
        stringstream ss;
        ss << Animal::about() << " " << "PawLength = " << " " << PawLength;
        return ss.str();
}

class Bird : public Animal 
{
    private:
        int FlightDuration; //minutes
    public:
        float BeakSize;	// days
        void setFlightDuration(int newFlightDuration) { FlightDuration = newFlightDuration; }
        int getFlightDuration() const { return FlightDuration; }
        virtual string about() const;
};
string Bird::about() const 
{
        stringstream ss;
        ss << Animal::about() << " " << "FlightDuration = " << " " << FlightDuration;
        return ss.str();
}

class Capybara : public Mammal
{
    private:
        float FrontTeethLength; //centimeters
    public:
        void setFrontTeethLength(int newFrontTeethLength) { FrontTeethLength = newFrontTeethLength; }
        int getFrontTeethLength() const { return FrontTeethLength; }
        virtual string about() const;
};
string Capybara::about() const
{
        stringstream ss;
        ss << Mammal::about() << " " << "FrontTeethLength = " << " " << FrontTeethLength;
        return ss.str();
}

class Caracal : public Mammal
{
    private:
        int TailLength; //centimeters
    public:
        void setTailLength(int newTailLength) { TailLength = newTailLength; }
        int getTailLength() const { return TailLength; }
        virtual string about() const;
};
string Caracal::about() const 
{
        stringstream ss;
        ss << Mammal::about() << " " << "TailLength = " << " " << TailLength;
        return ss.str();
}

class Raven : public Bird 
{
    private:
        int WingLength; //centimeters
    public:
        void setWingLength(int newWingLength) { WingLength = newWingLength; }
        int getWingLength() const { return WingLength; }
        virtual string about() const;
};
string Raven::about() const 
{
        stringstream ss;
        ss << Bird::about() << " " << "WingLength = " << " " << WingLength;
        return ss.str();
}

class Ostrich : public Bird 
{
    private:
        float EggWeight; //kg
    public:
        void setEggWeight(float newEggWeight) { EggWeight = newEggWeight; }
        float getEggWeight() const { return EggWeight; }
        virtual string about() const;

};
string Ostrich::about() const 
{
        stringstream ss;
        ss << Bird::about() << " " << "EggWeight = " << " " << EggWeight;
        return ss.str();
}
