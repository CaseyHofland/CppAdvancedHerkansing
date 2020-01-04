#include "Role.h"

namespace npc 
{
	Role::Role(NPC* npc) : npc(npc) {}
	Role::~Role() {}

	void Role::draw() const {
		npc->draw();
	}
}