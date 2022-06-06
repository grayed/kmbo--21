#include <iostream>
#include "electricity.h"

using namespace std;


int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? "" : "not ") << "connected" << endl;


    Switch swtch;
    Light lght;
    Generator gnr;
    gnr.connect("A1", swtch, "A2");
    swtch.connect("A1", lght, "A2");
    lght.connect("A1", gnr, "A2");
    return 0;
}
