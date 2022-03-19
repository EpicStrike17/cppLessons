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
	string str = "";
	for (int i = 0; i < Xsize; i++) {
		str += symbol;
	}
	_scr.assign(Ysize, str);

}

void ScreenController::add(vector<string> *pic, int x, int y){

	if (!pic) return;
	if (x < 0 || y < 0 || x + pic[0].size() > Xsize || y + pic->size() > Ysize) {
		return;
	}
	for (int Yoffset = 0; Yoffset < pic->size(); Yoffset++) {
		string newStr = (*pic)[Yoffset];
		for (int Xoffset = 0; Xoffset < newStr.size(); Xoffset++) {
			_scr[y+ Yoffset][x + Xoffset] = newStr[Xoffset];
		}
	}
}

// Ќарисовать всех существ (мобов и игроков) на кадре
void ScreenController::drawAll()
{
	fill(' ');
	for(auto elem : h) { 
		add(elem->pic, elem->x, elem->y);
	}

	draw();

}
