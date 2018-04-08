#pragma once
#include "Structure.h"
enum nodeColor {
	black, red

};

struct Node 
{
	Node *parent;
	Node *left;
	Node *right;
	int value;
	nodeColor color;
};




class RBTree : public Structure
{


public:
	//ADD METHODS
	void addElement(int x);
	void addElementOnIndex(int x, int index);
	void addElementOnBeginning(int x);
	//DEL METHODS
	void deleteLastElement();
	void deleteIndex(int index);
	void deleteFirst();
	void printAll();
	int getVaule(int index);
	void clearAll();
	bool contains(int x);
	RBTree();
	~RBTree();
private:
	Node *guard;
	Node * root;
	std::string cr, cl, cp;
	void print(std::string sp, std::string sn, Node * p); //Same in heap
	
};

