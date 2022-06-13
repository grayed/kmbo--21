#pragma once

class User {
protected:
	std::string login;
	int password;
public:
	User(std::string name);
	User();
	~User();
	static void* operator new[](size_t size);
	static void operator delete[](void* p);
};

class OK : public User {
public:
	OK(std::string name);
	OK();
	~OK();
	static void* operator new[](size_t size);
	static void operator delete[](void* p);
};

class VK : public User {
public:
	VK(std::string name);
	VK();
	~VK();
	static void* operator new[](size_t size);
};

