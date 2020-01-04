// main.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include "Parent.h"

// Testing different kinds of pointers

void Moved() {
	Parent* p1 = new Parent("Parent1");
	std::cout << "p1:" << *p1 << std::endl;

	Parent p2 = std::move(*p1);
	std::cout << "p2:" << p2 << std::endl;

	Parent* p3 = new Parent("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	*p3 = std::move(*p1);
	std::cout << "p1:" << p3 << std::endl;

	delete p1;
	delete p3;
}

void Shared() {
	auto p1 = std::make_shared<Parent>("Parent1");
	std::cout << "p1:" << *p1 << std::endl;

	auto p2 = p1;
	std::cout << "p2:" << *p2 << std::endl;

	auto p3 = std::make_shared<Parent>("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	p3 = p1;
	std::cout << "p1:" << *p3 << std::endl;

	p1.reset();
	p2.reset();
	p3.reset();
}

void Normal() {
	Parent* p1 = new Parent("Parent1");
	std::cout << "p1:" << *p1 << std::endl;

	Parent* p2 = new Parent(*p1); // calls the copy constructor
	std::cout << "p2:" << *p2 << std::endl;

	Parent* p3 = new Parent("Parent3");
	std::cout << "p3:" << *p3 << std::endl;

	*p3 = *p1; // calls the assignment operator
	std::cout << "p1:" << *p3 << std::endl;

	delete p1;
	delete p2;
	delete p3;
}

int main() {
	Moved();

	return 0;
}
