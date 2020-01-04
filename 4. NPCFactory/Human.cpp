#include <iostream>
#include "Human.h"

namespace npc 
{
	Human::Human() {}

	Human::~Human() {}

	void Human::draw() const {
		std::cout << "Race: Human" << std::endl;
	}
}