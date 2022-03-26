#pragma once
#include "Creature.h"

class Hero;

class Npc : public Creature
{
public:
	Npc();
	Npc(string path);
	Hero* findTarget();

	void DoAction();
	string getType() override;
};

