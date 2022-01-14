#pragma once
#include "Matrix.h"
class Matrix3 :
	public Matrix
{

private:
	string name;
	int n = 3;
	int** M;
public:
	//Конструктор
	Matrix3(string name);

	//Конструктор копирования
	Matrix3(Matrix3& const m);

	//Оператор копирования
	Matrix3& operator =(Matrix3& const m);

	//Геттеры и сеттеры
	string getName();

	//Деструктор
	~Matrix3();

	//Виртуальная функция
	double Definition();

	//Операторы ввода и вывода
	// Работа с потоками ввода и вывода
	friend ostream& operator<<(ostream& cout, Matrix3& a);
	friend istream& operator>>(istream& cin, Matrix3& a);
};

