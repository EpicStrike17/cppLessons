// Massives.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include <queue>
#include <vector>
using namespace std;


	


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



	//INITIALIZATION



	int array[] = { 1, 45, 2, 5, 9 };
	cout << "Array: ";
	for (int a = 0; a < 5; a++) {
		cout << array[a];
		if (a < 4) {
			cout << ", ";
		}
	}
	cout << endl;





	vector<int> vec = { 1, 4, 5, 7, 12 };
	cout << "Vector: ";
	for (int v = 0; v != vec.size(); v++) {
		cout << vec[v];
		if (v < 4) {
			cout << ", ";
		}
	}
	cout << endl;



	int* dyar = new int[]{ 1, 4, 5, 14, 8 };
	cout << "Dynamic array: ";
	int counter = 0;
	for (int d = 0; d != 5; d++) {
		cout << dyar[d];
		if (counter < 5) {
			cout << ", ";
			counter++;
		}
	}
	cout << endl;



	queue <int> que;
	int q;
	cout << "Input 5 elements of queue: ";
	for (int l = 0; l < 5; l++) {
		cin >> q;
		que.push(q);
	}
	queue <int> copyque = que;
	cout << "Queue: ";
	counter = 0;
	for (copyque.front(); !copyque.empty(); copyque.pop()) {
		cout << copyque.front();
	 if (counter != 4) {
			cout << ", ";
			counter++;
		}
	}
	


	//ADD 3 ELEMENTS


	int random;
	
	cout << "\nNo possibility for adding elements in standart array\n";

	
	
	
	cout << "\nVector plus 3 elements: ";
	for (int c = 0; c != 3; c++) {
		random = rand() % 100;
		vec.push_back(random);
	}
	for (int v = 0; v < vec.size(); v++) {
		cout << vec[v];
		if (v < 7) {
			cout << ", ";
		}
	}



	
	cout << "\nDynamic array plus 3 elements: ";
	for (int d = 4; d != 8; d++) {
		random = rand() % 100;
		dyar[d] = random;
	}
	counter = 0;
	for (int d = 0; d != 8; d++) {
		cout << dyar[d];
		if (counter < 8) {
			cout << ", ";
		}
		counter++;
	}
	cout << endl;




	
	cout << "\nQueue plus 3 elements: ";
	for (int q = 0; q != 3; q++) {
		random = rand() % 100;
		que.push(random);
	}
	counter = 0;
	copyque = que;
	for (copyque.front(); !copyque.empty(); copyque.pop()) {
		cout << copyque.front();
		if (!copyque.empty()) {
			cout << ", ";
			counter++;
		}
	}



	//FIND "5" AND REMOVE THEM

	counter = 0;
	int fixarray[4];
	for (int a = 0; a != 5; a++) {
		int ch = array[a];
		if (ch != 5) {
			fixarray[counter] = ch;
			counter++;
		}
	}
	cout << "\nArray without element '5': ";
	for (int a = 0; a != 4; a++) {
		cout << fixarray[a];
		if (a < 3) {
			cout << ", ";
		}
	}
	cout << endl;
	




	for (int v = 0; v != vec.size(); v++) {
		if (vec[v] == 5) {
			vec.erase(vec.begin() + v);
		}
	}
	cout << "\nVector without element '5': ";
	for (int v = 0; v != vec.size(); v++) {
		cout << vec[v];
		if (v < 6) {
			cout << ", ";
		}
	}




	cout << "\nDyar without element '5': ";
	counter = 0;
	int* fixdyar = new int[7];
	for (int d = 0; d != 8; d++) {
		if (dyar[d] != 5) {
			fixdyar[counter] = dyar[d];
		}
		counter++;
	}
	for (int d = 0; d != 7; d++) {
		cout << fixdyar[d];
		if (counter < 7) {
			cout << ", ";
		}
		counter++;
	}
	cout << endl;




	cout << "\nQueue without element '5': ";
	copyque = que;
	q = 0;
	for (copyque.front(); !copyque.empty(); copyque.pop()) {
		if (copyque.front() == 5) {
			q = copyque.front();
		}
	}
	for (que.front(); !que.empty(); que.pop()) {
		if (que.front() != q) {
			copyque.push(que.front());
		}
	}
	for (copyque.front(); !copyque.empty(); copyque.pop()) {
		cout << copyque.front();
		if (!copyque.back()) {
			cout << ", ";
		}
	}

}
