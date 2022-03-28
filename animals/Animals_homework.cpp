#include <iostream>
#include <sstream>
#include <string>
using namespace std;

class Animal {
public:
    bool predator;
protected:
    int age;
    Animal() { }
    Animal(int age_, int predator_) { age_ = age; predator_ = predator;}
};
//млекопитающие
class Mammalia : public Animal {
private:
    int wool_length;
    bool omnivorous;
public:
    int get_wool_length() {return wool_length;}
    void set_wool_length(int value) { wool_length=value; }
    bool get_omnivorous() {return omnivorous;}
    void set_omnivorous(bool value) { omnivorous=value; }
    bool get_predator() {return predator;}
    void set_predator(bool value) { predator=value; }
    virtual string about() const {
        stringstream ss;
        ss << "wool_length = " << wool_length << ", " << "omnivorous = " << omnivorous;
        return ss.str();
    }
};
//енот
class Raccoon : public Mammalia {
private:
    bool male;
    int mustache_length;
public:
    Raccoon(bool male_,int mustache_length_,int wool_length_,bool omnivorous_){
        set_male(male_);
        set_mustache_length(mustache_length_);
        set_wool_length(wool_length_);
        set_omnivorous(omnivorous_);
    }
    bool get_male() { return male;};
    void set_male(bool value) { male=value;}
    int get_mustache_length() { return mustache_length;};
    void set_mustache_length (int value) { mustache_length=value;}
    virtual string about() {
        stringstream ss;
        ss << "wool_length = " << get_wool_length() << ", " << "omnivorous = " << get_omnivorous() << ", " << "male = " << male << ", " << "mustache_length = " << mustache_length;
        return ss.str();
    }
};
class Deer : public Mammalia {
private:
    int length_of_horns; // длина рогов
    int speed;
public:
    Deer(int length_of_horns_,int speed_,int wool_length_,bool omnivorous_){
        set_length_of_horns(length_of_horns_);
        set_speed(speed_);
        set_wool_length(wool_length_);
        set_omnivorous(omnivorous_);
    }
    int get_length_of_horns() { return length_of_horns;};
    void set_length_of_horns (int value) { length_of_horns=value;}
    int get_speed() { return speed;};
    void set_speed (int value) { speed=value;}
    virtual string about() {
        stringstream ss; 
        ss << "wool_length = " << get_wool_length() << ", " << "omnivorous = " << get_omnivorous() << ", " << "length_of_horns = " << length_of_horns << ", " << "speed = " << speed;
        return ss.str();
    }
};
class Bird : public Animal {
private:
    bool can_fly;
    int wingspan; //размах крыла
public:
    bool get_can_fly() {return can_fly;}
    void set_can_fly(bool value) {can_fly=value;}
    int get_wingspan() {return wingspan;}
    void set_wingspan(int value) {wingspan=value;}
    bool get_predator() {return predator;}
    void set_predator(bool value) {predator=value;}
    virtual string about() const {
        stringstream ss;
        ss << "can_fly = " << can_fly << ", " << "wingspan = " << wingspan;
        return ss.str();
    }
};
class Sparrow: public Bird {
private:
    int body_length; //длина тела
    bool live_in_city;
public:
    Sparrow(int body_length_,bool live_in_city_,bool can_fly_,int wingspan_){
        set_body_length(body_length_);
        set_live_in_city(live_in_city_);
        set_can_fly(can_fly_);
        set_wingspan(wingspan_);
    }
    int get_body_length() { return body_length;};
    void set_body_length (int value) { body_length=value;}
    bool get_live_in_city() { return live_in_city;};
    void set_live_in_city (int value) { live_in_city=value;}
    virtual string about() {
        stringstream ss;
        ss << "can_fly = " << get_can_fly() << ", " << "winspan = " << get_wingspan() << ", " << "body_length = " << body_length << ", " << "live_in_city = " << live_in_city;
        return ss.str();
    }
};
class Eagle: public Bird {
private:
    int speed;
    int beak_lenght; //длина клюва
public:
    Eagle(int speed_,int beak_length_,bool can_fly_,int wingspan_){
        set_speed(speed_);
        set_beak_length(beak_length_);
        set_can_fly(can_fly_);
        set_wingspan(wingspan_);
    }
    int get_speed() { return speed;};
    void set_speed (int value) { speed=value;}
    int get_beak_length() { return beak_lenght;};
    void set_beak_length (int value) { beak_lenght=value;}
    virtual string about() {
        stringstream ss;
        ss << "can_fly = " << get_can_fly() << ", " << "winspan = " << get_wingspan() << ", " << "speed = " << speed << ", " << "beak_length = " << beak_lenght;
        return ss.str();
    }
};
class Fish : public Animal {
private:
    int weight; //масса
    bool live_in_the_sea;
public:
    int get_weight() {return weight;}
    void set_weight(int value) {weight=value;}
    bool get_live_in_the_sea() {return live_in_the_sea;}
    void set_live_in_the_sea(bool value) {live_in_the_sea=value;}
    bool get_predator() {return predator;}
    void set_predator(bool value) {predator=value;}
    virtual string about() {
        stringstream ss;
        ss << "weight = " << weight << ", " << "live_in_the_sea = " << live_in_the_sea;
        return ss.str();
    }
};
class Shark: public Fish {
private:
    int length_of_canines; //длина клыков
    int kilogram_of_fish_per_day; 
public:
    Shark() { }
    Shark(int length_of_canises_,int kilogram_of_fish_per_day_,int weigth_,bool live_in_the_sea_){
        set_length_of_canises(length_of_canises_);
        set_kilogram_of_fish_per_day(kilogram_of_fish_per_day_);
        set_weight(weigth_);
        set_live_in_the_sea(live_in_the_sea_);
    }
    int get_length_of_canises() { return length_of_canines;};
    void set_length_of_canises (int value) { length_of_canines=value;}
    int get_kilogram_of_fish_per_day() { return kilogram_of_fish_per_day;};
    void set_kilogram_of_fish_per_day(int value) { kilogram_of_fish_per_day=value;}
    virtual string about() {
        stringstream ss;
        ss << "weigth = " << get_weight() << ", " << "live_in_the_sea = " << get_live_in_the_sea() << ", " << "length_of_canises = " << length_of_canines << ", " << "kilogram_of_fish_per_day = " << kilogram_of_fish_per_day;
        return ss.str();
    }
};
class Dolphin: public Fish {
private:
    bool domestic;
    int speed;
public:
    Dolphin() { }
    Dolphin(bool domestic_,int speed_,int weigth_,bool live_int_the_sea_){
        set_domestic(domestic_);
        set_speed(speed_);
        set_weight(weigth_);
        set_live_in_the_sea(live_int_the_sea_);
    }
    bool get_domestic() { return domestic;};
    void set_domestic (bool value) { domestic=value;}
    int get_speed() { return speed;};
    void set_speed(int value) { speed=value;}  
    virtual string about() {
        stringstream ss;
        ss << "weigth = " << get_weight() << ", " << "live_in_the_sea = " << get_live_in_the_sea() << ", " << "domestic = " << domestic << ", " << "speed = " << speed;
        return ss.str();
    }
};
int main(int argc, char* argv[]){
    Shark Animal1(6,100,85,false);
    string s1 = Animal1.about();
    cout << "Shark: " << s1 << endl;
    Dolphin Animal2(true,37,80,false);
    string s2 =Animal2.about(); 
    cout << "Dolphin: " << s2 << endl;

}