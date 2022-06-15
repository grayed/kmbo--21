#include "animal.h"

#include <string>
using namespace std;
int main()
{
    Dog Mia("blue");
    Mia.setEyeColor("green");
    string aboutDog = Mia.about();
    cout<<"Mia:"<<aboutDog<<endl;

int main() {
	return 0;
} 
    Penguin Anton(true);
    Anton.setBeakLength(4);
    Anton.setLivesFlock(true);
    string aboutPenguin = Anton.about();
    cout<<"Anton:"<<aboutPenguin<<endl;
}
