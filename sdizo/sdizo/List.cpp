#include "List.h"



void List::addElement(int x)
{
	if (firstElement == nullptr && size==0) //list is empty
	{
		firstElement = new Element;
		firstElement->vaule = x;
		lastElement = firstElement;
		size++;
	}
	else
	{
		lastElement->next = new Element;
		lastElement = lastElement->next;
		lastElement->next = nullptr;
		lastElement->vaule = x;
		size++;
	}

}
void List::printAll()
{
	elementPointer = firstElement;
	
	if (size >= 1)
	{
		for (int i = 1; i <= size; i++)
		{
			std::cout << elementPointer->vaule << std::endl;
			if (elementPointer->next != nullptr)
				elementPointer = elementPointer->next;
		}
	}
	else
		std::cout << "Pusta lista" << std::endl;
	
	
}
int List::getVaule(int index)
{
	elementPointer = firstElement;
	if (size > 0)
	{
		for (int i = 1; i <= index-1; i++)
		{
			elementPointer = elementPointer->next;
		}
	}
	return elementPointer->vaule;
}
void List::addElementOnIndex(int x, int index)
{
	Element *tmp;
	elementPointer = firstElement;
	if (size == 0) addElement(x);
	else 
	{
		for (int i = 1; i < index-1; i++)
		{
			if (elementPointer != nullptr)
			{
				elementPointer = elementPointer->next;
			}
			
		}
		//Adding a new element between them
		
		tmp = elementPointer->next;
		elementPointer->next = new Element;
		elementPointer->next->vaule = x;
		elementPointer->next->next = tmp;
		size++;
		

	}
	
}
void List::addElementOnBeginning(int x){
	if (size != 0) {
		elementPointer = firstElement;
		firstElement = new Element;
		firstElement->next = elementPointer;
		firstElement->vaule = x;
		size++;
	}
	else
		addElement(x);
}
void List::deleteLastElement()
{
	elementPointer = firstElement;
	if (size > 0) {
		for (int i = 1; i < size; i++)
		{
			elementPointer = elementPointer->next;
		}
		delete lastElement;
		elementPointer->next = nullptr;
		lastElement = elementPointer;
		size--;
}
}
void List::deleteIndex(int index)
{
	if (index == 1)
	{
		deleteFirst();
	}
	else
	{
		elementPointer = firstElement;

		for (int i = 1; i < index; i++)
			elementPointer = elementPointer->next;
		Element *tmp = elementPointer->next->next;
		delete elementPointer->next;
		elementPointer->next = tmp;

		size--;
	}
}
void List::deleteFirst()
{
	if (size > 0)
	{
		elementPointer = firstElement->next;
		delete firstElement;
		firstElement = elementPointer;
		size--;
	}
}
void List::clearAll() {
	Element *tmpNext;
	if (elementPointer != nullptr) {
		elementPointer = firstElement;
		while (true) {
			if (elementPointer->next != nullptr) {
				tmpNext = elementPointer->next;
				delete elementPointer;
				elementPointer = tmpNext;

			}
			else
				break;
		}
		elementPointer = nullptr;
		firstElement = nullptr;
		lastElement = nullptr;
		size = 0;

	}
}

bool List::contains(int x)
{
	elementPointer = firstElement;
	for (int i = 1; i < size; i++)
	{
		if (elementPointer != nullptr)
		{
			if (elementPointer->vaule == x) {
			//	std::cout << "FOUND: " << x << std::endl;
				return true;
			}
			elementPointer = elementPointer->next;
		}

	}
	//std::cout << "No element in the list :  " << x << std::endl;
	return false;
}

List::List()
{//Constructor with cleaning
	size = 0;
	elementPointer = nullptr;
	firstElement = nullptr;
	lastElement = nullptr;
}


List::~List()
{
}
