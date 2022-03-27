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
			selectedHero = player1; //bruh
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

	ScreenController scene;
	scene.fill('#');
	scene.draw();
	system("pause");
	
	Creature* h1 = new Hero("player1.txt");
	Creature* h2 = new Npc("player2.txt");
	Creature* e1 = new Npc("Mob1.txt");

	scene.addChild(h1);
	scene.addChild(h2);
	scene.addChild(e1);

	h1->setXY(50, 10);
	h2->setXY(260, 30);
	e1->setXY(11, 15);

	while (true) {

		scene.DoAction();
		scene.drawAll();
		//system("pause");
	}




	


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

