#pragma once
#include <iostream>
#include <ctime>
#include <Windows.h>
#include <iomanip>
//My structures
#include "Structure.h"
#include "List.h"
#include "Array.h"
#include "Heap.h"
class Manager
{
private:
	Structure *structure;
	List * listPointer;
	Heap * heapPointer;
	Array * arrayPointer;
	enum type {
		list, heap, array
	}structureType;
	bool structureExist;
	bool found;
	bool exit;
	int index, givenInt, choice;
	int structureSize = 10;
	int measurement;
	int *measurementTab;
	int numberMeasurments=0;
	enum addSub {
		indexType, beginning, end
	}operationType = indexType;

public:
	int *elementsArray; // Contains random Ints to be put in structure
	//Constructor&Destructor
	Manager();
	~Manager();
	//Menus
	void mainMenu();
	void structureMenu();
	void manualMode();
	//Counter
	int timeCount(void (Manager::*function)(void)); //counts time for target funtion
	//Creation
	void setStructurePointer();
	void createStructure();
	void fillWithRandom();
	void deleteRandom();
	void containsRandom();
	void IsOnIndex();
	//Utility
	void createArrayOfElements();
	void outPutStars();
	int getNumber();
	int getIndex();
	void ManualModeAddIndexChoose();
	void ManualModeSubIndexChoose();
	//Measure
	void measureADD();
	void measureDEL();
	void measureFindIndex();
	void measureContains();
	void setMeasureTabSize();
	void setStructureSize();
	void countMeasure();
	void setaddSubType();
};

