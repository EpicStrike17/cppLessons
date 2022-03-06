
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
    11. Вывод чисел больше нуля
    12. Поиск максимального
    13. Сортировка по возрастанию/убыванию

    Меню
    1. Приветствие / инструкция
    2. Ввод команды/номера
    3. Условие - действие


    Создаём игру
            1. Чтение с файла player.txt ifstream и вывод на экран (name, hp, attack)
            2. А если 2 игрока. А если 1000 игроков?
        Функции
            3. Функция (формат функций)
            4. Но функция только читает файл, выводит на экран и не запоминает игрока.
            5. Какой тип данных вывести, чтоб сразу вернуть name,hp,attack ?  Никак. Оформим класс/структуру
        Классы/Структуры
            6. Создаём класс и метод isAlive
            7. Выводим функцию createHero в переменную Hero. Проверяем isAlive для игроков
            8. Создаем метод Kick(Hero enemy)
            9. Пытаемся ударить игрока (почему внешняя переменная не меняется?)
        Адреса, ссылки, указатели
            10. Используем указатель Hero*
            11. Проверяем Kick(Hero*)


*/