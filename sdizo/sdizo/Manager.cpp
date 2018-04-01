#include "Manager.h"

long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}

void Manager::createList()
{
	listPointer = new List();
	for (int i = 0; i < structureSize; i++)
		listPointer->addElement(elementsArray[i]);
}

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

void Manager::listMenu() {
	system("cls");
	outPutStars();
	std::cout << "Welocme to list Menu. I will cout time operacions" << std::endl;
	std::cout << "1. Create List" << std::endl;
	std::cout << "2. Add Item to list" << std::endl;
	std::cout << "3. Delete Item from list" << std::endl;
	std::cout << "4. Search for value" << std::endl;
	std::cout << "5. Search index" << std::endl;
	outPutStars();
	int listSize = 0;
	int choice;
	std::cin >> choice;
	bool choosen = false;
	while (choosen == false)
	{
		switch (choice) {
		case 1: {
			choosen = true;
			listPointer = new List();
			createArrayOfElements();
			timeCount(&Manager::createList);
		
		}
	
		case 2:choosen = true; break;
		case 3:choosen = true; break;
		case 4:choosen = true; break;
		case 5:choosen = true; break;
		default:
			std::cout << "Choose between 1-5" << std::endl;
			std::cin >> choice;
		}
		}
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
	std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed) /frequency << std::endl << std::endl;	std::cout << "The list will wait for you in list.txt file" << std::endl;


}

void Manager::createArray()
{
	std::cout << "a";
}



