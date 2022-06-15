#include "animal.h"
#include <string>
using namespace std;

int main() {
	Penguin Skipper(3, 0.4, false, 40, "Male");
	cout << "Skipper: " << Skipper.about() << endl << endl;

	Parrot Kesha(0.04, 0.18, true, 30, true);
	cout << "Kesha: " << Kesha.about() << endl << endl;

	Dog Masyanya(30, 0.57, 63, 10, "White");
	cout << "Masyanya: " << Masyanya.about() << endl << endl;

	Human Vasilisa(50, 1.70, 280, 30, 126);
	cout << "Vasilisa: " << Vasilisa.about() << endl << endl;

	return 0;
}