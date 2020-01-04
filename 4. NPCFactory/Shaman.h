#pragma once

#include "Role.h"

namespace npc 
{
	class Shaman : public Role 
	{
	public:
		Shaman(NPC* npc);
		~Shaman();

		void draw() const;
	};
}