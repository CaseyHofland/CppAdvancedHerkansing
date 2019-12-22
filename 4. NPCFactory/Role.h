#pragma once

#include "NPC.h"

namespace Edwin_Bed_win {
	class Role : public NPC {
	public:
		Role(NPC* npc);
		~Role();

		void draw() const;

	private:
		NPC* npc;
	};
}