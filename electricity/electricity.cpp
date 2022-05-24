#include <iostream>
#include "electricity.h"

using namespace std;


int main()
{
    Switch sw, sw2;
    sw.connect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? " " : "not ") << "connected" << endl;
    sw.disconnect("A2", sw2, "A1");
    cout << "is " << (sw.isConnectedTo(sw2) ? " " : "not ") << "connected" << endl;
    
    Switch sw1;
    Light lamp;
    Generator generator;
    generator.connect("A2", lamp, "A1"); // Нейтраль с 1ым полюсом лампы
    cout << "is " << (generator.isConnectedTo(lamp) ? " " : "not ") << "connected" << endl;
    generator.connect("A1", lamp, "A2"); // Фаза со 2ым полюсаом лампы
    generator.connect("A2", sw1, "A1");  // Нейтраль с 1ым полюсом переключателя
    generator.connect("A3", sw1, "A2"); //Земля со 2ым полюсом переключателя

    return 0;

    return 0;
}
