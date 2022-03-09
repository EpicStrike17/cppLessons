// Yura1.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#include "Utilities.h"
#include "Hero.h"


Hero::Hero() {}

Hero::Hero(std::string path){
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
	} while (!file.eof());

	file >> name >> hp >> atk >> arm >> agi;
	agiChance = ((float)agi / 1000) * 0.75;
	if (agiChance > 0.75) agiChance = 0.75;
	armPct = 0.75 / 1000 * arm;
	Stats();
	file.close();
}

void Hero::Kick(Hero* enemy) {
	cout << endl << name << " kick " << enemy->name << ": " << atk << "\n";
	enemy->getDamage(atk);
}
void Hero::Stats() {
	cout << "\n Name: " << name;
	cout << "\n HP: " << hp;
	cout << "\n ATK: " << atk;
	cout << "\n AGI: " << agi << " (" << agiChance << ")" << endl;
	cout << "\n ARM: " << arm  <<" ("<< armPct <<")" << endl;
}

void Hero::getDamage(int dmg) {
	if (agiChance*1000 > (rand() % 1000)) {
		cout << name << " успешно уклонился от атаки ";
		return;
	}
	
	hp -= dmg - dmg * armPct;
	if (hp <= 0) {
		cout << name << " died.";
	}
	
}

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
	player1 = new Hero("player1.txt");
	player2 = new Hero("player2.txt");
	string nextMenu = Menu("main");
	while (nextMenu != "exit") {
		nextMenu= Menu(nextMenu);
	}
	
	system("pause");
}

