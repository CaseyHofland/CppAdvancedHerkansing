#include <iostream>
#include "Shaman.h"

namespace Edwin_Bed_win {
	Shaman::Shaman(NPC* npc) : Role(npc) {}

	Shaman::~Shaman() {}

	void Shaman::draw() const {
		Role::draw();
		std::cout << "I am Shamelamedingdang" << std::endl;
	}
}