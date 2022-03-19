// Yura1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Utilities.h"
#include "Hero.h"
#include "ScreenController.h"
#include "Npc.h"



Creature* player1;
Creature* player2;
Creature* selectedHero;
int gameScore = 0;

string Menu(string type) {

	string cmd = "";
	if (type == "main") {
		system("cls");
		cout << "\n\n\nВыбор персонажа\n";
		cout << "1)Щербатая АмЭга\n";
		cout << "2)Бончмэн\n";
		cin >> cmd;
		if (cmd == "1") {
			selectedHero = player1;
		}
		else if (cmd == "2") {
			selectedHero = player2;
		}
		return "action";
	}
	else
		if (type == "action") {
			cout << "\n\n\nВыбор действия\n";
			cout << "1)Характеристики текущего персонажа\n";
			cout << "2)Ударить другого персонажа\n";
			cout << "х)В главное меню\n";
			cin >> cmd;
			if (cmd == "1") {
				selectedHero->Stats();
			}
			else if (cmd == "2") {
				auto enemy = selectedHero == player1 ? player2 : player1; //Тернарный оператор
				selectedHero->Kick(enemy);
			}
			
			if (cmd == "x") {
				return "main";
			}
			else {
				return "action";
			}
		}
}



int main()
{

	setlocale(LC_ALL, "Russian");
	gameScore = 0;
	for(int i=0;i<40;i++)
	cout << "wet";


	ScreenController scene;
	scene.fill('#');
	scene.draw();
	system("pause");
	
	Hero* h1 = new Hero("player1.txt");
	Hero* h2 = new Hero("player2.txt");
	Npc* e1 = new Npc("Mob1.txt");

	scene.h.push_back(h1);
	scene.h.push_back(h2);
	
	

	h1->setXY(50, 10);
	h2->setXY(260, 30);
	e1->setXY(11, 15);

	scene.drawAll();
	system("pause");

	h1->setXY(140, 10);
	h2->setXY(280, 30);
	e1->setXY(100, 20);
	scene.drawAll();
	system("pause");


	h2->step(Direction::DOWN, 5);
	scene.drawAll();
	system("pause");
	h2->step(Direction::DOWN, 5);
	scene.drawAll();
	system("pause");
	h2->step(Direction::LEFT, 15);
	scene.drawAll();
	system("pause");
	h2->step(Direction::DOWN, 5);
	scene.drawAll();
	system("pause");


	


	/*
	player1 = new Creature("player1.txt");
	player2 = new Creature("player2.txt");
	string nextMenu = Menu("main");
	while (nextMenu != "exit") {
		nextMenu= Menu(nextMenu);
	}
	*/
	
	system("pause");
}

