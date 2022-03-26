#include "Hero.h"

Hero::Hero() {};
Hero::~Hero() {
}

Hero::Hero(std::string path) :Creature(path)
{
	pic = new vector<string>({ 
		" 0 ",	//	" ☺ ",
		" T ",	// "╚╬╝",
		" LL"	// "╔═╗"
	});
}

void Hero::setArmor(int ar) {


}

void Hero::DoAction() {

	char cmd;
	//cin >> cmd;

	if (_kbhit()) {
		cmd = _getch();
		switch (cmd)
		{
		case 'w': Creature::step(Direction::UP, 3); break;
		case 'a': Creature::step(Direction::LEFT, 3); break;
		case 's': Creature::step(Direction::DOWN, 3); break;
		case 'd': Creature::step(Direction::RIGHT, 3); break;
		case '1': Kick(); break;
		default:
			break;
		}
	}
}

void Hero::step(int speed)
{
	Creature::step(curDir, speed);
}
