// NPCFactory.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include <iostream>
#include <vector>
#include "Factory.h"

// The only interesting files in this project is the Factory. Everything else is used for testing the factory.

// Draws all npcs in a list (used for testing)
void draw(std::vector<npc::NPC*> npcs) 
{
	for( auto& npc : npcs )
	{
		npc->draw();
		std::cout << std::endl;
	}
}

int main()
{
	std::vector<npc::NPC*> npcs;

	Factory factory = Factory();
	npcs.push_back(factory.createNPC(Race::Orc, Role::Shaman | Role::Farmer ));

	draw(npcs);

	return 0;
}
