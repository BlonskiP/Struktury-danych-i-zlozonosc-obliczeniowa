#include "Manager.h"

long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}


//Array Functions
void Manager::arrayMenu()
{
	system("cls");
}

void Manager::createArrayOfElements()
{
	std::cout << "How many Elements do you want to have in structure?";
	std::cin >>  structureSize;
	if (structureSize <= 0)
	{
		std::cout << "I need more than 0 elements in the list" << std::endl;
	}
	elementsArray = new int[structureSize];
	for (int i = 0; i < structureSize; i++) {
		elementsArray[i] = (rand() % 60000); //0 to 9999 int;
	}
	std::cout << "I created an array of ints (0 to 9999 vaule) we will add it to the structure" << std::endl;

}
//List functions
#pragma region ListFunctions  
void Manager::createList()
{
	listPointer = new List();
	for (int i = 0; i < structureSize; i++)
		listPointer->addElement(elementsArray[i]);
}


void Manager::listMenu() {
	system("Pause");
	system("cls");
	outPutStars();
	std::cout << "Welocme to list Menu. I will cout time operacions" << std::endl;
	std::cout << "1. Create List" << std::endl;
	std::cout << "2. Add Item to list" << std::endl;
	std::cout << "3. Delete Item from list" << std::endl;
	std::cout << "4. Search index" << std::endl;
	std::cout << "5. Search for value" << std::endl;
	std::cout << "6. Show ALL and make a file" << std::endl;
	outPutStars();
	int listSize = 0;
	int choice = 0;
	std::cin >> choice;

	while (true)
	{
		switch (choice) {
		case 1: {
			
			listPointer = new List();
			createArrayOfElements();
			//HERE PUT FUCTION TO FILE
			timeCount(&Manager::createList);
			isStructureCreated = true;
			listMenu();
		}

		case 2:listAddMenu();
		case 3:deleteListMenu(); break;
		case 4: {
			std::cout << "What number do you want to check?";
			getNumber();
			timeCount(&Manager::listContains);
			
			if (found == true)
				std::cout << intToAdd << " Was found" << std::endl;
			else
				std::cout << intToAdd << " Was not found" << std::endl;
			listMenu();
		} break;
		case 5: {
			getIndex();
			timeCount(&Manager::searchInList);
			std::cout << " on " << index <<  " I found int= " << intToAdd << std::endl;

		
			listMenu();
		} break;
		case 6: {
			listPointer->showAll();
			

		
		}
		default:
			std::cout << "Choose between 1-5" << std::endl;
			std::cin >> choice;
		
		}
		}
	}

void Manager::addToListOnStart()
{
	listPointer->addElementOnBeginning(intToAdd);
}

void Manager::addToListOnEnd()
{
	listPointer->addElement(intToAdd);
}

void Manager::addToListOnIndex()
{
	listPointer->addElementOnIndex(intToAdd, index);
}

void Manager::deleteListMenu()
{
	std::cout << "So what do you want to delete from list?" << std::endl;
	std::cout << "1. Last Element" << std::endl;
	std::cout << "2. First Element" << std::endl;
	std::cout << "3. Index element" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
	
		timeCount(&Manager::deleteFromListLast);
		std::cout << "Number has been deleted" << std::endl;
		listMenu();
	}
	case 2: {
	
		timeCount(&Manager::deleteFromListBeginning);
		std::cout << "Number has been deleted" << std::endl;
		listMenu();
	}


	case 3: {
		getIndex();
		timeCount(&Manager::deleteFromListIndex);
		std::cout << "Number has been deleted" << std::endl;
		listMenu();
	}
	default: {break; }

	}


	listMenu();
}

void Manager::deleteFromListLast()
{
	listPointer->deleteLastElement();
}

void Manager::deleteFromListIndex()
{
	listPointer->deleteIndex(index);
}

void Manager::deleteFromListBeginning()
{
	listPointer->deleteFirst();
}
void Manager::searchInList()
{
	intToAdd= listPointer->getVaule(index);
}
void Manager::listContains()
{
	found=listPointer->contains(intToAdd);
}
void Manager::listAddMenu()
{
	std::cout << "Where do you want to add int?" << std::endl;
	std::cout << "1.At the beginning" << std::endl;
	std::cout << "2.At the end" << std::endl;
	std::cout << "3.On index" << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1: {
		getNumber();
		timeCount(&Manager::addToListOnStart);
		std::cout << "Number has been added" << std::endl;
		listMenu();
	}
	case 2: {
		getNumber();
		timeCount(&Manager::addToListOnEnd);
		std::cout << "Number has been added" << std::endl;
		listMenu();
	}


	case 3: {
		getNumber();
		getIndex();
		timeCount(&Manager::addToListOnIndex);
		std::cout << "Number has been added" << std::endl;
		listMenu();
	}
	default: {break; }

	}

}

#pragma endregion  
//Heap functions


void Manager::createHeap()
{
}

void Manager::heapMenu()
{
	system("cls");
}

void Manager::outPutStars()
{
	for (int i = 0; i < 80; i++)
		std::cout << "*";
}



int Manager::getNumber()
{
	std::cout << "Give me int" << std::endl;
	std::cin >> intToAdd;
	return intToAdd;
}

int Manager::getIndex()
{
	std::cout << "On what index?" << std::endl;
	std::cin >> index;
	return index;
}

Manager::Manager()
{
	showMainMenu();
}


Manager::~Manager()
{
}

void Manager::showMainMenu()
{
	outPutStars();
	std::cout << "Welcome. Its a project made by Piotr Blonski" << std::endl;
	std::cout << "It will measure speed of operations on data structures which I implemented" << std::endl;
	std::cout << "Which one do you want to check?" << std::endl;
	std::cout << "1. Array" << std::endl;
	std::cout << "2. List" << std::endl;
	std::cout << "3. Heap" << std::endl;
	outPutStars();
	std::cout << std::endl;
	int choice;
	std::cin >> choice;
	switch (choice)
	{
	case 1:arrayMenu();  break;
	case 2:listMenu(); break;
	case 3:heapMenu(); break;
	default:
		std::cout << "ERROR. Give me 1, 2 or 3 to precede";

	}
}

void Manager::timeCount(void(Manager::*function)(void))
{
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = read_QPC();
	(this->*function)();
	elapsed = read_QPC() - start;
	std::cout << "Time [s] = " << std::fixed << std::setprecision(3) << (float)elapsed /frequency << std::endl;
	std::cout << "Time [ms] = " << std::setprecision(0) << (1000.0 * elapsed) /frequency << std::endl;
	std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed) /frequency << std::endl << std::endl;
	

}

void Manager::createArray()
{
	std::cout << "a";
}



