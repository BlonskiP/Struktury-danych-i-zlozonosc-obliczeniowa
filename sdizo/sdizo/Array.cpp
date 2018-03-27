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
	if (maxSize > actualSize)
	{
		arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int)); //memory block changes size. 
		
	}
	arrayPointer[actualSize - 1] = x;
}

void Array:: printAll() 
{
	
		for (int index_tablicy = 0; index_tablicy < actualSize; index_tablicy++) {
			printf("%i ", arrayPointer[index_tablicy]);
		}
		printf("\n");
	

}
