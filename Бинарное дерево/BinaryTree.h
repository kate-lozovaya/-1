#include <iostream>
#include <string>
#include <fstream>
using namespace std;

struct Node
{
	int x;
	Node* left;
	Node* right;
};

class Tree
{
private:
	Node* root;
public:
	Tree();
	void add(Node* root, Node* newEl);
	void search(Node* node, int x);
	void fIn(string filename);
	void fOut(Node* node)const;
	void Out(Node* node)const;
};
