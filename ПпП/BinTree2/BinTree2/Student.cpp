#include "Student.h"

Student::Student(int ID, string LastName, string FirstName, string adress, int ballsEGE)
{
	this->ID = ID;
	this->LastName = LastName;
	this->FirstName = FirstName;
	this->adress = adress;
	this->ballsEGE = ballsEGE;
}

Student::Student(Student& student)
{
	this->ID = student.ID;
	this->LastName = student.LastName;
	this->FirstName = student.FirstName;
	this->adress = student.adress;
	this->ballsEGE = student.ballsEGE;
}

Student::Student()
{
	this->ID = 0;
	this->LastName = "";
	this->FirstName = "";
	this->adress = "";
	this->ballsEGE = 0;
}

Student::~Student()
{
}

string Student::getLastName()
{
	return LastName;
}

string Student::getFirstName()
{
	return FirstName;
}

int Student::getID()
{
	return ID;
}

string Student::getadress()
{
	return adress;
}

int Student::getballsEGE()
{
	return ballsEGE;
}

ostream& operator<<(ostream& cout, Student& student)
{
	return cout << setw(14) << student.ID << setw(14) << student.LastName << setw(14) << student.FirstName << setw(30) << student.adress << setw(14) << student.ballsEGE;
}



