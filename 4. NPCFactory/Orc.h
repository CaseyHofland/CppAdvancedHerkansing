#pragma once

#include "NPC.h"

namespace npc 
{
	class Orc : public NPC 
	{
	public:
		Orc();
		~Orc();

		void draw() const;
	};
}