#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class Tree
{
private:
	int x;
	Tree *l, *r;
public:
	Tree();
	void add(Tree* root, Tree* newEl);
	void search(Tree* Tree, int x);
	void fIn(string filename);
	void fOut(Tree* Node)const;
	void Out(Tree* Node)const;
};