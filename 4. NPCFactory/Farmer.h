#pragma once

#include "Role.h"

namespace Edwin_Bed_win {
	class Farmer : public Role {
	public:
		Farmer(NPC* npc);
		~Farmer();

		void draw() const;
	};
}