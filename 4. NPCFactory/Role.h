#pragma once

#include "NPC.h"

namespace npc 
{
	class Role : public NPC 
	{
	public:
		Role(NPC* npc);
		~Role();

		void draw() const;

	private:
		NPC* npc;
	};
}