/*
Person - ����� �������������� ��������, ������ �� ������� ������ ������ � �������
*/
#pragma once
#include <iostream>
#include <string>
#include <iomanip>
using namespace std;


class Student
{
private:
	int ID;
	string LastName;
	string FirstName;
	string adress;
	int ballsEGE;
public:
	Student(int ID, string LastName, string FirstName, string adress, int ballsEGE);
	Student(Student& student);
	Student();
	~Student();


	string getLastName();
	string getFirstName();
	int getID();
	string getadress();
	int getballsEGE();


	friend ostream& operator<<(ostream& cout, Student& student);
};
