#include<iostream>
#include <sstream>
#include <string>
using namespace std;

class Animals {
public:
	int age;
protected:
	Animals() {};
	Animals(int valueAge) { age = valueAge; }
public:
	void setAge(int temp) { age = temp; }
	bool getAge() const { return age;}
	virtual string about() const;
};

string Animals::about() const {
	stringstream ss;
	ss << "Age = " << age;
	return ss.str();
}


class Birds :public Animals {
private:
	bool fly;
protected:
	Birds() {};
	Birds(int valueAge, bool valueFly) {
		fly = valueFly; 
		setAge(valueAge);
	}
public:
	void setFly(bool temp) { fly = temp; }
	bool getFly() const { return fly; }
	virtual string about() const;
};

string Birds::about() const {
	stringstream ss;
	ss << Animals::about()<< " " << "Fly = " << fly;
	return ss.str();
}


class Golub :public Birds {
private:
	int peroNums;
public:
    Golub(int age, bool fly, int valuePeroNums) {
		setAge(age);
		setFly(fly);
		peroNums = valuePeroNums;
	}
	void setPeroNums(int number) { peroNums = number; }
	int getPeroNums() const { return peroNums; }
	virtual string about() const;
};

string Golub::about() const {
	stringstream ss;
	ss << Birds::about() << " " << "peroNums = " << peroNums;
	return ss.str();
}


class Pinguin :public Birds {
private:
	bool king;
public:
	Pinguin(int age, bool fly, bool valueKing) { 
		setAge(age);
		setFly(fly); 
		king = valueKing; 
	}
	void setKing(bool temp) { king = temp; }
	bool getKing() const { return king; }
	virtual string about() const;
};

string Pinguin::about() const {
	stringstream ss;
	ss << Birds::about() << " " << "king = " << king;
	return ss.str();
}


class MilkDrinkers :public Animals{
private:
	int milkAmmount;
protected:
	MilkDrinkers() {}
	MilkDrinkers(int age, int valueMilkAmmount) { 
		setAge(age);
		milkAmmount = valueMilkAmmount; 
	}
public:
	void setMilkAmmount(int number) {milkAmmount = number; }
	int getMilkAmmount() const { return milkAmmount; }
	virtual string about() const;
};

string MilkDrinkers::about() const {
	stringstream ss;
	ss << Animals::about() << " " << "milkAmmount = " << milkAmmount;
	return ss.str();
}


class Cats :public MilkDrinkers {
private:
	int vibrLen;
public:
    Cats(int age, int milkAmmount, int valueVibtLen){
		setAge(age);
		setMilkAmmount(milkAmmount);
		vibrLen = valueVibtLen;
	}
	void setVibrLen(int number) { vibrLen = number; }
	int getVibrLen() const { return vibrLen; }
	virtual string about() const;
};

string Cats::about() const {
	stringstream ss;
	ss << MilkDrinkers::about() << " " << "vibrLen = " << vibrLen;
	return ss.str();
}


class Dogs :public MilkDrinkers {
private:
	bool small;
public:
    Dogs(int age, int milkAmmount, bool valueSmall){
		setAge(age);
		setMilkAmmount(milkAmmount);
		small = valueSmall;
	}
	void setSmall(bool temp) { small = temp; }
	bool getSmall() const { return small; }
	virtual string about() const;
};

string Dogs::about() const {
	stringstream ss;
	ss << MilkDrinkers::about() << " " << "small = " << small;
	return ss.str();
}

inline std::ostream& operator <<(std::ostream& os, const Animals& animal) {
	return os << animal.about();
}

int main() {
	return 0;
}
