#include "animal.h"
#include <string>
using namespace std;
int main()
{
    Dog Amy("blue");
    Amy.setEyeColor("green");
    string aboutDog = Amy.about();
    cout<<"Amy:"<<aboutDog<<endl;

    Penguin Vima(true);
    Vima.setBeakLength(4);
    Vima.setLivesFlock(true);
    string aboutPenguin = Vima.about();
    cout<<"Vima:"<<aboutPenguin<<endl;
}
