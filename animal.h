pragma once

#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal
{
private:
        int age;
        int weight;
public:
        Animal(){};
        Animal(int Age, int Weight)
        {
            Age = age;
            Weight = weight;
        }
        void setAge(int Age){age = Age;}
        void setWeight(int Weight){weight = Weight;}
        float getAge(){return age;}
        int getWeight(){return weight;}
        virtual string about()
        {
            stringstream str;
            str<<"Age="<<age<<";"<<"Weight="<<weight<<endl;
            return str.str();
        }
};

class Mammal: public Animal
{
private:
        bool wool;
public:
        Mammal(){};
        Mammal(bool Wool)
        {
            wool = Wool;
        }
        bool getWool(){return wool;}
        void setWool(bool value){wool = value;}
        virtual string about() const
        {
            stringstream ss;
            ss<<"Wool="<<wool;
            return ss.str();
        }
};

class Human: public Mammal
{
private:
        string sex;
public:
        Human(string Sex)
        {
            sex = Sex;
        }
        void setSex(string Sex){sex = Sex;}
        string getSex(){return sex;}
        virtual string about()
        {
            stringstream ss;
            ss<<"sex="<<getSex();
            return ss.str();
        }
};

class Dog: public Mammal
{
private:
        string eyeColor;
public:
        Dog(){};
        Dog(string EyeColor)
        {
            eyeColor = EyeColor;
        }
        string getEyeColor(){return eyeColor;}
        void setEyeColor(string value){eyeColor = value;}
        virtual string about()
        {
            stringstream ss;
            ss<<"EyeColor="<<getEyeColor();
            return ss.str();
        }
};

class Animal {
class Birds : public Animal
{
private:
        int beakLength;
public:
	float weight;				// kg
        Birds(){};
        Birds(int BeakLength)
        {
            beakLength = BeakLength;
        }
        int getBeakLength(){return beakLength;}
        void setBeakLength(int value){beakLength=value;}
        virtual string about()
        {
            stringstream ss;
            ss<<"beakLength="<<getBeakLength();
            return ss.str();
        }
};

class Mammal : public Animal {
class Penguin : public Birds
{
private:
        int livesFlock;
public:
	float pregnancyDuration;	// days
        Penguin(){};
        Penguin(bool LivesFlock)
        {
            livesFlock = LivesFlock;
        }
        bool getLivesFlock(){return livesFlock;}
        void setLivesFlock(bool value){livesFlock=value;}
        virtual string about()
        {
            stringstream ss;
            ss<<"livesFlock="<<getLivesFlock()<<";"<<"BeakLength="<<getBeakLength()<<endl;
            return ss.str();
        }
};

class Cat : public Mammal {
class Parrot : public Birds
{
private:
        int lifeExpectancy;
public:
	float vibrissaLength;		// meters
        Parrot(){};
        Parrot(int LifeExpectancy)
        {
            lifeExpectancy = LifeExpectancy;
        }
        int getLifeExpectancy(){return lifeExpectancy;}
        void setLifeExpectancy(int value){lifeExpectancy=value;}
        virtual string about()
        {
            stringstream ss;
            ss<<"LifeExpectancy="<<getLifeExpectancy();
            return ss.str();
        }
};
