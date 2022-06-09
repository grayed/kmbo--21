#include<iostream>
#include<sstream>
using namespace std;

class Animal
{
private:
	float height;
protected:
	Animal(float _height);
public:
	float getHeight() const { return height; }
	void setHeight(float newValue) { height = newValue; }
	virtual string about() const;	
};
ostream& operator <<(ostream& os, const Animal& animal);
class Mammal : public Animal {
private:
	float duration_of_pregnancy;
protected:
	Mammal(float _height, float _duration_of_pregnancy);
public:
	float getduration_of_pregnancy() const { return duration_of_pregnancy; }
	void setduration_of_pregnancy(float newValue) { duration_of_pregnancy = newValue; }
	virtual string about() const;
};
class birds : public Animal {
private:
	float feather_lenght ;
protected:
	birds(float _height, float _feather_lenght);
public:
	bool getfeather_lenght() const { return feather_lenght; }
	void setfeather_lenght(float newValue) { feather_lenght = newValue; }
	virtual string about() const;
};
class Dog :public Mammal {
private:
	float ear_lenght;
public:
	Dog(float _height, float _duration_of_pregnancy, float ear_lenght);
	float getear_lenght() const { return ear_lenght; }
	void setear_lenght(float newValue) { ear_lenght = newValue; }
	virtual string about() const;
};
class Cat :public Mammal {
private:
	float vibrissaLength;
public:
	Cat(float _height, float _duration_of_pregnancy, float _vibrissaLength);
	float getvibrissaLength() const { return vibrissaLength;}
	void setvibrissaLength(float newValue) { vibrissaLength = newValue; }
	virtual string about() const;
};

class Martlet : public birds {
private:
	float max_flight_altitude;
public:
	Martlet(float _height, float _feather_lenght, float _max_flight_altitude);
	float getmax_flight_altitude() const { return max_flight_altitude; }
	void setmax_flight_altitude(float newValue) { max_flight_altitude = newValue; }
	virtual string about() const;
};
class goose :public birds {
private:
	float max_flight_duration;
public:
	goose(float _height, float _feather_lenght, float _max_flight_duration);
	float getmax_flight_duration() const { return max_flight_duration; }
	void setmax_flight_duration(float newValue) { max_flight_duration = newValue; }
	virtual string about() const;
};
