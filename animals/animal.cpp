#include "animal.h"

using namespace std;

int main() {
	Cat kity(10.5, 9, 5.5);
	kity.setWeight(9);
	int weigth = kity.getWeight();
	Shark sharky(550, 40, 350);
	sharky.setJawSize(200);
	sharky.setSize(700);
	Giraffe giraffy (300.56, 15, 1500);
	giraffy.setpregnancyDuration(10);
	cout << sharky.getJawSize() << "\t" << sharky.getSize();
	return 0;
};


