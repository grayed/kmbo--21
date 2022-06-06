#include <iostream>
#include "memhacks.h"
#include "newhacks.h"

using namespace std;

int main()
{
    cout << "Explore dynamic memory" << std::endl;
    dynamicMemory();

    cout << "Explore stack memory" << std::endl;
    stackMemory();

    Buz* b = new Buz;

    return 0;
};
