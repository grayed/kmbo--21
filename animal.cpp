#include "animal.h"

#include <string>
using namespace std;
int main()
{
    Dog Mia("blue");
    Amy.setEyeColor("green");
    string aboutDog = Mia.about();
    cout<<"Amy:"<<aboutDog<<endl;

int main() {
	return 0;
} 
    Penguin Anton(true);
    Anton.setBeakLength(4);
    Anton.setLivesFlock(true);
    string aboutPenguin = Anton.about();
    cout<<"Anton:"<<aboutPenguin<<endl;
}
