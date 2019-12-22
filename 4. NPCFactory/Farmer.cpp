#include <iostream>
#include "Farmer.h"

namespace Edwin_Bed_win {
	Farmer::Farmer(NPC* npc) : Role(npc) {}

	Farmer::~Farmer() {}

	void Farmer::draw() const {
		Role::draw();
		std::cout << "I am Furmerur" << std::endl;
	}
}