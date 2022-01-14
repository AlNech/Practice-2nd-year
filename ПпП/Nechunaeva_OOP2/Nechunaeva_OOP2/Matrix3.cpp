#include "Matrix3.h"

Matrix3::Matrix3(string name)
{
    this->name = name;
    M = (int**) new int[n];

    // Выделить память для каждого указателя
    for (int i = 0; i < n; i++)
        M[i] = (int*)new int[n];

    // заполнить массив M нулями
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = 0;
}

Matrix3::Matrix3(Matrix3& const m)
{
    name = m.name;
    n = m.n;

    // Выделить память для M
    M = (int**) new int* [n]; // количество строк, количество указателей

    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // заполнить значениями
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
}

Matrix3& Matrix3::operator=(Matrix3& const m)
{
    if (n > 0)
    {
        // освободить память, выделенную ранее для объекта *this
        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (n > 0)
    {
        delete[] M;
    }
    // Копирование данных M <= m
    name = m.name;
    n = m.n;

    // Выделить память для M опять
    M = (int**) new int* [n]; // количество строк, количество указателей
    for (int i = 0; i < n; i++)
        M[i] = (int*) new int[n];

    // заполнить значениями
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            M[i][j] = m.M[i][j];
    return *this;
}

string Matrix3::getName()
{
    return this->name;
}

Matrix3::~Matrix3()
{
    if (n > 0)
    {
        // освободить выделенную память для каждой строки
        for (int i = 0; i < n; i++)
            delete[] M[i];
    }

    if (n > 0)
        delete[] M;
}

double Matrix3::Definition()
{
    return (M[0][0]*(M[1][1]*M[2][2]-M[1][2]*M[2][1])- M[0][1] * (M[1][0] * M[2][2] - M[1][2] * M[2][0])+ M[0][2] * (M[1][0] * M[2][1] - M[1][1] * M[2][0]));
}

ostream& operator<<(ostream& cout, Matrix3& a)
{
    cout << a.name << endl;
    for (int i = 0; i < a.n; i++)
    {
        for (int j = 0; j < a.n; j++)
            cout << setw(4) << a.M[i][j];
        cout << endl;
    }
    return cout;
}

istream& operator>>(istream& cin, Matrix3& a)
{
    cout << "Enter 3-n Matrix" << endl;
    for (int i = 0; i < a.n; i++)
        for (int j = 0; j < a.n; j++)
        {
            cin >> a.M[i][j];
        }
    return cin;
}
