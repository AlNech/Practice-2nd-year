/*
Задача:
Дан список из n целых чисел 𝑎0, 𝑎1, … , 𝑎𝑛−1 (|𝑎𝑖|100). Из группы подряд идущих
одинаковых чисел оставить только одно.

Автор: Нечунаева А.И.
Предмет: Практикум по программированию
Дата: 18.11.2021

*/

#include <iostream>
#include <iomanip>
#include <time.h>
#include <locale.h>


using namespace std;

struct List
{
	int info;
	List* pred, * next;
};

//Функция вставляет элемент p в список после элемента last
// возвращает указатель на вставленный в список элемент
List* insertElementIntoList(List* last, List* p)
{
	if (last && p)
	{
		p->pred = last;
		p->next = last->next;
		last->next = p;
		p->next->pred = p;
		return p;
	}
	else
		return NULL;
}

// Функция создает двусвязный список из n элементов с двумя сторожами
// Через head возвращает указатель на головного сторожа, 
// через tail - на хвостового сторожа
void createRandomList(List*& head, List*& tail, int n)
{
	head = new List;
	tail = new List;

	head->next = tail;
	tail->pred = head;

	List* last = head;
	srand(time(NULL));
	for (int i = 0; i < n; i++)
	{
		List* p = new List;
		p->info = rand() % 5 ;
		last = insertElementIntoList(last, p);
	}

	return;
}



// Функция печатает на консоль значения двусвязного списка
// с двумя сторожами head и tail

void printList(List* head, List* tail)
{
	List* p = head->next;
	while (p != tail)
	{
		cout << setw(6) << p->info;
		p = p->next;
	}
	cout << endl;
	return;
}

// Функция исключает элемент р из списка, возвращает указатель на
// элемент, следовавший после него
List* removeElement(List* p)
{
	if (p)
	{
		List* p1 = p->pred;
		List* p2 = p->next;
		p1->next = p2;
		p2->pred = p1;
		p->pred = p->next = NULL;
		return p2;
	}
	else
		return NULL;
}

// Функция удаляет из списка элементы групп с одинаковым значением
// head - головной сторож, tail - хвостовой сторож
void deleteSamElementsFromList(List* head, List* tail)
{
	
	List* p = head->next;
	List* pr = head;
	while (p != tail) {
		if (p->info == pr->info) {
			removeElement(pr);
		}
		pr = p;
		p = p->next;
		
	}

	return;
}




// Функция удаляет список
void deleteList(List* head, List* tail)
{
	List* p = head;
	while (p != tail)
	{
		List* p1 = p->next;
		delete p;
		p = p1;
	}
	delete tail;
}

void main()
{
	setlocale(LC_ALL, "Rus");

	List* head = NULL, * tail = NULL;

	cout << "Исходный список" << endl;
	createRandomList(head, tail, 10);
	printList(head, tail);

	cout << "Список после удаления из группы подряд идущих одинаковых чисел" << endl;
	deleteSamElementsFromList(head, tail);
	printList(head, tail);

	
	deleteList(head, tail);

	system("pause");
	return;
}