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
	//�����������
	Matrix3(string name);

	//����������� �����������
	Matrix3(Matrix3& const m);

	//�������� �����������
	Matrix3& operator =(Matrix3& const m);

	//������� � �������
	string getName();

	//����������
	~Matrix3();

	//����������� �������
	double Definition();

	//��������� ����� � ������
	// ������ � �������� ����� � ������
	friend ostream& operator<<(ostream& cout, Matrix3& a);
	friend istream& operator>>(istream& cin, Matrix3& a);
};

