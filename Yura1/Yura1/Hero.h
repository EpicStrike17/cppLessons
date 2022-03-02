#pragma once
#include "Utilities.h"

class Hero {
public:
	// ����  = ����������-����
	string name = "";
	int hp = 0;
	int atk = 0;
	int arm = 0;	// 1000 ����� = ����. ����� �� 75%
	// ������������
	Hero(); // ����������� �� ���������
	Hero(std::string path);
	// ����� = �������-����
	void Kick(Hero* enemy);
	void Stats();
	void getDamage(int dmg);

};

Hero* player1;
Hero* player2;
Hero* selectedHero;