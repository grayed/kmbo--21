#include <array.h>
#include <iostream>
using namespace std;



int main() {
    Vector<12> v1;
    v1[1] = v1[2] = 54;
    Vector<12> v2 = v1;
    cout << v2 << endl;
	return 0;
}
