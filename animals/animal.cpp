#include "animal.h"
#include <string>
using namespace std;

int main() 
{
	Dog Lana("brown");
	Lana.setСoat_color("black");
	string aboutDog = Lana.about();
	cout << "Lana : " << aboutDog << endl;

	Snake Eve(true);
	Eve.setMolt(false);
	string MoltEve = Eve.about();
	cout << "Snake : " << MoltEve << endl;

	Turtle Sage(26, 40);
	Sage.setAge(137);
	Sage.setNumber_life(752);
	string truth_about_Sage = Sage.about();
	cout << "Sage : " << truth_about_Sage << endl;
}  
