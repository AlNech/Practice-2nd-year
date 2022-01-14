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
	//�����������
	Matrix();
	Matrix(string name, int n);

	//����������� �����������
	Matrix(Matrix& const m);

	//�������� �����������
	Matrix& operator =(Matrix& const m);

	//������� � �������


	//����������
	~Matrix();

	//����������� �������
	virtual double Definition() = 0;

	//��������� ����� � ������
	// ������ � �������� ����� � ������
	friend ostream& operator<<(ostream& cout, Matrix& a);
	friend istream& operator>>(istream& cin, Matrix& a);

};

