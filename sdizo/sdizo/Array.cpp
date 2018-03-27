#include "Array.h"



Array::Array()
{
	arrayPointer = (int*)calloc(0, sizeof(int));
}
Array::Array(int size)
{
	maxSize = size;
	arrayPointer = (int*)calloc(size, sizeof(int));
}

Array::~Array()
{
}

void Array::addInt(int x) 
{
	actualSize++;
	if (actualSize > maxSize)
	{
		extendArray(); //increase size by 1 and relocate the array
	}
	arrayPointer[actualSize - 1] = x;
}

void Array:: printAll() 
{
	
		for (int ArrayIndex = 0; ArrayIndex < actualSize; ArrayIndex++) {
			printf("%i ", arrayPointer[ArrayIndex]);
		}
		printf("\n");
	

}
void Array::extendArray() 
{
	arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int)); //memory block changes size. 
	maxSize++;
}
