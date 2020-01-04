#pragma once

#include "Role.h"

namespace npc 
{
	class Farmer : public Role 
	{
	public:
		Farmer(NPC* npc);
		~Farmer();

		void draw() const;
	};
}