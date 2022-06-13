#include "animal.h"

using namespace std;

int main() {
	Cat Doner(3, 60,"Ginger");
	cout << Doner.about() << endl;

	Capybara Mandarin(55, 120, 6);
	cout << Mandarin.about() << endl;

	Spider Boris(false, true, 7);
	cout << Boris.about() << endl;

	Scorpion Gregor(6, false, 2);
	cout << Gregor.about() << endl;


	return 0;
}