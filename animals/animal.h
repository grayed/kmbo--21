#include <iostream>
#include <string>
#include <sstream>
using namespace std;

class Animal {
protected:
	Animal() {  }
	Animal(bool v_preadator, bool  v_cam_fly) { v_preadator = predator, v_cam_fly = can_fly; }
	bool predator;
	bool can_fly;
public:
	double weight;
};

class Mammal : public Animal {
private:
	int time_pregnancy;
	double alcohol;
public:
	int get_time_pregnancy() { return time_pregnancy; }
	int set_time_pregnancy(int value) { time_pregnancy = value; }
	double get_alcohol() { return alcohol; }
	double set_alcohol(double value) { alcohol = value; }
	bool get_preadtor() { return predator; }
	bool set_predator(bool flag) { predator = flag; }

	virtual string about() const { return (stringstream() << "Pregnancy_month = " << time_pregnancy << "," << " Alcohol % = " <<  alcohol ).str(); }
};

class Bears : public Mammal {
private:
	int time_dormancy;
public:
	Bears(int v_time_pregnancy, double v_alcohol, int v_time_dormancy) { v_time_pregnancy = get_time_pregnancy(), v_alcohol = get_alcohol(), v_time_dormancy = get_time_dormancy(); }
	int get_time_dormancy() { return time_dormancy; }
	int set_time_dormancy(int value) { time_dormancy = value; }
	virtual string about()  { return(stringstream() << "Time of doramncy=" << time_dormancy<< "Pregnancy_month = " << get_time_pregnancy() << "," << " Alcohol % = " << get_alcohol()).str(); }

};

class Birds : public Animal {
private:
	int height_fly;
public:
	int get_height_fly() { return height_fly; }
	int set_height_fly(int value) { height_fly = value; }
};

class Duck : public Birds {
private:
	string color_feathers;
public:
	Duck(int v_height_fly, string v_color_feathers) { v_height_fly = get_height_fly(), v_color_feathers = color_feathers; }
	string get_color_feathers() { return color_feathers; }
	string set_color_feathers(string value) { color_feathers = value; }
	virtual string about()  { return (stringstream() << "Height_meters = " << get_height_fly() << "Color of feathers:" << color_feathers).str(); }

};


