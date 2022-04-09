#pragma once
#include "Utilities.h"
#include "ScreenController.h"


class Drawable
{
public:
	vector<string> *pic;
	ScreenController* scene;
	int x = 0;
	int y = 0;
	float getDistance(Drawable* target);
	virtual void DoAction() = 0;
	virtual string getType() = 0;
	void setXY(int x, int y);
};

