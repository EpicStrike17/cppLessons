#include "Drawable.h"

float Drawable::getDistance(Drawable* target)
{
	return sqrt(pow(target->y - y, 2) + pow(target->x - x,2));
}

void Drawable::setXY(int x, int y)
{
	this->x = x;
	this->y = y;
}
