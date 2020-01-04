#include <iostream>
#include "Orc.h"

namespace npc 
{
	Orc::Orc() {}

	Orc::~Orc() {}

	void Orc::draw() const {
		std::cout << "Race: Orc" << std::endl;
	}
}