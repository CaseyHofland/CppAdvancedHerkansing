#pragma once

#include "NPC.h"

namespace npc
{
	class Human : public NPC 
	{
	public:
		Human();
		~Human();

		void draw() const;
	};
}
