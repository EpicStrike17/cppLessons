#include "Creature.h"

Creature::Creature() {
	//cout << " Creature constructor()"<<endl;
}

Creature::~Creature() {
	//cout << " Creature destructor()" << endl;
}


Creature::Creature(std::string path) {

	//cout << " Creature constructor(" <<path<<")" << endl;

	ifstream file(path, fstream::in);
	string parName = "";
	do {
		file >> parName;
		if (parName == "name") {
			file >> name;
		}
		else if (parName == "hp") {
			file >> hp;
		}
		else if (parName == "atk") {
			file >> atk;
		}
		else if (parName == "agi") {
			file >> agi;
		}
		else if (parName == "arm") {
			file >> arm;
		}
	} while (!file.eof());

	file >> name >> hp >> atk >> arm >> agi;
	agiChance = ((float)agi / 1000) * 0.75;
	if (agiChance > 0.75) agiChance = 0.75;
	armPct = 0.75 / 1000 * arm;
	//Stats();
	file.close();
}

void Creature::Kick() {
	if (!target) {
		return;
	}
	cout << endl << name << " kick " << target->name << ": " << atk << "\n";
	target->getDamage(atk);
}

void Creature::Kick(Creature* enemy) {
	cout << endl << name << " kick " << enemy->name << ": " << atk << "\n";
	enemy->getDamage(atk);
}

void Creature::Stats() {
	cout << "\n Name: " << name;
	cout << "\n HP: " << hp;
	cout << "\n ATK: " << atk;
	cout << "\n AGI: " << agi << " (" << agiChance << ")" << endl;
	cout << "\n ARM: " << arm << " (" << armPct << ")" << endl;
}

void Creature::getDamage(int dmg) {
	if (agiChance * 1000 > (rand() % 1000)) {
		cout << name << " успешно уклонился от атаки ";
		return;
	}

	hp -= dmg - dmg * armPct;
	if (hp <= 0) {
		cout << name << " died.";
	}

}

void Creature::step(Direction dir, int speed)
{
	switch (dir) {
		case Direction::UP: 
			y += speed; 
			break;
		case Direction::DOWN: 
			y -= speed; 
			break;
		case Direction::LEFT: 
			x -= speed; 
			break;
		case Direction::RIGHT: 
			x += speed; 
			break;
		default:
			cout<< "Wrong Direction"<<endl;
	}
	
}


void Creature::DoAction(){
	step(Direction::LEFT, 1);
	cout << "Creature step left"<<endl;
}