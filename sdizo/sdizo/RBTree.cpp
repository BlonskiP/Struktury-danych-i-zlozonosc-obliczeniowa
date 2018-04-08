#include "RBTree.h"



RBTree::RBTree()
{
	cr = cl = cp = "  ";
	cr[0] = 218; cr[1] = 196;
	cl[0] = 192; cl[1] = 196;
	cp[0] = 179;
	// Guard is initialized
	guard = new Node(); 
	guard->color = black; //always black         
	guard->parent = guard; //all guards pointers points himself
	guard->left = guard;
	guard->right = guard;
	root = guard;           // When there is no nodes. Root will point guard

}


RBTree::~RBTree()
{
}

void RBTree::print(std::string sp, std::string sn, Node * p)
{
}

void RBTree::addElement(int x)
{
}

void RBTree::addElementOnIndex(int x, int index)
{
}

void RBTree::addElementOnBeginning(int x)
{
}

void RBTree::deleteLastElement()
{
}

void RBTree::deleteIndex(int index)
{
}

void RBTree::deleteFirst()
{
}

void RBTree::printAll()
{
}

int RBTree::getVaule(int index)
{
	return 0;
}

void RBTree::clearAll()
{
}

bool RBTree::contains(int x)
{
	return false;
}
