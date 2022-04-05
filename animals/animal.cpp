#include "animal.h"

using namespace std;

int main() {
	Amphibia amphibia;
	amphibia.setNumber_of_limbs(4);
	cout << amphibia.getNumber_of_limbs() << "\n";

	Wolf wolf;
	wolf.setAverage_life_expectancy(17);
	cout << wolf.getAverage_life_expectancy() << "\n";

	Frog frog;
	frog.setNumber_of_offspring(4);
	cout << frog.getNumber_of_offspring() << "\n";

	Hare hare;
	hare.setRunning_speed_km_ch(12);
	cout << hare.getRunning_speed_km_ch() << "\n";
	return 0;

	cout << amphibia.about();
}