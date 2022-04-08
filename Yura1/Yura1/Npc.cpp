#include "Npc.h"
#include "Hero.h"

Npc::Npc(){}

Npc::Npc(string path) : Creature(path)
{
}

Hero* Npc::findTarget()
{
	Hero* near = nullptr;


	for (auto obj : scene->getObjects()) {	// Перебор всех объектов
		if (obj->getType() == "Hero") {		// Перебор только героев
			if (!near) {
				near = dynamic_cast<Hero*>(obj);
			}
			else {
				if (getDistance(obj) < getDistance(near) ) {
					near = dynamic_cast<Hero*>(obj);
				};
			}
		}
	}
	return near;
}

void Npc::DoAction() {
	Hero* target = findTarget();
	step(target, 2);
}

string Npc::getType()
{
	return "Npc";
}
