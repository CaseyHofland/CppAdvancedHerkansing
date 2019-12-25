#include <iostream>
#include "Parent.h"

Parent::Parent(std::string name) {
	this->name = name;
	std::string childName = "ChildOf" + name;
	this->child = std::make_unique<Child>(childName);
}

Parent::Parent(const Parent& other) {
	std::cout << "Parent cctor" << std::endl;
	this->name = other.name;
	this->child = std::make_unique<Child>(*other.child);
}

Parent::Parent(Parent&& other) noexcept {
	*this = std::move(other);
}

Parent::~Parent() {
	std::cout << "Parent dtor : " << this->name << std::endl;
	this->child.reset();
}

Parent& Parent::operator=(const Parent& other) {
	std::cout << "Parent assignment" << std::endl;

	if( this == &other ) return *this;

	this->name = other.name;
	this->child.reset();
	this->child = std::make_unique<Child>(*other.child);

	return *this;
}

Parent& Parent::operator=(Parent&& other) noexcept {
	if( this == &other )
		return *this;

	std::cout << "Parent move assignment from '" << other.name << "' @" << &other << " to Parent @" << this << std::endl;

	this->child.reset();

	this->name = std::move(other.name);
	this->child = std::move(other.child);

	other.name = {};
	other.child = {};

	return *this;
}

std::ostream& operator<<(std::ostream& os, const Parent& parent) {
	os << "parent name: " << parent.name << "," << *parent.child;
	return os;
}
