#pragma once
#include <iostream>
#include "Array.h"
#include "Heap.h"
#include "List.h"
#include <ctime>
#include <Windows.h>
#include <iomanip>
class Manager
{
public:
	int *elementsArray;
	int structureSize = 0;
	int intToAdd;
	int index;
	bool found;
	void createArrayOfElements();
	void outPutStars();
	int getNumber();
	int getIndex();
	bool isStructureCreated = false;
	void showMainMenu();
	void timeCount(void (Manager::*function)(void));
	void createArray();
	//List Manage
	List *listPointer;
	void createList();
	void listAddMenu();
	void listMenu();
	void addToListOnStart();
	void addToListOnEnd();
	void addToListOnIndex();
	void deleteListMenu();
	void deleteFromListLast();
	void deleteFromListIndex();
	void deleteFromListBeginning();
	void searchInList();
	void listContains();
	//Heap Manage
	Heap *heapPointer;
	void createHeap();
	void heapMenu();
	//Array Mange
	Array *ArrayPointer;
	void arrayMenu();
	
	
	

	Manager();
	~Manager();
};

