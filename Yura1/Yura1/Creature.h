#pragma once
#include "Utilities.h"
#include "Drawable.h"

class Creature: public Drawable {
public:
	// поле  = переменная-член
	string name = "";
	int hp = 0;
	int atk = 0;
	int agi = 0;
	float agiChance = 0;
	int arm = 0;	// 1000 брони = сниж. урона на 75%
	float armPct = 0;
	int x = 0;
	int y = 0;
	Creature *target;


	// конструкторы
	Creature(); // конструктор по умолчанию
	Creature(std::string path);
	~Creature();

	// метод = функция-член
	void Kick();
	void Kick(Creature* enemy);
	void Stats();
	void getDamage(int dmg);
	virtual void DoAction() = 0;
	void step(Direction dir,int speed);
	void setXY(int x, int y);



};
