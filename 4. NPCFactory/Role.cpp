#include "Role.h"

namespace Edwin_Bed_win {
	Role::Role(NPC* npc) : npc(npc) {}

	Role::~Role() {}

	void Role::draw() const {
		npc->draw();
	}
}