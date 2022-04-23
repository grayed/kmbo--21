#include <sstream>
#include "animal.h"

Animal::Animal(float weight, int age) {
    this->weight = weight;
    this->age = age;
}

std::string Animal::about() const {
    std::stringstream ss;
    ss << "Weight is " << weight << " kg" << ", age is " << age << " years";
    return ss.str();
}

std::ostream &operator<<(std::ostream &out, const Animal &a) {
    return out << a.weight << " : " << a.age;
}

Mammal::Mammal(float weight, int age, int pregnancyDuration) : Animal(weight, age) {
    this->pregnancyDuration = pregnancyDuration;
}

std::string Mammal::about() const {
    std::stringstream ss;
    ss << "Pregnancy duration is " << pregnancyDuration << " days";
    return ss.str();
}

Reptile::Reptile(float weight, int age, float eggDiameter) : Animal(weight, age) {
    this->eggDiameter = eggDiameter;
}

std::string Reptile::about() const {
    std::stringstream ss;
    ss << "Egg diameter is " << eggDiameter << " centimeters";
    return ss.str();
}

Dog::Dog(float weight, int age, int pregnancyDuration, std::string&& breed) : Mammal(weight, age, pregnancyDuration) {
    this->breed = breed;
}

std::string Dog::about() const {
    std::stringstream ss;
    ss << "Breed is " << breed;
    return ss.str();
}

Cat::Cat(float weight, int age, int pregnancyDuration, float vibrissaLength) : Mammal(weight, age, pregnancyDuration) {
    this->vibrissaLength = vibrissaLength;
}

std::string Cat::about() const {
    std::stringstream ss;
    ss << "Vibrissa length is " << vibrissaLength << " centimeters";
    return ss.str();
}

Turtle::Turtle(float weight, int age, float eggDiameter, float shellSize) : Reptile(weight, age, eggDiameter) {
    this->shellSize = shellSize;
}

std::string Turtle::about() const {
    std::stringstream ss;
    ss << "Shell size is " << shellSize << " meters";
    return ss.str();
}

Snake::Snake(float weight, int age, float eggDiameter, float length) : Reptile(weight, age, eggDiameter) {
    this->length = length;
}

std::string Snake::about() const {
    std::stringstream ss;
    ss << "Length is " << length << " meters";
    return ss.str();
}

int main() {
    Dog dog_1 = Dog(25, 7, 60, "Husky");
    Cat cat_1 = Cat(10, 5, 65, 7);
    Turtle turtle_1 = Turtle(100, 45, 2.35, 8);
    Snake snake_1 = Snake(50, 12, 0.38, 5);

    std::cout << dog_1.about() << std::endl;
    std::cout << cat_1.about() << std::endl;
    std::cout << turtle_1.about() << std::endl;
    std::cout << snake_1.about() <<std:: endl;

    std::cout << dog_1 << std::endl;
    std::cout << cat_1 << std::endl;
    std::cout << turtle_1 << std::endl;
    std::cout << snake_1 << std::endl;

    return 0;
}
