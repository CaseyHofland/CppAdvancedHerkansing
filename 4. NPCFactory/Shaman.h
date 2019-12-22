#pragma once

#include "Role.h"

namespace Edwin_Bed_win {
	class Shaman : public Role {
	public:
		Shaman(NPC* npc);
		~Shaman();

		void draw() const;
	};
}