// Polina.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;

// Создание функции
// Тип ответа   Название(входные данные) {Действия}


class Hero {

    // у каждого объекта есть переменная - член (можно померить)

public:
    string name;
    int hp;
    int attack;


    // Методы = функция-член класса (что умеет)

    bool islife() {
        if (hp > 0) {
            return true;
        }
        cout << "i am dead" << endl;
        return false;
    }

    void Kick(Hero* enemy) {
        enemy->getDamage(attack);
        if (!islife()) return;
    }


    void getDamage(int dmg) {
        hp -= dmg;
        if (hp <= 0) {
            cout << "i am dead" << endl;

        }
}
};


Hero* createh(string pass) {
    ifstream file(pass, fstream::in);
    
    Hero* newplayer = new Hero();


    file >> newplayer->name >> newplayer->hp >> newplayer->attack;
    cout << "\n name:" << newplayer->name;
    cout << "\n hp:" << newplayer->hp;
    cout << "\n attack:" << newplayer->attack;
    file.close();
    return newplayer;
}

string Menu(string cmd) {
    string newCmd = "";
    if (cmd == "main") {
        cout << endl << "1. Select hero";
        cout << endl << "x. Exit";
        
        cin >> newCmd;
        if (newCmd == "1") return "selectHero";
        if (newCmd == "x") return "exit";

    }
    if (cmd == "selectHero") {
        cout << endl << "1. Player1";
        cout << endl << "2. Player2" << endl;
        cin >> newCmd;


    }

}


int main()
{
   Hero* player1 = createh("player1.txt");
   Hero* player2 = createh("player2.txt");

    player1->Kick(player2);
   
   

   


    


    


}




// Запуск программы: CTRL+F5 или меню "Отладка" > "Запуск без отладки"
// Отладка программы: F5 или меню "Отладка" > "Запустить отладку"

// Советы по началу работы 
//   1. В окне обозревателя решений можно добавлять файлы и управлять ими.
//   2. В окне Team Explorer можно подключиться к системе управления версиями.
//   3. В окне "Выходные данные" можно просматривать выходные данные сборки и другие сообщения.
//   4. В окне "Список ошибок" можно просматривать ошибки.
//   5. Последовательно выберите пункты меню "Проект" > "Добавить новый элемент", чтобы создать файлы кода, или "Проект" > "Добавить существующий элемент", чтобы добавить в проект существующие файлы кода.
//   6. Чтобы снова открыть этот проект позже, выберите пункты меню "Файл" > "Открыть" > "Проект" и выберите SLN-файл.
