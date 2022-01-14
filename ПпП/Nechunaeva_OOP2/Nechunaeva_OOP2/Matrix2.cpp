#include "Matrix2.h"

Matrix2::Matrix2(string name)
{
	this->name = name;
    M = (int**) new int[n];

    // �������� ������ ��� ������� ���������
    for (int i = 0; i < n; i++)
        M[i] = (int*)new int[n];

    // ��������� ������ M ������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}

Matrix2::Matrix2(Matrix2& const m)
{
    name = m.name;
    n = m.n;

    // �������� ������ ��� M
    M = (int**) new int* [n]; // ���������� �����, ���������� ����������

    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // ��������� ����������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
}

Matrix2& Matrix2::operator=(Matrix2& const m)
{
    if(n > 0)
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
    M = (int**) new int* [n]; // ���������� �����, ���������� ����������
    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // ��������� ����������
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
    return *this;
}

string Matrix2::getName()
{
    return this->name;
}

Matrix2::~Matrix2()
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

double Matrix2::Definition()
{
    return (M[0][0]*M[1][1]-M[0][1]*M[1][0]);
}

ostream& operator<<(ostream& cout, Matrix2& a)
{
    cout << a.name << endl;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.n; j++)
            cout <<setw(4)<<a.M[i][j];
        cout << endl;
    }
    return cout;
}

istream& operator>>(istream& cin, Matrix2& a)
{
    cout << "Enter 2-n Matrix" << endl;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.n; j++)
        {
            cin >> a.M[i][j];
        }
    return cin;
}
