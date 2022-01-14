/*
PersonSBTree - система хранения объектов класса Person. 
Хранение реализовано в структуре бинарного дерева поиска (Search Binary Tree) 
без поддержки сбалансированности.
Реализованы операции вставки, поиска и удаления объектов-вершин в бинарное дерево.
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

	StudentNode* root; // Корень бинарного дерева поиска

public:
	StudUnivTree();
	~StudUnivTree();

	// Вставка в дерево новой вершины, данные которой берутся из объекта person
	// Возвращает true в случае удачной вставки, и false, если объект с таким ключом в дереве уже есть	
	bool insert(Student& student);

	// Рекурсивная функция вставки в дерево с корнем root новой вершины 
	bool insertStudent(StudentNode*& root, Student& student);
	// Рекурсивная функция вставки в дерево с корнем root новой вершины идендитефикатором фамилией
	bool insertStudentLastName(StudentNode*& root, Student& student);
	//Создание нового дерева с ключем в виде фамилии
	bool DoNewTree(Student& student);

	// Поиск в дереве вершины по ключу ID
	// Возвращает 
	//   true в случае успешного поиска, при этом через параметр student передается найденный объект;
	//   false, если вершина с таким ключом в дереве отсутствует.	
	bool search(int ID, Student& student);

	// Поиск в дереве вершины по месту жительства	
	bool searchadress(string adress, Student& student);
	// Поиск в дереве вершины по баллам егэ от и до
	bool searchball(int minB, int maxB, Student& student);

	// Рекурсивная функция поиска в дереве с корнем root вершины с ЕГЭ
	bool  searchballroot(StudentNode * &root, int minB, int maxB, Student & student);
	// Рекурсивная функция поиска в дереве с корнем root вершины с местом жительства
	bool  searchadressroot(StudentNode*& root, string adress, Student& student);
	// Рекурсивная функция поиска в дереве с корнем root вершины с ключом ID
	bool  searchStudent(StudentNode*& root, int ID, Student& student);

	// Удаление в дереве вершины по ключу ID 
	// Возвращает 
	//   true в случае успешного удаления вершины;
	//   false, если вершина дерева с таким ключом в дереве отсутствует.	
	bool  erase(int ID);

	// Рекурсивная функция поиска и удаления в дереве с корнем root вершины с ключом keyInn
	bool  eraseStudent(StudentNode*& root, int ID);

	// Вспомогательная функция удаления вершины из БДП. 
	//Применяется в случае удаления вершины с двумя поддеревьями
	void  del(StudentNode*& r, StudentNode*& delnode);

	// Очистка бинарного дерева 
	void clear();

	// Рекурсивная функция очистки дерева с корнем root
	void clearStudUnivTree(StudentNode* root);

	friend ostream& operator<<(ostream& cout, StudUnivTree& studUnivTree);

	ostream& print(ostream& cout, StudentNode* root);
};

