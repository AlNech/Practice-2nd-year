// Nechunaeva_OOP2.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
/*
    Задача:  У любой вещественной квадратной матрицы есть имя и можно найти её определитель. 
    Матрицы бывают двух видов - второго порядка (2х2) и третьего порядка(3х3). 
    Создать массив таких объектов и найти имя объекта-матрицы с наибольшим определителем.

    Вариант: 11
    Предмет: Практикум по программированию
    Студент: Нечунаева Алёна Игоревна
    Группа : ИТ-21
    Преподаватель: Анисимов А.Е.
*/

#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
#include <cassert>
#include "Matrix.h"
#include "Matrix2.h"
#include "Matrix3.h"

using namespace std;


int main()
{
    //Ввод матрицы второго порядка
    Matrix2 A("A");
    cin >> A;
    cout << A << "def = "<<A.Definition() << endl;
    //Ввод матриицы третьего порядка
    Matrix3 B("B");
    cin >> B;
    cout << B << "def = " << B.Definition() << endl;;

    
    struct maxM {
        string name;
        double Definition;
    };
    vector<maxM> maxdef;

    maxM Matrix1, Matrix2;
    Matrix1.name = A.getName();
    Matrix1.Definition = A.Definition();
    Matrix2.name = B.getName();
    Matrix2.Definition = B.Definition();

    maxdef.push_back(Matrix1);
    maxdef.push_back(Matrix2);


    string Namemax;
    double max = -10000;
    for (auto el:maxdef)
    {
        if (el.Definition > max)
        {
            max = el.Definition;
            Namemax = el.name;
        }
    }
    cout << Namemax<<" has max definition"<<endl;
}

