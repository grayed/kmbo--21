#include "animal.h"

using namespace std;

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
	Beatle dungbeetle;
	dungbeetle.weight = 0.002;
	dungbeetle.numof_limbs = 6;
	dungbeetle.numof_wings = 4;
	dungbeetle.numof_mustache = 2;
	ButterFly cupidinidae;
	cupidinidae.weight = 0.000001;
	cupidinidae.numof_limbs = 6;
	cupidinidae.numof_wings = 4;
	cupidinidae.colorof_wings = "Blue";
	Snake grass_snake;
	grass_snake.weight = 0.15;
	grass_snake.numof_limbs = 0;
	grass_snake.isShell = false;
	grass_snake.tongueLength = 0.01;
	grass_snake.isPoisonous = false;
	Turtle sea_turtle;
	sea_turtle.weight = 100;
	sea_turtle.numof_limbs = 4;
	sea_turtle.isShell = true;
	sea_turtle.tongueLength = 0.05;
	sea_turtle.shellStrength = 80;
	Cat vibrissa;
	vibrissa.weight = 6;
	vibrissa.numof_limbs = 4;
	vibrissa.pregnancyDuration = 60;
	vibrissa.numof_niples = 6;
	vibrissa.vibrissaLength = 0.4;
	Dog doberman;
	doberman.weight = 40;
	doberman.numof_limbs = 4;
	doberman.pregnancyDuration = 60;
	doberman.numof_niples = 8;
  doberman.dobermanLength = 1;
	cout << "Cupidinidae:" << '\n' << cupidinidae.about();
	cout << '\n';
	cout << "Dungbeatle:" << '\n' <<dungbeetle;
	return 0;
}
