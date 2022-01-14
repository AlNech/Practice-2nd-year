/*
Задача:
Множество точек. Реализовать классы - «точка n-мерного пространства» и «множество точек n-мерного пространства».
Для последнего класса реализовать операции:
объединение, пересечение и разность множеств.

Предмет: Практикум по программированию
Дата: 28.12.2021
Вариант: 11

*/
#include <iostream>
#include <iomanip>
#include <set>
#include <algorithm>
#include "Spot.h"
#include "SetSpot.h"
using namespace std;


int main()
{
	//Задаем координаты точек на XY
	Spot a(1, 1), b(1, 2), c(1, 5), d(2, 3); 
	//Создание множеств из этих точек
	vector<Spot> s1{ a,b,c,d }, s2{ a,b,d }, s3,s4,s5;
	SetSpot ss1(s1);

	//Объединение
	ss1.MergeSet(s2, s3);
	//Пересечение
	ss1.IntersectionSet(s2, s4);
	//Разница
	ss1.DiffSet(s2, s5);
	
	

	
	
}