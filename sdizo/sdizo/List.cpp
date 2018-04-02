#include "List.h"



void List::addElement(int x)
{
	if (firstElement == nullptr && listSize==0) //list is empty
	{
		firstElement = new Element;
		firstElement->vaule = x;
		lastElement = firstElement;
		listSize++;
	}
	else
	{
		lastElement->next = new Element;
		lastElement = lastElement->next;
		lastElement->vaule = x;
		listSize++;
	}

}
void List::printAll()
{
	elementPointer = firstElement;
	
	if (listSize >= 1)
	{
		for (int i = 1; i <= listSize; i++)
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
	if (listSize > 0)
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
	if (listSize == 0) addElement(x);
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
		listSize++;
		

	}
	
}
void List::addElementOnBeginning(int x){
	if (listSize != 0) {
		elementPointer = firstElement;
		firstElement = new Element;
		firstElement->next = elementPointer;
		firstElement->vaule = x;
		listSize++;
	}
	else
		addElement(x);
}
void List::deleteLastElement()
{
	elementPointer = firstElement;
	if (listSize > 0) {
		for (int i = 1; i < listSize; i++)
		{
			elementPointer = elementPointer->next;
		}
		delete lastElement;
		elementPointer->next = nullptr;
		lastElement = elementPointer;
		listSize--;
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

		listSize--;
	}
}
void List::deleteFirst()
{
	if (listSize > 0)
	{
		elementPointer = firstElement->next;
		delete firstElement;
		firstElement = elementPointer;
		listSize--;
	}
}
void List::clearAll() {
	elementPointer = firstElement;
	for (int i = 1; i <= listSize; i++)
	{
		Element *tmpNext;
		tmpNext = elementPointer->next;
		delete elementPointer;
		elementPointer = tmpNext;
		delete tmpNext;
	}
	listSize = 0;

}

bool List::contains(int x)
{
	elementPointer = firstElement;
	for (int i = 1; i < listSize; i++)
	{
		if (elementPointer != nullptr)
		{
			if (elementPointer->vaule == x) {
				std::cout << "Znaleziono element " << x << std::endl;
				return true;
			}
			elementPointer = elementPointer->next;
		}

	}
	std::cout << "Brak elementu w liscie :  " << x << std::endl;
	return false;
}

List::List()
{//Constructor with cleaning
	listSize = 0;
	elementPointer = nullptr;
	firstElement = nullptr;
	lastElement = nullptr;
}


List::~List()
{
}
