#pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal{
    private:
        float Weigth; // kg
    protected:
        Animal() {}
        Animal(float newWeight) { Weigth = newWeight; }
    public:

        void setWeigth(float newValue) { Weigth = newValue;}

        float getWeigth() const { return Weigth;}

        virtual string about() const { stringstream ss; ss << "Weigth = " << Weigth; return ss.str(); }
};

inline std::ostream& operator <<(ostream &os, const Animal &a){
    return os << "Weigth = " << a.getWeigth() << endl;
}

class Bird : public Animal{
    private:
        int Wingspan; // cm
    protected:
        Bird() {}
        Bird(int newWingspan, float newWeight):Animal(newWeight){ Wingspan = newWingspan; }
    public:
        void setWingspan(int newValue) { Wingspan = newValue;}

        float getWingspan() const { return Wingspan;}

        virtual string about() const {
            stringstream ss; 
            ss << Animal::about() << ',' << '\n' << "Wingspan = " << Wingspan ; return ss.str(); 
        }
};

class Reptile : public Animal{
    private:
        bool IsAquaticReptile;
    protected:
        Reptile() {}
        Reptile(bool IsAquatic, float newWeight):Animal(newWeight){ IsAquaticReptile = IsAquatic; }
    public:
        void setIsAquaticReptile(bool sign) { IsAquaticReptile = sign;}

        bool getIsAquaticReptile() const { return IsAquaticReptile;}

        virtual string about() const { 
            stringstream ss; 
            ss << Animal::about() << '\n' << "Is aquatic reptile = " <<  IsAquaticReptile; 
            return ss.str();
        }
};

class Crocodile : public Reptile{
    private:
        string Color;
    public:
        Crocodile(float newWeight, bool IsAquatic, string newColor):Reptile(IsAquatic, newWeight){
            Color = newColor;
        }

        void setColor(string newColor) { Color = newColor;}

        string getColor() const { return Color;}

        virtual string about() const {
            stringstream ss;
            ss << '\n' << Reptile::about() << '\n' << "Color = " << Color;
            return ss.str();
        }
};

class Chameleon : public Reptile{
    private:
        double ColorChangeTime; // sec
    public:
        Chameleon(float newWeight, bool IsAquatic, double newColorTime):Reptile(IsAquatic, newWeight){
            ColorChangeTime = newColorTime;
        }

        void setColorChancgeTime(float newValue) { ColorChangeTime = newValue;}

        float getColorChangeTime() const { return ColorChangeTime;}

        virtual string about() const {
            stringstream ss;
            ss  << Reptile::about() << '\n' << "Color change time = " << ColorChangeTime;
            return ss.str();
        }
};

class Ostrich : public Bird{
    private:
        double runningSpeed; // km/h
    public:
        Ostrich(float newWeight, int newWingspan, double newSpeed):Bird(newWingspan, newWeight){
            runningSpeed = newSpeed;
        }

        void setrunningSpeed(double newValue) { runningSpeed = newValue; }

        double getrunningSpeed() const { return runningSpeed; }

        virtual string about() const {
            stringstream ss;
            ss << Bird::about() << '\n' << "Running speed = " << runningSpeed;
            return ss.str();
        }
};

class Pinguin : public Bird{
    private:
        double swimmingSpeed; // km/h
    public:

        Pinguin(float newWeight, int newWingspan, double newSpeed):Bird(newWingspan, newWeight){
            swimmingSpeed = newSpeed;
        }

        void setswimmingSpeed(double newValue) { swimmingSpeed = newValue; }

        double getswimmingSpeed() const { return swimmingSpeed; }

        virtual string about() const {
            stringstream ss;
            ss << Bird::about() << '\n' << "Swimming speed = " << swimmingSpeed;
            return ss.str();
        }
};


