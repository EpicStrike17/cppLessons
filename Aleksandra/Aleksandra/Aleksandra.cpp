// Aleksandra.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//ТИП_ОТВЕТА   НАЗВАНИЕ (ВХОДНЫЕ ДАННЫЕ) {ДЕЙСТВИЯ}
 
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

class Hero {
public:
    // Поля = Переменная-член
    string name;
    int hp;
    int attack;

    // Методы = функция-член

    bool isAlive() {
        if (hp > 0) {
            return true;
        }
        cout << "\n I AM UNDER AVADA KEDAVRA!" << endl;
        return false;
    }

    void getDamage(int dmg) {
        hp -= dmg;
        if (hp <= 0) {
            cout << "\n I am FIRE!!! I AM DEATH!!!" << endl;
        }
    }

    void Kick(Hero* enemy) {
        if (!isAlive()) return;
        enemy->getDamage(attack);

    }

    
 };

Hero* createHero(string path) {
    Hero* player = new Hero;
 ifstream file(path, fstream::in);
    

    file >> player->name >>player->hp >>player->attack;
    
    cout << "\n Name: " << player->name;
    cout << "\n HP: " << player->hp;
    cout << "\n Attack: " << player->attack;
    file.close();
    return player;
}

string Menu(string cmd) {
        string newCMD="";
    if (cmd == "main") {
        cout << endl << "1.Select hero";
        cout << endl << "x.Exit" << endl;

        cin >> newCMD;
        if (newCMD == "1") return "selectHero";
        if (newCMD == "x") return "exit";
     }

    if (cmd == "selectHero") {
        cout << endl << "1.Player1";
        cout << endl << "2.Player2" << endl;
        cin >> newCMD;
    }
}

int main()
{
    Hero* player1 = createHero("player1.txt");
    Hero* player2 = createHero("player2.txt");

    player1->isAlive();
    player2->isAlive();

    while (player2->isAlive()) {
        player1->Kick(player2);
    }


    player1->isAlive();
    player2->isAlive();

   


   
}

