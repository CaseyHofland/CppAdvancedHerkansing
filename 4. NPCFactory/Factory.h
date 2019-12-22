#pragma once

#include "NPC.h"

enum Race {
	Human,
	Orc
};

enum Roles {
	None = 0,
	Farmer = 1,
	Knight = 2,
	Shaman = 4
};

inline Roles operator|(Roles lhs, Roles rhs) {
	return static_cast<Roles>( static_cast<int>( lhs ) | static_cast<int>( rhs ) );
}

inline Roles& operator|=(Roles lhs, Roles rhs) {
	lhs = lhs | rhs;
	return lhs;
}

class Factory {
public:
	Factory();
	virtual ~Factory();

	Edwin_Bed_win::NPC* createNPC(Race race, Roles roles = Roles::None);
};