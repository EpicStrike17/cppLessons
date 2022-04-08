#pragma once
#include "Utilities.h"

class Drawable;

class ScreenController
{
public:
	ScreenController();
	void draw();
	void fill(char symbol =' ');
	void addChild(Drawable* elem);
	void add(vector<string>* pic, int x, int y);
	vector<Drawable*> getObjects();
	void DoAction();
	void drawAll();
	int Xsize = 290;
	int Ysize = 60;
	vector<string> _scr;

private:
	vector<Drawable*> objects;
//	Npc* e1;
};

