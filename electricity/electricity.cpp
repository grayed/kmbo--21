#include <iostream>
#include "electricity.h"

using namespace std;


int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? " " : "not ") << "connected" << endl;
    sw.disconnect("A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? " " : "not ") << "connected" << endl;
    
    cout << "Other::::::\n";
    Switch sw1;
    Light lamp;
    Generator generator;
    //Генератор [фаза] - выключатель - лампа - [нейтраль] Генератор
    generator.connect("A1", sw1, "A1"); 
    sw1.connect("A2", lamp, "A1"); 
    lamp.connect("A2", generator, "A2");
    cout << "is " << (lamp.isConnectedTo(sw1) ? " " : "not ") << "connected" << endl;
    generator.disconnect("A1");
    cout << "is " << (generator.isConnectedTo(sw1) ? " " : "not ") << "connected" << endl;

    return 0;
}
