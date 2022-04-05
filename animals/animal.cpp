#include "animal.h"

using namespace std;

int main() {
	Cat cat;
	Dog dog;
	Raven raven;
	Sparrow sparrow;
	cat.setpregnancyDuration(70);
	cat.setvibrissaLength(0.2);
	cat.setweight(2);
	dog.setpregnancyDuration(80);
	dog.setrazorLength(0.3);
	dog.setweight(30);
	raven.setfearthLength(0.7);
	raven.setheight(0.3);
	raven.setweight(1);
	sparrow.setfearthLength(0.1);
	sparrow.setrazorLength(0.02);
	sparrow.setweight(0.5);
	cout << dog << endl;
	cout << cat << endl;
	cout << sparrow << endl;
	cout << raven << endl;
}
