#include <iostream>
#include <string>
#include <queue>
#include "Laba3.h"

using namespace std;
class File
{
public:
    File(std::string fname) {
        name = fname;
        createTime = time(0);
        hitNumber = 0;
    };
    std::string name;
    time_t createTime;
    int hitNumber;
};

class FileSys {
public:
    queue<File*> files;
    void AddFileBefore(File* f, std::string targetName) {
        queue<File*> refiles;
        bool fadded = false;
        while (!files.empty()) {
            if (targetName == files.front()->name) {
                refiles.push(f);
                fadded = true;
            }
            refiles.push(files.front());
            files.pop();
        }
        files = refiles;
        if (!fadded) {
            cout << "Не удалось найти файл " << targetName << endl;
        }
    }
    void AddFileAfter(File* f, std::string targetName) {
        queue<File*> refiles;
        bool fadded = false;
        while (!files.empty()) {
            refiles.push(files.front());
            if (targetName == files.front()->name) {
                refiles.push(f);
                fadded = true;
            }
            files.pop();
        }
        files = refiles;
        if (!fadded) {
            cout << "Не удалось найти файл " << targetName << endl;
        }
    }


    void Show() {
        cout << "FILES LIST:" << endl;
        cout << "файл\t\tсоздан\t\tобращений" << endl;

        if (!files.empty()) {
            queue<File*> copy = files;

            while (!copy.empty()) {
                File* tmpFile = copy.front();
                cout << tmpFile->name << "\t\t" << tmpFile->createTime << "\t" << tmpFile->hitNumber << endl;
                copy.pop();
            }
        }

        cout << "files count: " << files.size() << endl;
    }

    void DelOldFiles(time_t t) {
        queue<File*> refiles;
        while (!files.empty()) {
            if (files.front()->createTime > t) {
                refiles.push(files.front());
            }
            files.pop();
        }
        files = refiles;
    }

    File* getFile(std::string fname) { 
        queue<File*> refiles;
        File* foundFile = nullptr;
        while (!files.empty()) {
            if (files.front()->name == fname) {
                foundFile = files.front();
            }
            refiles.push(files.front());
            files.pop();
        }
        files = refiles;

        if (!foundFile) {
            cout << "Файл не найден" << endl;
        }
        else {
            foundFile->hitNumber++;
        }
        return foundFile;
    }
    
    File* getPopular() {
        queue<File*> refiles;
        if (files.empty()) {
            cout << "Файлов нет" << endl;
            return nullptr;
        }

        File* popular = files.front();
        while (!files.empty()) {
            if (files.front()->hitNumber > popular->hitNumber) {
                popular = files.front();
            }
            refiles.push(files.front());
            files.pop();
        }
        files = refiles;
        return popular;
    }
};

int main()
{

    string cmd = "";
    setlocale(LC_ALL, "Russian");
    FileSys fs;
    fs.files.push(new File("fi1"));
    fs.files.push(new File("fi2"));
    fs.files.push(new File("fi3"));
    fs.files.push(new File("fi4"));
    fs.files.push(new File("fi5"));
    while (cmd != "0") {
        cout << "Команды:" << endl
         << "1)Показать очередь" << endl
         << "2)Добавить файл перед указанного" << endl
         << "3)Добавить файл после указанного" << endl
         << "4)Команда удаления файлов, созданных раннее: " << endl
         << "5) Найти файл " << endl
         << "6) Вывести самый часто запрашиваемый файл " << endl
         << "0)Выход из программы" << endl
         << "Введите команду: " << endl;
        cin >> cmd;
        if (cmd == "1") {
            fs.Show();
        }
        else if (cmd == "2") {
            string n;
            string k;
            cout << "Введите имя файла, который будет добавляется: ";
            cin >> n;
            cout << "Введите имя файла, который будет указателем: ";
            cin >> k;
            fs.AddFileBefore(new File(n), k);
        }
        else if (cmd == "3") {
            string n;
            string k;
            cout << "Введите имя файла, который будет добавляется: " ;
            cin >> n;
            cout << "Введите имя файла, который будет указателем: ";
            cin >> k;
            fs.AddFileAfter(new File(n), k);
        }
        else if (cmd == "4") {
            string n;
            cout << "Введите дату создания файлов(до этой даты все файлы удалятся)" ;
            cin >> n;
            time_t tm = atoi(n.c_str());
            if (tm <= 0) {
                cout << "Дата должна быть положительным целым числом";
            }
            else {
                fs.DelOldFiles(tm);
            }
        }
        else if (cmd == "5") {
            string fname = "";
            cout << "Введите имя файла: ";
            cin >> fname;
            if (File* found = fs.getFile(fname)) {
                cout << "Найденный файл: " << found->name << " (обращений: " << found->hitNumber << ")" << endl;
            }
        }
        else if (cmd == "6") {
            if (File* popular = fs.getPopular()) {
                cout << "Самый популярный файл: " << popular->name << " (обращений: "<<popular->hitNumber<<")" << endl;
            } 
        }
    }

    system("pause");
}

/*
14. В файловой системе каталог файлов организован в виде стека или очереди. Для
каждого файла в каталоге содержатся следующие сведения:
• имя файла;
• дата создания;
• количество обращений к файлу.
Написать программу, которая обеспечивает:
++ начальное формирование каталога файлов;
++ добавление файла перед указанным.
++ добавление файла после указанного.
++ вывод каталога файлов;
++ удаление файлов, дата создания которых меньше заданной;
++ выборку файла с наибольшим количеством обращений.
++Программа должна обеспечивать диалог с помощью меню и контроль ошибок при вводе.

*/