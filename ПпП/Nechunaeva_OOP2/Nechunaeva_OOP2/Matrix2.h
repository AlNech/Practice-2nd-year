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
	//�����������
	Matrix2(string name);

	//����������� �����������
	Matrix2(Matrix2& const m);

	//�������� �����������
	Matrix2& operator =(Matrix2& const m);

	//������� � �������
	string getName();

	//����������
	~Matrix2();

	//����������� �������
	double Definition();

	//��������� ����� � ������
	// ������ � �������� ����� � ������
	friend ostream& operator<<(ostream& cout, Matrix2& a);
	friend istream& operator>>(istream& cin, Matrix2& a);

};

