#pragma once
#include <iostream>
#include <string>
#include <iomanip>
#include <cassert>

using namespace std;

class Matrix
{
private:
	string name;
	int n;
	int** M;
public:
	//Конструктор
	Matrix();
	Matrix(string name, int n);

	//Конструктор копирования
	Matrix(Matrix& const m);

	//Оператор копирования
	Matrix& operator =(Matrix& const m);

	//Геттеры и сеттеры


	//Деструктор
	~Matrix();

	//Виртуальная функция
	virtual double Definition() = 0;

	//Операторы ввода и вывода
	// Работа с потоками ввода и вывода
	friend ostream& operator<<(ostream& cout, Matrix& a);
	friend istream& operator>>(istream& cin, Matrix& a);

};

