#include "animal.h"

using namespace std;

Animal::Animal(float weight_ ,int numof_limbs_) {
	weight = weight_;
	numof_limbs = numof_limbs_;
}
Insects::Insects(float weight_ ,int numof_limbs_, int numof_wings_) : Animal(weight_ ,numof_limbs_){
		numof_wings = numof_wings_;
}
Beatle::Beatle(float weight_,int numof_limbs_,int numof_wings_,int numof_mustache_) : Insects(weight_ ,numof_limbs_,numof_wings_){
		numof_mustache = numof_mustache_;
}
ButterFly::ButterFly(float weight_,int numof_limbs_,int numof_wings_,string colorof_wings_) : Insects(weight_ ,numof_limbs_,numof_wings_){
		colorof_wings = colorof_wings_;
}

Animal::~Animal() {}

string Animal::about() const {
	stringstream ss;
	ss << "Weight = " << weight << '\n' << "Number of Limbs = " << numof_limbs;
	return ss.str();
}

string Insects::about() const {
	stringstream ss;
	ss << Animal::about() << '\n' << "Number of wings = " << numof_wings;
	return ss.str();
}

string Beatle::about() const {
	stringstream ss;
	ss << Insects::about() << '\n' << "Number of mustache = " << numof_mustache;
	return ss.str();
}

string ButterFly::about() const {
	stringstream ss;
	ss << Insects::about() << '\n' << "Color of wings = " << colorof_wings;
	return ss.str();
}

int main() {
	Beatle dungbeetle(0.002,6,4,2);
	ButterFly cupidinidae(0.000001,6,4,"Blue");
	cout << "Cupidinidae:" << '\n' << cupidinidae.about();
	cout << '\n';
	cout << "Dungbeatle:" << '\n' <<dungbeetle;
	return 0;
}
