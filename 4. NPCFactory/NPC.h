#pragma once

namespace npc 
{
	class NPC 
	{
	public:
		NPC();
		virtual ~NPC();

		virtual void draw() const = 0;
	};
}