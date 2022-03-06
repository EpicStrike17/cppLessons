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
            cout << "\n I am alive!" << endl;
            return true;
        }
        return false;
    }
    
    void Kick(Hero* enemy) {
        enemy->hp -= 35;

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

