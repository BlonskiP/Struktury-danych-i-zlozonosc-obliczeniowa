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
	List *listPointer;
	Heap *heapPointer;
	Array *ArrayPointer;
	bool isStructureCreated = false;
	void showMainMenu();
	void timeCount(void (Manager::*function)(void));
	void createArray();
	void createList();
	void createHeap();
	void arrayMenu();
	void createArrayOfElements();
	void listMenu();
	void heapMenu();
	void outPutStars();
	Manager();
	~Manager();
};

