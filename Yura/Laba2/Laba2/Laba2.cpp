#include <iostream>
using namespace std;


int main()
{
	int sum = 0;
	int arr[10];
	srand(time(0));

	int N;
	cout << "Type N: ";
	cin >> N;

	cout<< "\nArray: ";
	bool sign = true;
	
	for (int i = 0; i < N; i++) {
		*(arr + i) = rand() % 100;
		cout << *(arr + i) << " ";

		sum += (sign ? 1 : -1) * *(arr + i);
		sign = !sign;
	};


	cout<< "\nSum: "<< sum<< endl;

	cout << endl;
	system("pause");
}