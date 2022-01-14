#include "StudUnivTree.h"

StudUnivTree::StudUnivTree()
{
	root = nullptr;
}

StudUnivTree::~StudUnivTree()
{
	clear();
}

bool StudUnivTree::insert(Student& student)
{
	return insertStudent(root, student);
}

bool StudUnivTree::insertStudent(StudentNode*& root, Student& student)
{
	if (root == nullptr)
	{
		root = new StudentNode(student, nullptr, nullptr);
		return true;
	}
	else
	{
		if (student.getID() < root->student.getID())
			return insertStudent(root->left, student);
		else
			if (student.getID() > root->student.getID())
				return insertStudent(root->right, student);
			else
				return false;
	}
}

bool StudUnivTree::insertStudentLastName(StudentNode*& root, Student& student)
{
	if (root == nullptr)
	{
		root = new StudentNode(student, nullptr, nullptr);
		return true;
	}
	else
	{
		if (student.getLastName()< root->student.getLastName())
			return insertStudentLastName(root->left, student);
		else
			if (student.getLastName() > root->student.getLastName())
				return insertStudentLastName(root->right, student);
			else
				return false;
	}
}

bool StudUnivTree::DoNewTree(Student& student)
{
	return insertStudentLastName(root, student);
}

bool StudUnivTree::search(int ID, Student& student)
{
	return searchStudent(root, ID, student);
}

bool StudUnivTree::searchadress(string adress, Student& student)
{
	return searchadressroot(root, adress, student);
}

bool StudUnivTree::searchball(int minB, int maxB, Student& student)
{
	return searchballroot(root, minB, maxB, student);
}

bool StudUnivTree::searchballroot(StudentNode*& root, int minB, int maxB, Student& student)
{
	if (root != nullptr)
	{
		if ((root->student.getballsEGE()>=minB) && (root->student.getballsEGE() <= maxB))
		{
			cout << root->student << endl;
			searchballroot(root->left, minB, maxB, student);
			searchballroot(root->right, minB, maxB, student);
			return true;
		}
		else
			if ((root->student.getballsEGE() < minB) || (root->student.getballsEGE() > maxB)) {
				searchballroot(root->left, minB, maxB, student);
				searchballroot(root->right, minB, maxB, student);
				return false;
			}
				
	}
	else
		return false;
}

bool StudUnivTree::searchadressroot(StudentNode*& root, string adress, Student& student)
{
	if (root != nullptr)
	{
		if (root->student.getadress() == adress)
		{
			student = root->student;
			return true;
		}
		else
			if (adress != root->student.getadress())
				return searchadressroot(root->left, adress, student);
			else
				return searchadressroot(root->right, adress, student);
	}
	else
		return false;
}

bool StudUnivTree::searchStudent(StudentNode*& root, int ID, Student& student)
{
	if (root != nullptr)
	{
		if (root->student.getID() == ID)
		{
			student = root->student;
			return true;
		}
		else
			if (ID < root->student.getID())
				return searchStudent(root->left, ID, student);
			else
				return searchStudent(root->right, ID, student);
	}
	else
		return false;
}

bool StudUnivTree::erase(int ID)
{
	return eraseStudent(root, ID);
}

bool StudUnivTree::eraseStudent(StudentNode*& root, int ID)
{
	//void DeleteNode(TreeNode * &p, int k)
	{
		StudentNode* delnode;

		if (root == nullptr)
			return false;
		else
		{
			if (ID < root->student.getID())
				return eraseStudent(root->left, ID);
			else
				if (ID > root->student.getID())
					return eraseStudent(root->right, ID);
				else
				{
					delnode = root;
					if (delnode->right == nullptr)
						root = delnode->left;
					else
						if (delnode->left == nullptr)
							root = delnode->right;
						else
							del(delnode->left, delnode);
					delete delnode;
					return true;
				}
		}
	}
}

void StudUnivTree::del(StudentNode*& r, StudentNode*& delnode)
{
	if (r->right)
		del(r->right, delnode);
	else
	{
		delnode->student = r->student;
		delnode = r;
		r = r->left;
	}
	return;
}

void StudUnivTree::clear()
{
	clearStudUnivTree(root);
	root = nullptr;
	return;
}

void StudUnivTree::clearStudUnivTree(StudentNode* root)
{
	if (root != nullptr)
	{
		clearStudUnivTree(root->left);
		clearStudUnivTree(root->right);
		delete root;
	}
	return;
}

ostream& StudUnivTree::print(ostream& cout, StudentNode* root)
{
	if (root)
	{
		print(cout, root->left);
		cout << root->student << endl;
		print(cout, root->right);
	}
	return cout;
}

ostream& operator<<(ostream& cout, StudUnivTree& studUnivTree)
{
	cout << "--------------------------------------------" << endl;
	return 	studUnivTree.print(cout, studUnivTree.root)
		<< "--------------------------------------------" << endl;
}

