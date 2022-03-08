#include "animal.h"
#include <iostream>
#include <string>
#include <sstream>
using namespace std;


int main() {
	Duck mandarin_duck();
	Bears black_beer();
	mandarin_duck().set_height_fly(100);
	black_beer().set_time_dormancy(9);

	int res = mandarin_duck().get_height_fly();
	cout << res << "\n";
	return 0;
}