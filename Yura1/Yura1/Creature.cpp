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
		else if (parName == "pic") {
			int n = 0;
			string picLine = "";
			file >> n;
			if (n == 0) {
				throw("");
			}
			pic = new vector<string>;
			getline(file, picLine);
			for (int i = 0; i < n; i++) {
				getline(file, picLine);
				pic->push_back(picLine);
			}

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
		cout << name << " ??????? ????????? ?? ????? ";
		return;
	}

	hp -= dmg - dmg * armPct;
	if (hp <= 0) {
		cout << name << " died.";
		//deleting died objects
		auto objects = scene->getObjects();

		for (auto obj = objects.begin(); obj != objects.end(); ++obj) {
			if ( (*obj) == this ) {
				scene->getObjects().erase(obj);
			}
		}
	}

}

void Creature::step(Direction dir, int speed)
{
	int oldX = x;
	int oldY = y;

	switch (dir) {
		case Direction::UP: 
			y -= speed*1.5; 
			break;
		case Direction::UPLEFT: 
			y -= speed;
			x -= speed;
			break;
		case Direction::UPRIGHT: 
			y -= speed;
			x += speed;
			break;
		case Direction::DOWN: 
			y += speed*1.5; 
			break;
		case Direction::DOWNLEFT:
			y += speed;
			x -= speed;
			break;
		case Direction::DOWNRIGHT:
			y += speed;
			x += speed;
			break;
		case Direction::LEFT: 
			x -= speed * 1.5;
			break;
		case Direction::RIGHT: 
			x += speed * 1.5;
			break;
	}

	//add collision
	for (auto obj : scene->getObjects()) {
		int x1 = x;
		int y1 = y;
		int h1 = y1 + pic->size();
		int w1 = x1 + (*pic)[0].size();
		if (obj == this) {
			continue;
		}

		int x2 = obj->x;
		int y2 = obj->y;
		int h2 = y2 + obj->pic->size();
		int w2 = x2 + (*obj->pic)[0].size();

		if (x1 <= w2 && w1 >= x2) {
			if (y1 <= h2 && h1 >= y2) {
				x = oldX;
				y = oldY;
			}
		}
	}
	
}

void Creature::step(Drawable* target, int speed)
{
	int diffx = target->x - x;
	int diffy = target->y - y;
	Direction dir;

	if (diffy < 0 && diffx > 0) dir = Direction::UPRIGHT;
	else if (diffy < 0 && diffx < 0) dir = Direction::UPLEFT;
	else if (diffy < 0 && diffx == 0) dir = Direction::UP;
	
	else if (diffy > 0 && diffx > 0) dir = Direction::DOWNRIGHT;
	else if (diffy > 0 && diffx < 0) dir = Direction::DOWNLEFT;
	else if (diffy > 0 && diffx == 0) dir = Direction::DOWN;
	 
	else if (diffy == 0 && diffx > 0) dir = Direction::RIGHT;
	else if (diffy == 0 && diffx < 0) dir = Direction::LEFT;
	else if (diffy == 0 && diffx == 0) dir = Direction::NONE;
	step(dir, speed);
}

