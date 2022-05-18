#include "animal.h"
#include "mammal.h"
#include "bird.h"

void printBirdInfo() {
	Eagle sharpSightedEagle(12, 1.2, 0.9);

	Parrot niceGreenParrot(5570463, 0.1, 0.3);

	std::cout << sharpSightedEagle << std::endl << niceGreenParrot << std::endl;
}

void printMammalInfo() {
	Cat littleKitten(0.05, 60, 0.5);
	
	Dog bigScaryDog(Chauchau, 50, 10);

	std::cout << littleKitten << std::endl << bigScaryDog;
}

int main() {

	printBirdInfo();
	printMammalInfo();

	return 0;
}