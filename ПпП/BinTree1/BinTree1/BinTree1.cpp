/*
    Задача:
    По входной последовательности вещественных чисел построить бинарное дерево.
    Вывести значение каждой вершины и среднее арифметическое её потомков (если он есть).

    Автор: Нечунаева А.И.
    Предмет: Практикум по программированию
    Дата: 08.12.2021
    Вариант: 11

*/

#include <iostream>
#include <iomanip>
#include <locale.h>
#include <vector>

using namespace std;


//Struct BinTree
struct TreeNode
{
    int info;
    int value;
    int counter;
    double arMean;

    TreeNode* left, * right ;
};

// Prototype of function
TreeNode* makeTree(int level);
void printTree(TreeNode*& root, const int level = 0);
void ArithmeticMean(TreeNode*& root, const int level = 0);


void main()
{
    setlocale(LC_ALL, "Russian");

    cout << "Введите дерево" << endl;
    TreeNode* root = makeTree(0);

    cout << "Введенное дерево:" << endl;
    printTree(root);

    int value = 0;
    int counter = 0;
    cout << "Вывод вершин и среднего значения его потомков" << endl;
    ArithmeticMean(root);

    system("pause");
    return;
}


//Input BinTree
TreeNode* makeTree(int level)
{
    char c;
    cout << setw(4 * level) << "" << "Создать вершину? (y/n)";
    cin >> c;
    if (c == 'y')
    {
        TreeNode* p = new TreeNode;
        cout << setw(4 * level) << "" << "Введите значение вершины:";
        cin >> p->info;

        cout << setw(4 * level) << "" << "Левое поддерево вершины " << p->info << endl;
        p->left = makeTree(level + 1);

        cout << setw(4 * level) << "" << "Правое поддерево вершины " << p->info << endl;
        p->right = makeTree(level + 1);
        return p;
    }
    else
        return NULL;


}


// Output BinTree
void printTree(TreeNode*& root, const int level)
{
    if (root)
    {
        printTree(root->left, level + 1);
        cout << setw(4 * level) << "" << root->info << endl;
        printTree(root->right, level + 1);
    }
    return;
}


void ArithmeticMean(TreeNode*& root, const int level)
{
    if (root) 
    {
        root->value = 0;
        root->counter = 0;

        
        
        ArithmeticMean(root->left, level + 1);
        ArithmeticMean(root->right, level + 1);
        
        if ((!root->left) && (!root->right)) {
            root->value += root->info;
        }
        if (root->left)
        {
            root->value += (root->left)->value;
            root->counter++ ;
        }
        if (root->right)
        {
            root->value += (root->right)->value;
            root->counter++;
        }
        
        
        
        if ((root->left) || (root->right)) {
            root->arMean = (double)((root->value) / (root->counter));
        }
        else {
            root->arMean = 0;
        }
        
        cout << "Вершина: " << root->info << "    Среднее арифметическое значение потомков: " << root->arMean << endl;
         
        
    }
    
}

