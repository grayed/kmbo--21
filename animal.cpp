#include "animal.h"
#include <string>
using namespace std;
int main() {
	Cat Barsik("black");
	Barsik.setWoolColor("white");
	string aboutCat = Barsik.about();
	cout << "Barsik : " << aboutCat << endl;

	GoldFish Bulka(true);
	Bulka.setWeight(1);
    Bulka.setLivesInAquarium(false);
	string descFish = Bulka.about();
	cout << "Bulka : " << descFish << endl;
} 