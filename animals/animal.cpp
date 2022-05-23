#include "animal.h"

using namespace std;


int main()
{
	Cat m(4, "Predator", 1.34, 9);
	Cow mu(4, "herbivore", 30, 10);
	cout << m;
	cout << mu;

	Turtle t(4, true, "terrestre");
	Snake s(0, false, 10);
	cout << t;

	return 0;
}
