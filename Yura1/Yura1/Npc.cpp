#include "Npc.h"

Npc::Npc(){}

Npc::Npc(string path): Creature(path)
{
	pic = new vector<string>({
		" q(O_O)p ",	//	" ☺ ",
		" \\/|=|\\/ ",	// "╚╬╝",
		"   I I   "	// "╔═╗"
		});
}

bool Npc::findTarget()
{
	return false;
}

void Npc::DoAction() {
	step(Direction::LEFT, 1);
	cout << "Creature step left" << endl;
}