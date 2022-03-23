#include <iostream>
#include <fstream>

using namespace std;

int main()
{
	int n = 0;

	std::ifstream f("f.txt", fstream::in);
	if(f.is_open()){
		ofstream g_out("g.txt", fstream::out);
		ofstream h_out("h.txt", fstream::out);

		g_out << "\\\\ Четные числа"<<endl;
		h_out << "\\\\ Нечетные числа"<<endl;

		while (!f.eof()) {
			f >> n;
			if (n % 2 == 0) {
				g_out << n << " ";
			}
			else {
				h_out << n << " ";
			}
		}
		f.close();
	}
	else {
		cout << "File f doesn`t exist" << endl;
	}
	system("pause");
}

/*
14. Дан файл f, компоненты которого являются целыми числами. 
Записать в файл g все четные числа исходного файла, в файл h – все нечетные. Порядок
следования чисел сохраняется. Записать в файл g и h комментарии.
*/