#pragma once

#include "Role.h"

namespace npc 
{
	class Knight : public Role 
	{
	public:
		Knight(NPC* npc);
		~Knight();

		void draw() const;
	};
}