#pragma once

#include "NPC.h"

namespace Edwin_Bed_win {
	class Orc : public NPC {
	public:
		Orc();
		~Orc();

		void draw() const;
	};
}