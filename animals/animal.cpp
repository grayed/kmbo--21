#include <iostream>
#include <sstream>
#include <string>

using namespace std;

class Animal
{
private:
	int Age; //возраст в годах
	float Weight; //вес в кг

public:

    int  getAge()  const { return Age; }
    void setAge(int ValueAge) { Age = ValueAge; }

    float getWeight() const { return Weight; }
    void setWeight(float ValueWeight) { Weight = ValueWeight; }

    virtual string about() const { return (stringstream() << "Age = "<< Age <<", "<<"Weight = "<<Weight).str(); }

protected:

    Animal() {};
    Animal(int ValueAge, float ValueWeight)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
    }

};

class Mammal : public Animal
{
private:
	int DurFeeding; //длительность вскармливания в неделях
	string CoatColor; //цвет шерсти

public:

    int  getDurFeeding()  const { return DurFeeding; }
    void setDurFeeding(int ValueDurFeeding) { DurFeeding = ValueDurFeeding; }

    string getCoatColor() const { return CoatColor; }
    void setCoatColor(string Color) { CoatColor = Color; }

    virtual string about() const { return (stringstream() << Animal::about() << ", " << "Duration of feeding = " << DurFeeding << ", " << "Coat color = " << CoatColor).str(); }

protected:

    Mammal() {};
    Mammal(int ValueAge, float ValueWeight, int ValueDurFeeding, string Color)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setDurFeeding(ValueDurFeeding);
        setCoatColor(Color);
    };

};


class Reptile : public Animal
{
private:
	int NumEggs; //количество яиц в кладке
	int DurMolting; //длительность линьки в днях, включая подготовку к ней

public:

    int  getNumEggs()  const { return  NumEggs; }
    void setNumEggs(int ValueEggs) { NumEggs = ValueEggs; }

    int getDurMolting() const { return DurMolting; }
    void setDurMolting(int ValueMolting) { DurMolting = ValueMolting; }

    virtual string about() const { return (stringstream() << Animal::about() << ", " << "Number of eggs = " << NumEggs << ", " << "Duration of molting = " << DurMolting).str(); }


protected:
    Reptile() {};
    Reptile(int ValueAge, float ValueWeight, int ValueEggs, int ValueMolting)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setNumEggs(ValueEggs);
        setDurMolting(ValueMolting);
    };


};


class Hedgehog : public Mammal
{
private:
	int NumNeedles; //количество иголок

public:

    int  getNumNeedles()  const { return  NumNeedles; }
    void setNumNeedles(int ValueNeedles) { NumNeedles = ValueNeedles; }

    Hedgehog() {};
    Hedgehog(int ValueAge, float ValueWeight, int ValueDurFeeding, string Color, int ValueNeedles)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setDurFeeding(ValueDurFeeding);
        setCoatColor(Color);
        setNumNeedles(ValueNeedles);
    };
    
    virtual string about() const { return (stringstream() << Mammal::about() << ", " << "Number of needles = " << NumNeedles).str(); }


};

class Giraffe : public Mammal
{
private:
	float NeckLength; //длина шеи в метрах
public:

    float getNeckLength()  const { return  NeckLength; }
    void setNeckLength(float ValueLength) { NeckLength = ValueLength; }

    Giraffe() {};
    Giraffe(int ValueAge, float ValueWeight, int ValueDurFeeding, string Color, float ValueLength)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setDurFeeding(ValueDurFeeding);
        setCoatColor(Color);
        setNeckLength(ValueLength);
    };

    virtual string about() const { return (stringstream() << Mammal::about() << ", " << "Neck length = " << NeckLength).str(); }
};


class Cobra : public Reptile
{
private:
	float Length; //длина в метрах
public:

    float getLength()  const { return  Length; }
    void setLength(float ValueLength) { Length = ValueLength; }

    Cobra() {};
    Cobra(int ValueAge, float ValueWeight, int ValueEggs, int ValueMolting, float ValueLength)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setNumEggs(ValueEggs);
        setDurMolting(ValueMolting);
        setLength(ValueLength);
    };

    virtual string about() const { return (stringstream() << Reptile::about() << ", " << "Length = " << Length).str(); }
};

class Crocodile : public Reptile
{
private:
	int NumTeeth;
public:

    int getNumTeeth()  const { return  NumTeeth; }
    void setNumTeeth(int ValueTeeth) { NumTeeth = ValueTeeth; }

    Crocodile() {};
    Crocodile(int ValueAge, float ValueWeight, int ValueEggs, int ValueMolting, int ValueTeeth)
    {
        setAge(ValueAge);
        setWeight(ValueWeight);
        setNumEggs(ValueEggs);
        setDurMolting(ValueMolting);
        setNumTeeth(ValueTeeth);
    };

    virtual string about() const { return (stringstream() << Reptile::about() << ", " << "Number of teeth = " << NumTeeth).str(); }
};



int main()
{
    Hedgehog a1(3, 0.8, 6, "gray", 4000);
    cout << "Hedgehog: " << a1.about() << endl;

    Giraffe a2(15, 700, 48, "yellow-brown", 1.9);
    cout << "Giraffe: " << a2.about() << endl;

    Cobra a3(17, 6, 20, 10, 3);
    cout << "Cobra: " << a3.about() << endl;

    Crocodile a4(55, 400, 10, 5, 67);
    cout << "Crocodile : " << a4.about() << endl;

	return 0;
}