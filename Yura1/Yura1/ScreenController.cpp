#include "ScreenController.h"

#include "Drawable.h"

ScreenController::ScreenController()
{
	_scr.assign(Ysize,"");
}


void ScreenController::addChild(Drawable* elem) {
	objects.push_back(elem);
	elem->scene = this;
}

vector<Drawable*> ScreenController::getObjects(){
	return objects;
}

void ScreenController::DoAction() {
	for (auto obj : objects) {
		obj->DoAction();
	}
}

void ScreenController::draw()
{	

	system("cls");
		std::string Frame = "";
		for (auto fnya : _scr) {
			Frame += fnya + '\n';
		}
		for (int x = 0; x < Xsize; x++) {
			Frame += "_";
		}
		cout << Frame<< endl;
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
	for(auto obj : objects) {
		add(obj->pic, obj->x, obj->y);
	}

	draw();

}
