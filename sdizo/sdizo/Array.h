#pragma once
#include <cstdlib>
#include <stdio.h>
#include <string.h>
class Array
{
private:
	int actualSize = 0;
	int maxSize = 0;
	int* arrayPointer;
public:
	Array();
	Array(int size);
	void addInt(int x); //Adds new int at the end of the array
	void printAll();
	void extendArray();
	void addIntAtStart(int x);
	~Array();
};

