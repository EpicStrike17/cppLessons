#pragma once
#include "Creature.h"
class Npc : public Creature
{
public:
	Npc();
	Npc(string path);
	bool findTarget();

};

