#include "Hero.h"

Hero::Hero() {};
Hero::~Hero() {
	//cout << "Hero destructor()"<< endl;
}

Hero::Hero(std::string path) :Creature(path)
{
	//cout << " Hero constructor(" << path << ")" << endl;
	pic = new vector<wstring>({ 
		" ☺ ",
		"╚╬╝",
		"╔═╗"
	});
}

Hero::Hero(int playerId) : Creature("player"+to_string(playerId)+".txt")
{

	//cout << " Hero constructor(ID: " << playerId << ")" << endl;
}

void Hero::setArmor(int ar) {


}

void Hero::DoAction() {
	char cmd;
	cin >> cmd;
	switch (cmd)
	{
	case 'w': step(Direction::UP, 1); break;
	case 'a': step(Direction::LEFT, 1); break;
	case 's': step(Direction::DOWN, 1); break;
	case 'd': step(Direction::RIGHT, 1); break;
	case '1': Kick(); break;
	default:
		break;
	}
}