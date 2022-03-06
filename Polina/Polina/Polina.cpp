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
            cout << "i am alive" << endl;
            return true;

        }
    }


};


Hero createh(string pass) {
    ifstream file(pass, fstream::in);
    
    Hero newplayer;


    file >> newplayer.name >> newplayer.hp >> newplayer.attack;
    cout << "\n name:" << newplayer.name;
    cout << "\n hp:" << newplayer.hp;
    cout << "\n attack:" << newplayer.attack;
    file.close();
    return newplayer;
}

int main()
{
    createh("player1.txt");
    createh("player2.txt");


    Hero player1;


    


    


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
