#include "SetSpot.h"

SetSpot::SetSpot(vector<Spot>_setspots)
{
	this->setspots = _setspots;
}

int SetSpot::size()
{
	return setspots.size();
}

void SetSpot::MergeSet(vector<Spot> a, vector<Spot> b)
{
	for (auto el : setspots)
		b.push_back(el);
	for (auto el : a)
		b.push_back(el);
	cout << "Union" << endl;
	for (auto el : b)
	{
		cout << "(x,y): " << el << "   "<<endl;
	}
	cout << endl;
}

void SetSpot::IntersectionSet(vector<Spot>a, vector<Spot>b)
{
	
	for (auto el1 : setspots)
		for (auto el2 : a)
		{
			if ((el1.getX() == el2.getX()) && (el1.getY() == el2.getY()))
				b.push_back(el1);
		}
	cout << "Intersection" << endl;
	for (auto el : b)
	{
		cout << "(x,y): "<< el<<"   "<<endl;
	}
	cout << endl;

}

void SetSpot::DiffSet(vector<Spot>a, vector<Spot>b)
{
	for (auto el1 : setspots)
		for (auto el2 : a)
		{
			if ((el1.getX() != el2.getX()) || (el1.getY() != el2.getY()))
				b.push_back(el2);
		}
	
	cout << "DiffSet" << endl;
	for (auto el : b)
	{
		cout << "(x,y): " << el << "   " << endl;
	}
	cout << endl;
}


void SetSpot::print()
{
	for (auto el : setspots)
	{
		cout << "(x,y): " << endl;
	}

}

ostream& operator<<(ostream&, SetSpot& _setspot)
{
	cout << "Точки: "<< endl;
	_setspot.print();
	cout << endl;
	return cout;
}
