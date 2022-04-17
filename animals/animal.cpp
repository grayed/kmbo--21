#include "animal.h"
#include <string>
using namespace std;

int main() {
	Human Ivan(false,89);
	Ivan.setIq(101);
	Ivan.setIsWorking(true);
	string desc = Ivan.about();
	cout << "Human : " << desc << endl;
	Parrot Kesha(true);
	Kesha.setLivesInCity(false);
	Kesha.setCanFly(true);
	string descParrot = Kesha.about();
	cout << "Parrot :" << descParrot << endl;
}