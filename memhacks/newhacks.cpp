#include <iostream>
#include "newhacks.h"

User::User(std::string name) {
	login = name;
	std::cerr << "Hello, " << login << std::endl;
}


User::User() {
	std::cerr << "This is constructor " <<std::endl;
}


User::~User(){
	std::cerr << "This is destructor. Goodbye! " << std::endl;
}

void* User::operator new[](size_t size) {
	auto p = malloc(size);
	std::cerr << "U've created an account" << std::endl;
	return p;
}
void User::operator delete[](void* p) {
	std::cerr << "U've deleted the account" << std::endl;
	free(p);
}

OK::OK(std::string name) {
	login = name; 
	std::cerr << "Hi, " << login << "! This is OK" << std::endl;
}


OK::OK() {
	std::cerr << "This is OK constructor" << std::endl;
	std::cout << std::endl;
}

OK:: ~OK() {
	std::cout << std::endl;
	std::cerr << "This is OK destructor. We'll miss u!" << std::endl;
	
}

void* OK:: operator new[](size_t size) {
	void* p = malloc(size);
	std::cerr << "Welcome to OK!" << std::endl;
	return p;
}

void OK:: operator delete[](void* p) {
	std::cerr << "See u soon in OK!" << std::endl;
	free(p);
}

VK::VK(std::string name) {
	login = name;
	std::cerr << "Yo, " << login << ". This is VK" << std::endl;
}

VK::VK() {
	std::cerr << "This is VK constructor" << std::endl;
}

VK:: ~VK() {
	std::cout << std::endl;
	std::cerr << "This is VK destructor. See ya! "<< std::endl;
	
}

void* VK:: operator new[](size_t size) {

	throw std:: exception("ERROR! ERROR! U can't use dynamic memory!!!");
}


void static_mem() {
	User user1("Gordon Ramsay");
	std::cout << std:: endl;
	OK user2("Grayed");
	std::cout << std:: endl;
	VK user3("Pavel Durov");
	std:: cout << std:: endl;

	//Конструкторы (далее — к.) срабатывают в след. порядке: к.родителя -> к. ребенка
	//в данном примере: к. User -> к. OK; к. User -> к. VK

	//Деструкторы же (далее — д.) срабатывают в обратном порядке: д. ребенка -> д. родителя
	//в данном примере: д. OK -> д. User;  д. VK -> д. User
}

void dynamic_mem() {
	User* gregorSamsa = new User[1];
	delete[] gregorSamsa;
	std::cout << std::endl;

	OK* petrI = new OK[2];
	delete[] petrI;
	std::cout << std::endl;
}

int main()
{
	std::cout << "Let's check static memory:\n" << std::endl;
	static_mem();

	std::cout << "=================" << std::endl;

	std::cout << "Let's check dynamic memory:\n" << std::endl;
	dynamic_mem();

	try {

		VK* Adamovich = new VK[3];
	}
	catch (std::exception& e)
	{
		std::cout << e.what() << std::endl;

	}

	return 0;
}
 