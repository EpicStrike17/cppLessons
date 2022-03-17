// Yura1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Utilities.h"
#include "Hero.h"
#include "ScreenController.h"



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



void pseudoMain() {

	Hero* her = new Hero(1);

	//her->step(Direction::UP, 3);
	//her->DoAction();
	
	her->Kick();

	delete her;

}

int main()
{

	setlocale(LC_ALL, "Russian");
	gameScore = 0;
	for(int i=0;i<40;i++)
	cout << "wet";


	ScreenController screen;
	screen.fill('#');
	screen.draw();
	system("pause");
	
	Hero* dick = new Hero("player1.txt");
	screen.add(dick->pic,100,13);
	screen.draw();


	pseudoMain();
	


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

