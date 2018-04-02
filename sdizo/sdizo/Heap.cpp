#include "Heap.h"



Heap::Heap(int startingSize)
{
	if (startingSize >= 0) {
		size = 0;
		maxSize = startingSize;
		array = new int[maxSize];
	}
	else
		std::cout << "StartingSize must be not lower than 0" << std::endl;
}


Heap::~Heap()
{
	delete[] array;
}

void Heap::heapSort(int index)
{
	int leftChild = getLeftChild(index);
	int rightChild = getRightChild(index);
	int largest = index;
	if (leftChild < size && array[leftChild]> array[largest])
		largest = leftChild;
	if (rightChild < size && array[rightChild] > array[largest])
		largest = rightChild;

	if (largest != index) //Typical swap algorithm
	{
		int temp = array[index];
		array[index] = array[largest];
		array[largest] = temp;
		heapSort(largest);
	}
}


void Heap::extendHeap()
{
	
	maxSize = maxSize * 2; //We will contain a lot of element so i want to make sure it's not so often used
	int *temp = new int[maxSize];
	for (int i = 0; i <= maxSize / 2; i++)
	{
		
		temp[i]= array[i];
	}
	array = temp;
} //DONE

void Heap::push(int x)
{
	if (size == maxSize) //make sure you have free space for new element. If not, increase max size and reloc array
	{
		extendHeap(); 
	}

	size++;
	
	int ElementIndex = size-1;
	array[ElementIndex] = x;
	int parentIndex = getParent(ElementIndex);
	while (ElementIndex > 0 && array[parentIndex] < array[ElementIndex]) //check if you are bigger than your parent
	{
		int temp = array[parentIndex]; //parent copy
		array[parentIndex] = array[ElementIndex]; //parent node is now child
		array[ElementIndex] = temp; //child node is now parent;
		ElementIndex = parentIndex;
		parentIndex= getParent(ElementIndex);
	}
}

int Heap::pop()
{
	if (size == 1) 
	{
		size--;
		return array[0];
	}
	int root = array[0];
	array[0] = array[size - 1];
	size--;
	heapSort(0);
	return root;
}

void Heap::kill()
{
	delete[] array;
}

void Heap::print(std::string sp, std::string sn, int index)
{
	

	cr = cl = cp = "  ";
	cr[0] = 218;
	cr[1] = 196;
	cl[0] = 192; 
	cl[1] = 196;
	cp[0] = 179;
	std::string s;
	if (index < size)
	{
		s = sp;
		if (sn == cr) s[s.length() - 2] = ' ';
		print(s + cp, cr, 2 * index + 2);

		s = s.substr(0, sp.length() - 2);

		std::cout << s << sn << array[index] << std::endl;

		s = sp;
		if (sn == cl) s[s.length() - 2] = ' ';
		print(s + cp, cl, 2 * index + 1);
	}

}

int Heap::getParent(int index)
{
	int parentIndex = (index - 1) / 2;
	return parentIndex;
}

int Heap::getLeftChild(int index)
{
	int leftChildIndex = 2 * index + 1;
	return leftChildIndex;
}

int Heap::getRightChild(int index)
{
	int rightChildIndex = 2 * index + 2;
	return rightChildIndex;
}

void Heap::print()
{
	print("", "", 0);
}


bool Heap::contains(int value)
{
	
	for (int i = 0; i < size; i++)
	{
		if (array[i] = value)
			return true;
	}
	
	return false;
}

bool Heap::IsAHeap() {
	int parent;
	for (int i = 0; i < size; i++)
	{
		parent = getParent(i);
		if (array[i] > array[parent] ) {
			std::cout << "It's not a heap!ERROR" << std::endl;
			std::cout << array[i] <<"is bigger than his parent: " << array[parent] << std::endl;
			return false;
		}
		
	}
	std::cout << "It's  a heap! for sureee" << std::endl;
	return true;

}