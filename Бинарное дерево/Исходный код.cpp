#include "BinaryTree.h"

Tree::Tree()
{
	x = 0;
	Tree* l = r = NULL;
}
void Tree::add(Tree* root, Tree* newEl)
{
	if (root->x > newEl->x)
	{
		if (root->l != NULL)
			add(root->l, newEl);
		else root->l = newEl;
	}
	if (root->x <= newEl->x)
	{
		if (root->r != NULL)
			add(root->r, newEl);
		else root->r = newEl;
	}
}
void Tree::search(Tree* Tree, int x)
{
	if (Tree != NULL)
	{
		while (Tree->x != x)
		{
			if (Tree->x > x&&Tree->l != NULL)
				search(Tree->l, x);
			else
			{
				if (Tree->x < x&&Tree->r != NULL)
					search(Tree->r, x);
				else cout << "\nElement isn't find\n";
			}
		}
		cout << "Left: " << Tree->l << "\tX: " << Tree->x << "\tRight: " << Tree->r;
	}
}
void Tree::fIn(string filename)
{
	ifstream fin;
	Tree* root = NULL;
	Tree* newEl = NULL;
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
void Tree::fOut(Tree* Node)const
{
	ofstream fout;
	string filename;
	cout << "Enter the filename\t";
	cin >> filename;
	fout.open(filename);
	if (Node != NULL)
	{
		Out(Node->l);
		fout << Node->x;
		Out(Node->r);
	}
	fout.close();
}
void Tree::Out(Tree* Node)const
{
	if (Node != NULL)
	{
		Out(Node->l);
		cout << Node->x;
		Out(Node->r);
	}
}