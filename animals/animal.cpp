#include "animal.h"

using namespace std;

int main() {
    Elephant eleph(150, 3000., 22);
    eleph.setWeight(3004.);
    eleph.setTrunkLength(145);
    cout << eleph.getTrunkLength() << " " << eleph.getPregnancyDuration() << " " << eleph.getWeight() << "\n";

    Cat cat(14, 7, 1);
    cout << cat.getVibrissaLength() << " " << cat.getWeight() << " " << cat.getPregnancyDuration() << "\n";

    Penguin penguin(1, 40);
    cout << penguin.getHeight() << " " << penguin.getWeight() << " " << penguin.getCanFly() << "\n";

    Colibri colibri("blue", 0.02);
    cout << colibri.getColor() << " " << colibri.getWeight() << " " << colibri.getCanFly() << "\n";

	return 0;
}