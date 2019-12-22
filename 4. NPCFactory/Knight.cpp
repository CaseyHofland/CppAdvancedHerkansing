#include <iostream>
#include "Knight.h"

namespace Edwin_Bed_win {
	Knight::Knight(NPC* npc) : Role(npc) {}

	Knight::~Knight() {}

	void Knight::draw() const {
		Role::draw();
		std::cout << "I am Knicht" << std::endl;
	}
}