#include "animal.h"
#include "mammal.h"
#include "bird.h"

void printBirdInfo() {
	Eagle sharpSightedEagle(12);
	sharpSightedEagle.wingLength = 1.2;
	sharpSightedEagle.weight = 0.9;

	Parrot niceGreenParrot(5570463);
	niceGreenParrot.wingLength = 0.1;
	niceGreenParrot.weight = 0.3;

	std::cout << sharpSightedEagle << std::endl << niceGreenParrot << std::endl;
}

void printMammalInfo() {
	Cat littleKitten(0.05);
	littleKitten.pregnancyDuration = 60;
	littleKitten.weight = 0.5;
	
	Dog bigScaryDog(Chauchau);
	bigScaryDog.pregnancyDuration = 50;
	bigScaryDog.weight = 10;

	std::cout << littleKitten << std::endl << bigScaryDog;
}

int main() {

	printBirdInfo();
	printMammalInfo();

	return 0;
}