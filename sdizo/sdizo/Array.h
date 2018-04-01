#pragma once
#include <cstdlib>
#include <stdio.h>
#include <iostream>
#include <string.h>
class Array
{
private:
	int actualSize = 0;
	int maxSize = 0;
	int* arrayPointer;
public:
	//Contructors
	Array();
	Array(int size);
	//Add fuctions
	void addInt(int x); 
	void addIntAtStart(int x);
	void addOnIndex(int x, int index);


	void printAll();
	
	//Searching
	bool contains(int x);
	void GetIndexes(int x);
	int GetInt(int index);
	
	//Delete form array
	void delLast();
	void delFirst();
	void delOnIndex(int index);


	void extendArray();
	~Array();
};

