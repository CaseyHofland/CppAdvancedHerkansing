#pragma once

#include "Role.h"

namespace Edwin_Bed_win {
	class Knight : public Role {
	public:
		Knight(NPC* npc);
		~Knight();

		void draw() const;
	};
}