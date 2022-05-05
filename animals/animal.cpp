#include "animal.h"

using namespace std;

Animal::Animal(float _weight, int _age) {
        weight = _weight;
        age = _age;
    }

string Animal::about() const {
        stringstream ss;
        ss << "Weight: " << weight << " kg" << ", age: " << age << " years";
        return ss.str();
    }

ostream& operator << (ostream &out, const Animal &animal) {
    return out << animal.about();
}

Mammal::Mammal(float _weight, int _age, int _pregnancyLength) : Animal(_weight, _age) {
        pregnancyLength = _pregnancyLength;
    }

string Mammal::about() const {
        stringstream ss;
		ss << Animal::about();
        ss << ", pregnancyLength: " << pregnancyLength << " days";
        return ss.str();
    }

Reptile::Reptile(float _weight, int _age, float _eggHeight) : Animal(_weight, _age) {
        eggHeight = _eggHeight;
    }

string Reptile::about() const {
        stringstream ss;
		ss << Animal::about();
        ss << ", eggHeight: " << eggHeight << " centimeters";
        return ss.str();
    }

Cat::Cat(float _weight, int _age, int _pregnancyLength, float _vibrissaeLength) : Mammal(_weight, _age, _pregnancyLength) {
        vibrissaeLength = _vibrissaeLength;
        }

string Cat::about() const {
        stringstream ss;
		ss << Mammal::about();
        ss << ", vibrissaeLength: " << vibrissaeLength << " centimeters";
        return ss.str();
    }

Dog::Dog(float _weight, int _age, int _pregnancyLength, string _breed) : Mammal(_weight, _age, _pregnancyLength) {
        breed = move(_breed);
    }

string Dog::about() const {
        stringstream ss;
		ss << Mammal::about();
        ss << ", breed: " << breed;
        return ss.str();
    }

Turtle::Turtle(float _weight, int _age, float _eggHeight, float _shellSize) : Reptile(_weight, 4, _eggHeight) {
        shellSize = _shellSize;
    }

string Turtle::about() const {
        stringstream ss;
		ss << Reptile::about();
        ss << ", shellSize: " << shellSize << " meters";
        return ss.str();
    }

Snake::Snake(float _weight, int _age, float _eggHeight, float _length) : Reptile(_weight, _age, _eggHeight) {
        length = _length;
    }

string Snake::about() const {
        stringstream ss;
		ss << Reptile::about();
        ss << ", length: " << length << " meters";
        return ss.str();
    }

int main()
{
    // tests:
    Dog dog_1 = Dog(25, 4, 60, "Husky");
    Cat cat_1 = Cat(10, 8, 65, 7);
    Turtle turtle_1 = Turtle(100, 2, 8, 2.35);
    Snake python = Snake(50, 12, 0.38, 5);

    cout << "dog_1: " << dog_1.about() << endl;
    cout << "cat_1: " << cat_1.about() << endl;
    cout << "turtle_1: " << turtle_1.about() << endl;
    cout << "python: " << python.about() << endl;
    cout << "" << endl;
    cout << "dog_1: " << dog_1 << endl;
    cout << "cat_1: " << cat_1 << endl;
    cout << "turtle_1: " << turtle_1 << endl;
    cout << "python: " << python << endl;

    return 0;
}