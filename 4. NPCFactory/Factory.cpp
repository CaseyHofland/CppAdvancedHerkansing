#include "Factory.h"
#include "Human.h"
#include "Orc.h"
#include "Farmer.h"
#include "Knight.h"
#include "Shaman.h"

Factory::Factory() {}

Factory::~Factory() {}

// This creates a new NPC based on a Race and a Role the user selects
npc::NPC* Factory::createNPC(Race race, Role roles) 
{
	npc::NPC* npc = nullptr;

	switch( race )
	{
	case Race::Human:
		npc = new npc::Human();
		break;
	case Race::Orc:
		npc = new npc::Orc();
		break;
	default:
		break;
	}

	if( static_cast<int>(roles & Role::Farmer) )
	{
		npc = new npc::Farmer(npc);
	}
	if( static_cast<int>( roles & Role::Knight ) )
	{
		npc = new npc::Knight(npc);
	}
	if( static_cast<int>( roles & Role::Shaman ) )
	{
		npc = new npc::Shaman(npc);
	}

	return npc;
}
