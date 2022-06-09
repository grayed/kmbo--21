#include "animal.h"
#include "string"

using namespace std;

int main() {
	BrownBear Vinny(20);
	Lion Mufasa(true);
	Vinny.setHeight(200);
	string s = Vinny.about();
	Vinny.setPregnancyDuration(90);
	cout<<"Vinny: "<<s;
	Mufasa.setisCarnivore(false);
	Mufasa.setAge(30);
	cout<<"Mufasa: "<<Mufasa.about();


}