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
	extendArray(); //increase size by 1 and relocate the array
	
	arrayPointer[actualSize - 1] = x;
}

void Array:: printAll() 
{
	
		for (int ArrayIndex = 0; ArrayIndex < actualSize; ArrayIndex++)
		{
			printf("%i ", arrayPointer[ArrayIndex]);
		}
		printf("\n");
	

}
void Array::extendArray()
{
	if (maxSize <= actualSize) //Check if extension and relocation is nessesery
	arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int)); //memory block changes size. 
	if(maxSize<actualSize)
	maxSize++;
}

void Array::addIntAtStart(int x)
{
	actualSize++;
	extendArray();
	
	memmove(arrayPointer + 1, arrayPointer, (actualSize - 1) * sizeof(int)); //Copies, moves the table leaves space for one int at the start
	*arrayPointer = x;
	
}
void Array::addOnIndex(int x, int index) 
{
	if (index < actualSize && index >= 0) 
	{
		actualSize++;
		extendArray();
		
		memmove(arrayPointer + index + 1, arrayPointer + index, (actualSize - 1 - index) * sizeof(int));
		*(arrayPointer + index) = x;

	}
	else
		std::cout << "ERROR AT 'addOnIndex' method. Array is not large enough" << std::endl;
}
bool Array::contains(int x) 
{
	for (int i = 0; i < actualSize; i++) 
	{
		if (*(arrayPointer + i) == x)
		{
			std::cout << "found " << x << " Retured true" << std::endl;
			return true;
		}
	
	}
	std::cout << "Coudn't find " << x << " Retured false" << std::endl;
	return false;
}
void Array::GetIndexes(int x) 
{
	if (contains(x))
		
	{
		std::cout << x << " found on indexes: ";
		for (int i = 0; i < actualSize; i++) {
			if (*(arrayPointer + i) == x) 
			{
				std::cout << i << " ";
			}
			
		}
		std::cout << std::endl;

	}
	else
		std::cout << "THERE IS NO " << x << std::endl;

}
int Array::GetInt(int index) 
{
	if (index < maxSize && index >=0)
	{
		if (index < actualSize) 
		{
			return *(arrayPointer + index);
		}



	}
	else
	std::cout << "ERROR AT GetInt method: index out of range" << std::endl;

}

void Array::delLast()
{
	if (actualSize > 0) {
		maxSize--;
		actualSize--;
		arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int));
	}
	else
	std::cout << "ERROR on delLast method. Array is empty" << std::endl;
}

void Array::delFirst()
{
	if (actualSize > 0) {
		memmove(arrayPointer, arrayPointer + 1, (actualSize * sizeof(int)));
		actualSize--;
		maxSize--;
		arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int));
	}
	else
	std::cout << "ERROR on delFirst method. Array is empty" << std::endl;
}

void Array::delOnIndex(int index)
{
	if (index < actualSize && index >= 0)
	{
		actualSize--;
		maxSize--;
	

		memmove(arrayPointer + index , arrayPointer + index+1, (actualSize  - index) * sizeof(int));
		arrayPointer = (int*)realloc(arrayPointer, actualSize * sizeof(int));

	}
	else
		std::cout << "ERROR AT 'addOnIndex' method. Array is not large enough" << std::endl;

}
