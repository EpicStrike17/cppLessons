// Yura1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include <queue>
#include "Utilities.h"
#include "Hero.h"
#include "ScreenController.h"
#include "Npc.h"



Creature* player1;
Creature* player2; //bruh,bruh
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

class Clock {
	 protected:
		int minutes = 0;
	public:
		int hour = 0;
		void setTime(int h) {
			hour = h;
		}
		void setMin(int min) {
			if (min >= 0 && min < 60) {
				minutes = min;
				return;
			}
			cout << "You are dumb" << endl;
		}
		virtual void set() = 0;

		int getMin() {
			return minutes;
		}

};
class Handclock : public Clock {
	void set() override {
		cout << "You wear clock" << endl;
	}
};
class Tableclock : public Clock {
	void set() override {
		cout << "You set clock on the table" << endl;
	}
};

int main()
{

	/*
	Создать массив из объектов(int), создать вектор(int), dymanic array(int), queue(int)
	При инициализации записать в каждый из них пять рандомных чисел
	Вывести на экран
	Добавить в каждый из них ещё три рандомных числа
	Вывести на экран
	Найти один элементов(который равен 5) и удалить этот элемент
	Отсортировать по возрастанию
	Вывести на экран
	*/
	int array[6] = { 1, 45, 2, 5, 9, 17 };
	vector<int> vec = { 1, 4, 5, 7, 12, 43 };
	int* dyar = new int[5] { 1, 4, 5, 14, 8 };
	queue <int> que;
	{ 135, 5, 12, 9, 32, 6 };

















	Clock* time;
	time->setMin(45);
	Clock* coc = new Handclock();
	coc->set();



	setlocale(LC_ALL, "Russian");
	gameScore = 0;

	ScreenController scene;
	scene.fill('#');
	scene.draw();
	system("pause");


	scene.spawn(new Hero("player1.txt"));
	
	Creature* h1 = new Hero("player1.txt");
	scene.addChild(h1);
	h1->setXY(50, 10);


	Creature* h2 = new Npc("player2.txt");
	scene.addChild(h2);
	h2->setXY(260, 30);


	Creature* e1 = new Npc("Mob1.txt");
	scene.addChild(e1);
	e1->setXY(11, 15);

	while (true) {

		scene.DoAction();
		scene.drawAll();
		//system("pause");
	}


	// Сделать проверку коллизий
	// Атаку с расстояния + стрельба для игрока (патроны)



	


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

