#pragma once

namespace Edwin_Bed_win {
	class NPC {
	public:
		NPC();
		virtual ~NPC();

		virtual void draw() const = 0;
	};
}