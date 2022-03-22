#include "animal.h"

using namespace std;

int main() {
	Human man("Russia", true, "Grey", "male", 74, 23.5, 4);
    cout << man.about() << endl;
    Cat cat(false, 0, "Yellow", "female", 23, 4, 4);
    cout << cat.about() << endl;
    Cockroach cock(12.2, true, true, 5, 10, 6);
    cout << cock.about() << endl;
    Mosquito mosq("male", true, true, 10, 10, 6);
    cout << mosq.about() << endl;

	return 0;
}