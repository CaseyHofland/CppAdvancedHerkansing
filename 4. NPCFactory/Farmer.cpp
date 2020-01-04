#include <iostream>
#include "Farmer.h"

namespace npc 
{
	Farmer::Farmer(NPC* npc) : Role(npc) {}

	Farmer::~Farmer() {}

	void Farmer::draw() const {
		Role::draw();
		std::cout << "Role: Farmer" << std::endl;
	}
}