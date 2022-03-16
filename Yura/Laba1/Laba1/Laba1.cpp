// Laba1.cpp :
//  Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

class Animals {
public:
    Animals();
    Animals(const Animals& src);
    Animals(const char* _name, const char* _klass, int _avgweight);
    ~Animals();
    void setAvgWeigth(int weight){
        if (weight < 0) {
            std::cout << "value must be more than 0"<< std::endl;
            return;
        }
        avgweight = weight;
    }
    int getAvgWeight() {
        return avgweight;
    }
    void setName(const char* _name) {
        delete[] name;
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    char* getName() {
        char* copy = new char[strlen(name) + 1];
        strcpy(copy, name);
        return copy;
    }
    void setKlass(const char* _klass) {
        delete[] klass;
        klass = new char[strlen(_klass)+1];
        strcpy(klass, _klass);
    }
    char* getKlass() {
        char* copy = new char[strlen(klass) + 1];
        strcpy(copy, klass);
        return copy;
    }
private:
    char* name;
    char* klass;
    int avgweight;
};

Animals::Animals() {
    name = new char[8];
    klass = new char[8];
    strcpy(name, "unknown");
    strcpy(klass, "unknown");
    avgweight = 0;
}

Animals::Animals(const char* _name, const char* _klass, int _avgweight) {
    name = new char[strlen(_name)+1];
    strcpy(name, _name);
    klass = new char[strlen(_klass)+1];
    strcpy(klass, _klass);
    avgweight = _avgweight;
}

Animals::Animals(const Animals& src) {
    name = new char[strlen(src.name)+1];
    strcpy(name, src.name);
    klass = new char[strlen(src.klass)+1];
    strcpy(klass, src.klass);
    avgweight = src.avgweight;
};

Animals::~Animals() {
    delete[] name;
    delete[] klass;
}


void init() {
    int a = 7;
    std::string b = "asgard";
    char* gg = new char[50];
}

int main()
{
    std::cout << "Hello World!\n";
    Animals cat("cat", "cats", 10);
    Animals cat2 = cat;
    
    cat.setKlass("Koshak");
    cat.setAvgWeigth(50);
    std::cout << " weight of cat = " << cat.getAvgWeight() << std::endl;
    std::cout << " name of cat = " << cat.getName() << std::endl;
    std::cout << " klass of cat = " << cat.getKlass() << std::endl;


    
}


