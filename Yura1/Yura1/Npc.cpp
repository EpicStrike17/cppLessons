#include "Npc.h"

Npc::Npc(){}

Npc::Npc(string path): Creature(path)
{
}

bool Npc::findTarget()
{
	return false;
}
