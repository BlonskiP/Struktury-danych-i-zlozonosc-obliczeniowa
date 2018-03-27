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
