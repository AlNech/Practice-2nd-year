/*
PersonSBTree - ������� �������� �������� ������ Person. 
�������� ����������� � ��������� ��������� ������ ������ (Search Binary Tree) 
��� ��������� ������������������.
����������� �������� �������, ������ � �������� ��������-������ � �������� ������.
*/
#pragma once
#include "Student.h"

class StudUnivTree
{
private:
	struct StudentNode {
		Student student;
		StudentNode* left, * right;
		StudentNode(Student student, StudentNode* left, StudentNode* right) {
			this->student = student;
			this->left = left;
			this->right = right;
		}
		StudentNode() {
			this->student = student;
			this->left = nullptr;
			this->right = nullptr;
		}
	};

	StudentNode* root; // ������ ��������� ������ ������

public:
	StudUnivTree();
	~StudUnivTree();

	// ������� � ������ ����� �������, ������ ������� ������� �� ������� person
	// ���������� true � ������ ������� �������, � false, ���� ������ � ����� ������ � ������ ��� ����	
	bool insert(Student& student);

	// ����������� ������� ������� � ������ � ������ root ����� ������� 
	bool insertStudent(StudentNode*& root, Student& student);
	// ����������� ������� ������� � ������ � ������ root ����� ������� ����������������� ��������
	bool insertStudentLastName(StudentNode*& root, Student& student);
	//�������� ������ ������ � ������ � ���� �������
	bool DoNewTree(Student& student);

	// ����� � ������ ������� �� ����� ID
	// ���������� 
	//   true � ������ ��������� ������, ��� ���� ����� �������� student ���������� ��������� ������;
	//   false, ���� ������� � ����� ������ � ������ �����������.	
	bool search(int ID, Student& student);

	// ����� � ������ ������� �� ����� ����������	
	bool searchadress(string adress, Student& student);
	// ����� � ������ ������� �� ������ ��� �� � ��
	bool searchball(int minB, int maxB, Student& student);

	// ����������� ������� ������ � ������ � ������ root ������� � ���
	bool  searchballroot(StudentNode * &root, int minB, int maxB, Student & student);
	// ����������� ������� ������ � ������ � ������ root ������� � ������ ����������
	bool  searchadressroot(StudentNode*& root, string adress, Student& student);
	// ����������� ������� ������ � ������ � ������ root ������� � ������ ID
	bool  searchStudent(StudentNode*& root, int ID, Student& student);

	// �������� � ������ ������� �� ����� ID 
	// ���������� 
	//   true � ������ ��������� �������� �������;
	//   false, ���� ������� ������ � ����� ������ � ������ �����������.	
	bool  erase(int ID);

	// ����������� ������� ������ � �������� � ������ � ������ root ������� � ������ keyInn
	bool  eraseStudent(StudentNode*& root, int ID);

	// ��������������� ������� �������� ������� �� ���. 
	//����������� � ������ �������� ������� � ����� ������������
	void  del(StudentNode*& r, StudentNode*& delnode);

	// ������� ��������� ������ 
	void clear();

	// ����������� ������� ������� ������ � ������ root
	void clearStudUnivTree(StudentNode* root);

	friend ostream& operator<<(ostream& cout, StudUnivTree& studUnivTree);

	ostream& print(ostream& cout, StudentNode* root);
};

