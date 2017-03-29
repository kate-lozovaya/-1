#include "BinaryTree.h"

Tree::Tree()
{
	root->x = 0;
	root->left = root->right = NULL;
}
void Tree::add(Node* root, Node* newEl)
{
	if (root->x > newEl->x)
	{
		if (root->left != NULL)
			add(root->left, newEl);
		else root->left = newEl;
	}
	if (root->x <= newEl->x)
	{
		if (root->right != NULL)
			add(root->right, newEl);
		else root->right = newEl;
	}
}
void Tree::search(Node* node, int x)
{
	if (node != NULL)
	{
		while (node->x != x)
		{
			if (node->x > x&&node->left != NULL)
				search(node->left, x);
			else
			{
				if (node->x < x&&node->right != NULL)
					search(node->right, x);
				else cout << "\nElement isn't find\n";
			}
		}
		cout << "\nLeft: " << node->left << "\tX: " << node->x << "\tRight: " << node->right << endl;
	}
	else cout << "\nThere isn't tree\n";
}
void Tree::fIn(string filename)
{
	ifstream fin;
	Node* root = NULL;
	Node* newEl = NULL;
	fin.open(filename);
	if (!fin.is_open())
		cout << "The file isn't find" << endl;
	if (fin.eof())
		root->x = 0;
	else fin >> root->x;
	while (!fin.eof())
	{
		fin >> newEl->x;
		add(root, newEl);
	}
	fin.close();
}
void Tree::fOut(Node* node)const
{
	ofstream fout;
	string filename;
	cout << "Enter the filename\t";
	cin >> filename;
	fout.open(filename);
	if (node != NULL)
		Out(node);
	fout.close();
}
void Tree::Out(Node* node)const
{
	if (node != NULL)
	{
		Out(node->left);
		cout << node->x;
		Out(node->right);
	}
}
