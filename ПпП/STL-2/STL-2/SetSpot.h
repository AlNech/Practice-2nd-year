#pragma once
#include <iostream>
#include <algorithm>
#include <set>
#include "Spot.h"

using namespace std;
//Реализация множества точек
class SetSpot
{
private: vector<Spot> setspots;
public:
	SetSpot();
	SetSpot(vector<Spot>);
	int size();

	void MergeSet(vector<Spot>, vector<Spot>);
	void IntersectionSet(vector<Spot>, vector<Spot>);
	void DiffSet(vector<Spot>, vector<Spot>);


	void print();
	friend ostream& operator<<(ostream&, SetSpot& _setspot);
};
