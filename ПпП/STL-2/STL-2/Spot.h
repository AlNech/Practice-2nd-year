#pragma once
#include <iostream>
#include <vector>
using namespace std;
//���������� ������ ����� � n-������ ������������
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

