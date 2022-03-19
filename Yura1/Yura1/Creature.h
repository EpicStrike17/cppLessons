#pragma once
#include "Utilities.h"
#include "Drawable.h"

class Creature: public Drawable {
public:
	// ����  = ����������-����
	string name = "";
	int hp = 0;
	int atk = 0;
	int agi = 0;
	float agiChance = 0;
	int arm = 0;	// 1000 ����� = ����. ����� �� 75%
	float armPct = 0;
	int x = 0;
	int y = 0;
	Creature *target;


	// ������������
	Creature(); // ����������� �� ���������
	Creature(std::string path);
	~Creature();

	// ����� = �������-����
	void Kick();
	void Kick(Creature* enemy);
	void Stats();
	void getDamage(int dmg);
	virtual void DoAction() = 0;
	void step(Direction dir,int speed);
	void setXY(int x, int y);



};
