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
protected:
	int time_pregnancy;
	double alcohol;
public:
	int get_time_pregnancy() { return time_pregnancy; }
	int set_time_pregnancy(int value) { time_pregnancy = value; }
	double get_alcohol() { return alcohol; }
	double set_alcohol(double value) { alcohol = value; }
	bool get_preadtor() { return predator; }
	bool set_predator(bool flag) { predator = flag; }

	//	virtual string about() const { return (stringstream() << "Pregnancy_month = " << time_pregnancy << "," << " Alcohol % = " <<  alcohol ).str(); }
};

class Bears : public Mammal {
private:
	int time_dormancy;
public:
	Bears(int v_time_pregnancy, double v_alcohol, int v_time_dormancy) { v_time_pregnancy = time_pregnancy, v_alcohol = alcohol, v_time_dormancy = time_dormancy; }
	int get_time_dormancy() { return time_dormancy; }
	int set_time_dormancy(int value) { time_dormancy = value; }

};

class Birds : public Animal {
protected:
	int height_fly;
public:
	int get_height_fly() { return height_fly; }
	int set_height_fly(int value) { height_fly = value; }
	//= virtual string about() const { return (stringstream() << "Height_meters = " << height_fly).str();}

};

class Duck : public Birds {
private:
	string color_feathers;
public:
	Duck(int v_height_fly, string v_color_feathers) { v_height_fly = height_fly, v_color_feathers = color_feathers; }
	string get_color_feathers() { return color_feathers; }
	string set_color_feathers(string value) { color_feathers = value; }
};


int main() {
	Duck mandarin_duck();
	Bears black_beer();
	mandarin_duck().set_height_fly(100);
	black_beer().set_time_dormancy(9);

	int res = mandarin_duck().get_height_fly();
	cout << res << "\n";
	return 0;
}