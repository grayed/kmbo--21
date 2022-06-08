#pragma once
#include <iostream>
#include <sstream>
using namespace std;


class Animal {
private:
    bool CanMoveFreely;
protected:
    Animal() { CanMoveFreely = 0; }
    Animal(bool YesOrNo) { CanMoveFreely = YesOrNo; }
public:
    
    void setCanMoveFreely(bool YesOrNo) { CanMoveFreely = YesOrNo; }
    bool get_CanMoveFreely() const { return CanMoveFreely; }
    virtual string about() const { return (stringstream() << "CanMoveFreely =" << CanMoveFreely).str(); }

};


class Mammal :public Animal {
private:
    bool FeedsWithMilk;
protected:
    Mammal() { FeedsWithMilk = 0; }
    Mammal(bool FeedOrNot) { FeedsWithMilk = FeedOrNot; }
public:   
    void setFeedsWithMilk(bool FeedOrNot) { FeedsWithMilk = FeedOrNot; }
    bool get_FeedsWithMilk() const { return FeedsWithMilk; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << "FeedsWithMilk =" << FeedsWithMilk).str(); }
};

class Cat :public Mammal {
private:
    int MiceCaughtCounter;

public:
    Cat(int MiceCaught) { MiceCaughtCounter = MiceCaught; }
    void set_MiceCaughtCounter(int MiceCaught) { MiceCaughtCounter = MiceCaught; }
    int get_MiceCaughtCounter() const { return MiceCaughtCounter; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "MiceCaughtCounter =" << MiceCaughtCounter).str(); }
};

class Horse :public Mammal {
private:
    float kilometresRun;
public:
    Horse(float distance) { kilometresRun = distance; }
    void setkilometresRun(float distance) { kilometresRun = distance; }
    float get_kilometresRun() const { return kilometresRun; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << Mammal::about() << ", " << "kilometresRun =" << kilometresRun).str(); }
};


class Birds : public Animal {
private:
    int FeathersCounter;
protected:
    Birds() { FeathersCounter = 0; }
    Birds(int Feathers) { FeathersCounter = Feathers; }
public:
    void setFeathersCounter(int Feathers) { FeathersCounter = Feathers; }
    int get_FeathersCounter() const { return FeathersCounter; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << "FeathersCounter =" << FeathersCounter).str(); }
};
class Pigeon :public Birds {
private:
    bool CanBegForBread;
public:  
    Pigeon(int CheekyOrNot) { CanBegForBread = CheekyOrNot; }
    bool get_CanBegForBread() const { return CanBegForBread; }
    void setCanBegForBread(int CheekyOrNot) { CanBegForBread = CheekyOrNot; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << Birds::about() << ", " << "CanBegForBread =" << CanBegForBread).str(); }
};
class Caliber :public Birds {
private:
    int WingBeatSpeedPerSecond;
public: 
    Caliber(int BeatCounter) { WingBeatSpeedPerSecond = BeatCounter; }
    int get_WingBeatSpeedPerSecond() const { return WingBeatSpeedPerSecond; }
    void setWingBeatSpeedPerSecond(int BeatCounter) { WingBeatSpeedPerSecond = BeatCounter; }
    virtual string about() const { return (stringstream() << Animal::about() << ", " << Birds::about() << ", " << "WingBeatSpeed =" << WingBeatSpeedPerSecond).str(); }
};