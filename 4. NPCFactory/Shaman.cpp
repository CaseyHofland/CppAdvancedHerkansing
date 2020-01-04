#include <iostream>
#include "Shaman.h"

namespace npc 
{
	Shaman::Shaman(NPC* npc) : Role(npc) {}

	Shaman::~Shaman() {}

	void Shaman::draw() const {
		Role::draw();
		std::cout << "Role: Shaman" << std::endl;
	}
}