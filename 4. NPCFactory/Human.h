#pragma once

#include "NPC.h"

namespace Edwin_Bed_win{
	class Human : public NPC {
	public:
		Human();
		~Human();

		void draw() const;
	};
}
