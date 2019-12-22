// NPCFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Factory.h"

void draw(std::vector<Edwin_Bed_win::NPC*> npcs) {
	for( auto& npc : npcs )
	{
		npc->draw();
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<Edwin_Bed_win::NPC*> npcs;

	Factory factory = Factory();
	npcs.push_back(factory.createNPC(Race::Orc, Roles::Shaman | Roles::Farmer ));

	draw(npcs);

	return 0;
}
