#include "Matrix.h"

Matrix::Matrix()
{
    this->n = 0;
    this->name = "";
    this->M = nullptr;
}

Matrix::Matrix(string name, int n)
{
	this->name = name;
	this->n = n;
	assert(n > 0);
	M =(int**) new int[n];

    // �������� ������ ��� ������� ���������
    for (int i = 0; i < n; i++)
        M[i] = (int*)new int[n];

    // ��������� ������ M ������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}

Matrix::Matrix(Matrix& const m)
{
    name = m.name;
    n = m.n;

    // �������� ������ ��� M
    M = (int**) new int * [n]; // ���������� �����, ���������� ����������

    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // ��������� ����������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
}

Matrix& Matrix::operator=(Matrix& const m)
{
    if (n > 0)
    {
        // ���������� ������, ���������� ����� ��� ������� *this
        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (n > 0)
    {
        delete[] M;
    }

    // ����������� ������ M <= m
    name = m.name;
    n = m.n;

    // �������� ������ ��� M �����
    M = (int**) new int * [n]; // ���������� �����, ���������� ����������
    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // ��������� ����������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
    return *this;

 }

Matrix::~Matrix()
{
    if (n > 0)
    {
        // ���������� ���������� ������ ��� ������ ������
        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (n > 0)
        delete[] M;
}

ostream& operator<<(ostream& cout, Matrix& a)
{
    cout << a.name << endl;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.n; j++)
            cout << a.M[i][j] << setw(3);
    cout << endl;
    return cout;
}

istream& operator>>(istream& cin, Matrix& a)
{
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.n; j++)
        {
            cin >> a.M[i][j];
            cout << setw(3);
        }
    return cin;
}
