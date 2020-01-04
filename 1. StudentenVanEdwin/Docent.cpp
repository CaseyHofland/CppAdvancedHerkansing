#include <iostream>
#include "Docent.h"

Docent::Docent(string name) : name(name) {}

Docent::~Docent() 
{
	for( auto& module : modules )
		module->docent = nullptr;
}

const string Docent::Name() const
{
	return name;
}

ostream& operator<<(ostream& os, const Docent& docent) 
{
	return os << docent.name;
}
