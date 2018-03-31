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
	void heapSort(int index); // sorting
	void extendHeap(); // more space for heap
	void push(int x); // add int to heap
	int pop(); // return root 
	void kill(); //deletes array
	void print(std::string sp, std::string sn, int index); 
	int getParent(int index); // return parent id
	int getLeftChild(int index); // return left child id
	int getRightChild(int index); //returns right child id
	void print(); // no parameter version of print for easy use

	bool contains(int value); //checks if 'value' is in heap
	bool IsAHeap(); //tests if its a heap. compare parents with theis childern
};

