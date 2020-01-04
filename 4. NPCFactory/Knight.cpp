#include <iostream>
#include "Knight.h"

namespace npc 
{
	Knight::Knight(NPC* npc) : Role(npc) {}

	Knight::~Knight() {}

	void Knight::draw() const {
		Role::draw();
		std::cout << "Role: Knight" << std::endl;
	}
}