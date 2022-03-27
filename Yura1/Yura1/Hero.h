#pragma once
#include "Creature.h"
class Hero : public Creature
{
public:
	
	Hero();
	~Hero();
	Hero(std::string path);
	void setArmor(int ar);
	void DoAction();

	void step(int speed);
	string getType() override;


	Direction curDir;
};

