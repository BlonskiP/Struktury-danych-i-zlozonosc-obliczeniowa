#pragma once
#include <iostream>
#include "Structure.h"
struct Element {
	int vaule;
	Element *next;

};

class List : public Structure
{
private:
	Element *lastElement;
	Element *elementPointer;
	Element *firstElement;
	int listSize;
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
	List();
	~List();
};

