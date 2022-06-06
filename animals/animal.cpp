#include "animal.h"
using namespace std;
int main() {
	Shark example1(240, 40.2, 32.7);
	example1.setFinSize(30.6);
	example1.setWeight(200);
	Bass example2(12.3, 15.12, 6.2);
	Horse example3(82.9, 12, 50.5);
	Cat example4(5.2, 8, 4.9);
	cout << example1.getFinSize() << " " << example1.getWeight();
	return 0;
};