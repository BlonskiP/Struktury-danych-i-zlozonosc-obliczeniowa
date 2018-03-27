#pragma once
class Array
{
private:
	int actualSize = 0;
	int maxSize = 0;
	int* arrayPointer;
public:
	Array();
	Array(int size);
	~Array();
};

