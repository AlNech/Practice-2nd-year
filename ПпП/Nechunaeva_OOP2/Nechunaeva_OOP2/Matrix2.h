#pragma once
#include "Matrix.h"
class Matrix2 :
	public Matrix
{
private:
	string name;
	int n = 2;
	int** M;
public:
	//Конструктор
	Matrix2(string name);

	//Конструктор копирования
	Matrix2(Matrix2& const m);

	//Оператор копирования
	Matrix2& operator =(Matrix2& const m);

	//Геттеры и сеттеры
	string getName();

	//Деструктор
	~Matrix2();

	//Виртуальная функция
	double Definition();

	//Операторы ввода и вывода
	// Работа с потоками ввода и вывода
	friend ostream& operator<<(ostream& cout, Matrix2& a);
	friend istream& operator>>(istream& cin, Matrix2& a);

};

