#include "animal.h"
#include <sstream>
#include <iostream>
using namespace std;

int main() {
    Cat Scottish(5);
    Horse Spirit(1234);
    Scottish.set_MiceCaughtCounter(7);
    Spirit.setkilometresRun(1500);
    int res = Scottish.get_MiceCaughtCounter();
    int res2 = Spirit.get_kilometresRun();
    cout << res << " " << res2 << "\n";
    return 0;
}