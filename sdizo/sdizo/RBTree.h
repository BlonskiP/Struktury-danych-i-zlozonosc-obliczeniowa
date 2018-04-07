#pragma once
#include "Structure.h"



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
	
	
};

