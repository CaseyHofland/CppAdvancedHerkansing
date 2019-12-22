#include "Factory.h"
#include "Human.h"
#include "Orc.h"
#include "Farmer.h"
#include "Knight.h"
#include "Shaman.h"

Factory::Factory() {}

Factory::~Factory() {}

Edwin_Bed_win::NPC* Factory::createNPC(Race race, Roles roles) {
	Edwin_Bed_win::NPC* npc = nullptr;

	switch( race )
	{
	case Race::Human:
		npc = new Edwin_Bed_win::Human();
		break;
	case Race::Orc:
		npc = new Edwin_Bed_win::Orc();
		break;
	default:
		break;
	}

	if( roles & Roles::Farmer )
	{
		npc = new Edwin_Bed_win::Farmer(npc);
	}
	if( roles & Roles::Knight )
	{
		npc = new Edwin_Bed_win::Knight(npc);
	}
	if( roles & Roles::Shaman )
	{
		npc = new Edwin_Bed_win::Shaman(npc);
	}

	return npc;
}
