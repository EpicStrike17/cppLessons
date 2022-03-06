
#include "utilities.h"

// ФОРМАТ СОЗДАНИЯ ФУНКЦИЙ
// ТИП_ОТВЕТА  НАЗВАНИЕ(ВХОДНЫЕ ДАННЫЕ) { ДЕЙСТВИЯ }



class Hero {
public:
    // Поля  = Переменная-член
    string name;
    int hp;
    int attack;

    // Методы = функция-член

    bool isAlive() {
        if (hp > 0) {
            cout << endl << name << " is alive" << endl;
            return true;
        }

        cout << "\n " << name << "is dead!" << endl;
        return false;
    }

    void Kick(Hero* enemy) {
        enemy->hp -= 30;
    }

};



Hero* createHero(string path) {
    ifstream file(path, fstream::in);

    Hero* newPlayer = new Hero();

    file >> newPlayer->name >> newPlayer->hp >> newPlayer->attack;
    cout << "\n Name: " << newPlayer->name;
    cout << "\n HP: " << newPlayer->hp;
    cout << "\n Attack: " << newPlayer->attack;
    file.close();
    return newPlayer;
}

int main()
{

    Hero* player1 = createHero("player1.txt");
    Hero* player2 = createHero("player2.txt");

    player1->isAlive();
    player2->isAlive();

    player1->Kick(player2);
    player1->Kick(player2);
    player1->Kick(player2);

    player1->isAlive();
    player2->isAlive();
   
    system("pause");

}




/* 
   +Комментарии
    +0. Создание переменных разных типов. Присваивание
    1. Дебаггер и брейкпоинты
    +2. Изменение по условию  if else
    3. Циклы и счётчики for while  doWhile
    +4. Вывод в консоль (константы, переменные)
    +5. Ввод с клавиатуры
    +6. Конфликт типов (ввод строки в число)
    7. Приведение типов ( float, int, char, string )
    8. Массивы (строка=массив)
    9. Создание массива
    10. Ввод массива чисел

    Меню
    1. Приветствие / инструкция
    2. Ввод команды/номера
    3. Условие - действие

    Функции


*/