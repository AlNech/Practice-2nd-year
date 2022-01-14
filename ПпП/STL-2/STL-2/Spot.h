#pragma once
#include <iostream>
#include <vector>
using namespace std;
//Реализация класса точек в n-мерном пространстве
class Spot 
{
private:
	int x, y;
public:
	Spot();
	Spot(int, int);
	int getX();
	int getY();
	friend ostream& operator<<(ostream&, Spot& spot);
};

