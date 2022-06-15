#pragma once
#include <iostream>
#include <string>
#include <sys/types.h>

class Foo {
	int height;
	bool permission;

public:
	Foo() {
		height = 0;
		permission = false;
		std::cerr << "Foo constructor\n";
	}
	~Foo() {
		std::cerr << "Foo destructor\n";
	}

	void setHeight(int value) { height = value; }
	void setPermission(bool value) { permission = value; }

	int getHeight() const { return height; }
	bool getPermission() const { return permission; }

	static void* operator new(size_t n) {
		auto p = malloc(n);
		std::cerr << "Foo - operator new, " << n << "bytes, adress: " << p << "\n";
		return p;
	}
	static void operator delete(void* p) {
		std::cerr << "Foo - operator delete\n";
		free(p);
	}
};

class Bar :public Foo {
	std::string name;
	char group;
public:
	Bar() {
		name = "Sasha";
		group = 'A';
		std::cerr << "Bar constructor\n";
	}
	~Bar() {
		std::cerr << "Bar destructor\n";
	}

	void setName(std::string value) { name = value; }
	void setGroup(char value) { group = value; }

	std::string getName() { return name; }
	char getGroup() { return group; }

	void* operator new(size_t n) {
		auto p = malloc(n);
		std::cerr << "Bar - operator new, " << n << " bytes, adress: " << p << "\n";
		return p;
	}
	void operator delete(void* p) {
		std::cerr << "Bar - operator delete\n";
		free(p);
	}
};

class Buz :public Foo {
	int age;
	char sex;
public:
	Buz() {
		age = 0;
		sex = 'M';
		std::cerr << "Buz constructor\n";
	}
	~Buz() {
		std::cerr << "Buz destructor\n";
	}

	void setAge(int value) { age = value; }
	void setSex(char value) { sex = value; }
	
	int getAge() { return age; }
	char getSex() { return sex; }
private:
	static void* operator new(size_t n) {
		auto p = malloc(n);
		std::cerr << "Buz - operator new, " << n << " bytes, adress: " << p << "\n";
		return p;
	}
	static void operator delete(void* p) {
		std::cerr << "Buz - operator delete\n";
		free(p);
	}
};
