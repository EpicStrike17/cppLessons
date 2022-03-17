#include "ScreenController.h"

ScreenController::ScreenController()
{
	_scr.assign(Ysize,"");
}

void ScreenController::draw()
{
	system("cls");
	for (int y = 0;y < Ysize;y++) {
			cout << _scr[y] << endl;
	}

	for (int x = 0; x < Xsize; x++) {
		cout << "_";
	}
	cout << endl;
}

void ScreenController::fill(char symbol)
{
	wstring str = std::basic_string<wchar_t>();
	for (int i = 0; i < Xsize; i++) {
		str += symbol;
	}
	_scr.assign(Ysize, str);

}

void ScreenController::add(vector<wstring> *pic, int x, int y){
	if(pic)
	for (int Yoffset = 0; Yoffset < pic->size(); Yoffset++) {
		string newStr = (*pic)[Yoffset];
		for (int Xoffset = 0; Xoffset < newStr.size(); Xoffset++) {
			_scr[y+ Yoffset][x + Xoffset] = newStr[Xoffset];
		}
	}
}
