#pragma once
#include "Creature.h"
class Hero : public Creature
{
public:
	
	Hero();
	~Hero();
	Hero(std::string path);
	Hero(int playerId);
	void setArmor(int ar);
	void DoAction();
};

