#include "Spot.h"

Spot::Spot(int _x, int _y)
{
	this->x = _x;
	this->y = _y;
}

int Spot::getX()
{
	return this->x;
}

int Spot::getY()
{
	return this->y;
}

ostream& operator<<(ostream& cout, Spot& spot)
{
	cout << "x: " << spot.x << " y: " << spot.y<< "  ";
	return cout;
}
