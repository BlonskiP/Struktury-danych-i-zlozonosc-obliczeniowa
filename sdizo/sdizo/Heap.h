#pragma once
#include <iostream>
#include <string>
class Heap
{//Fast Reminder
//  Root is on top and is the biggest int (1st index in array)
//  Left child of 'i' node is 2*i
// Right child of 'i' node is 2*i+1


private:
	std::string cr, cl, cp;
	int *array;
	int maxSize;
	int size;
public:
	Heap(int startingSize);
	~Heap();
	void heapSort(int index);
	void extendHeap();
	void push(int x);
	int pop();
	void kill();
	void print(std::string sp, std::string sn, int index);
	int getParent(int index);
	int getLeftChild(int index);
	int getRightChild(int index);
	void print();
	bool contains(int value);
};

