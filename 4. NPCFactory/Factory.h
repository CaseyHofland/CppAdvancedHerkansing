#pragma once

#include "NPC.h"

enum class Race 
{
	Human,
	Orc
};

enum class Role 
{
	None = 0,
	Farmer = 1,
	Knight = 2,
	Shaman = 4
};

inline Role operator|(Role lhs, Role rhs) 
{
	return static_cast<Role>( static_cast<int>( lhs ) | static_cast<int>( rhs ) );
}

inline Role& operator|=(Role lhs, Role rhs) 
{
	lhs = lhs | rhs;
	return lhs;
}

inline Role operator&(Role lhs, Role rhs)
{
	return static_cast<Role>( static_cast<int>( lhs ) & static_cast<int>( rhs ) );
}

inline Role& operator&=(Role lhs, Role rhs)
{
	lhs = lhs & rhs;
	return lhs;
}

class Factory {
public:
	Factory();
	virtual ~Factory();

	npc::NPC* createNPC(Race race, Role roles = Role::None);
};