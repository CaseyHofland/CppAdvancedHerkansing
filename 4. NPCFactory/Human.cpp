#include <iostream>
#include "Human.h"

namespace Edwin_Bed_win {
	Human::Human() {}

	Human::~Human() {}

	void Human::draw() const {
		std::cout << "Humanz" << std::endl;
	}
}