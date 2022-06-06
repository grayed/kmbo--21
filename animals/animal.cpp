#include "animal.h"
#include <string>

using namespace std;

int main() {
	Human Stepan(true, 19);
	Stepan.setInRussia(false);
	Stepan.setAge(54);
	string result1 = Stepan.about();
	cout<<"Human: "<<result1<<endl;
	Sphinks cat123(0,true);
	cat123.setWoolLength(1);
	cat123.setBlueEyes(false);
	string result2 = cat123.about();
	cout<<"Cat sphinks: "<<result2<<endl;
}