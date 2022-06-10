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
    gnr.connect("A2", lght, "A1");
    swtch.connect("A1", lght, "A2");
    cout << "Generator is" << (gnr.isConnectedTo(lght) ? " " : "not ") << "connected light" << endl;
    cout << "Light is" << (lght.isConnectedTo(gnr) ? " " : "not ") << "connected to generator" << endl;
    cout << "Generator is" << (gnr.isConnectedTo(swtch) ? " " : "not ") << "connected to switch" << endl;
    cout << "Switch is" << (swtch.isConnectedTo(gnr) ? " " : "not ") << "connected to generator" << endl;
    cout << "Switch is" << (swtch.isConnectedTo(lght) ? " " : "not ") << "connected to light" << endl;
    cout << "Light is" << (lght.isConnectedTo(swtch) ? " " : "not ") << "connected to switch" << endl;

    gnr.disconnect("A2");
    cout << "Generator disconnected" << endl;
    cout << "Generator is" << (gnr.isConnectedTo(lght) ? " " : " not ") << "connected light" << endl;
    cout << "Light is" << (lght.isConnectedTo(gnr) ? " " : " not ") << "connected to generator" << endl;
    return 0;
}
