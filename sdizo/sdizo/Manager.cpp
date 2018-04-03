#include "Manager.h"



Manager::Manager()
{
	structureExist = false;
	found = false;
	exit  = false;
}


Manager::~Manager()
{
}
//Menus
void Manager::mainMenu()
{
	outPutStars();
	std::cout << "Welcome. Its a project made by Piotr Blonski" << std::endl;
	std::cout << "It will measure speed of operations on data structures which I implemented" << std::endl;
	std::cout << "Which one do you want to check?" << std::endl;
	std::cout << "1. Array" << std::endl;
	std::cout << "2. List" << std::endl;
	std::cout << "3. Heap" << std::endl;
	std::cout << "0. EXIT" << std::endl;
	outPutStars();
	std::cout << std::endl;
	std::cin >> choice;
	switch (choice)
	{
	case 1:structureType = array;  break;
	case 2:structureType = list; break;
	case 3:structureType = heap; break;
	case 0: exit = true; break;
	default:
		{system("cls");
		std::cout << "ERROR. Give me 1, 2 or 3 to precede" << std::endl;
		mainMenu();
		}
	}
	if (exit == false)
		structureMenu();
	
	
}

void Manager::structureMenu()
{
	
	outPutStars();
	std::cout << "It will measure speed of operations on data structures which I implemented" << std::endl;
	
	if (structureExist == true) {
		std::cout << "Your structure is Ready for experiment" << std::endl;
		std::cout << "Will make 100 measurments and arithmetic average " << std::endl;
		std::cout << "1.Measure ADD algorithms" << std::endl;
		std::cout << "2.Measure DELETE algorithms" << std::endl;
		std::cout << "3.Measure Search algorithms" << std::endl;
		std::cout << "4.Measure GetIndex Value algorithms" << std::endl;
		std::cout << "5.Print structure" << std::endl;
		std::cout << "6.Put structure in file" << std::endl;
		std::cout << "7.Delete Structure and Create New" << std::endl;
		std::cout << "0. EXIT" << std::endl;
		std::cin >> choice;
		switch (choice) 
		{
		case 1: {measureADD(); break; }
		case 2: {measureDEL(); break; }
		case 3: {measureContains(); break; }
		case 4: {measureFindIndex(); break; }
		case 5: {structure->printAll(); break; }
		case 6: {
			//TO DO
			break; }
		case 7: {
			//To DO
			break; }
		case 0: {break; }
		default: {
			system("cls");
			std::cout << "Give 1-7 and 0 to preced" << std::endl;
			structureMenu();
			 }
		}

	}
	else {
		std::cout << "We will create Structure now." << std::endl;
		setStructurePointer();
	}
	
	
	
	
}



void Manager::setStructurePointer()
{
	switch (structureType) 
	{
	case list: { listPointer = new List(); structure = listPointer;  break; }
	case heap: { heapPointer = new Heap(); structure = heapPointer;  break; }
	case array: { arrayPointer = new Array(); structure = arrayPointer;  break; }
	}
	std::cout << "Structure has been created. Size = 0" << std::endl;
	std::cout << "Going back to StructureMenu " << std::endl;
	system("Pause");
	system("cls");
	structureExist = true;
	structureMenu();
}

void Manager::createStructure()
{
	setStructurePointer();
}

void Manager::fillWithRandom()
{
	
	for (int i = 0; i < structureSize; i++)
		structure->addElement(elementsArray[i]);
}

//Utility functions
//It creates array of random ints
void Manager::createArrayOfElements()
{
	
	std::cout << "How many Elements do you want random?";
	std::cin >> structureSize;
	if (structureSize <= 0)
	{
		std::cout << "I need more than 0 elements in the list" << std::endl;
	}
	elementsArray = new int[structureSize];
	for (int i = 0; i < structureSize; i++) {
		elementsArray[i] = (rand() % 1000) - 500; //-50 to49;
	}
	std::cout << "I created an array of ints (0 to 9999 vaule) we will add it to the structure" << std::endl;

}
void Manager::outPutStars()
{
	for (int i = 0; i < 80; i++)
		std::cout << "*";
}

int Manager::getNumber()
{
	std::cout << "Give me int" << std::endl;
	std::cin >> givenInt;
	return givenInt;
}

int Manager::getIndex()
{
	return 0;
}

void Manager::measureADD()
{
	for (int i = 0; i < 100; i++) {
		createArrayOfElements();

	
	}
}

void Manager::measureDEL()
{
}

void Manager::measureFindIndex()
{
}

void Manager::measureContains()
{
}


//Time counting
long long int read_QPC()
{
	LARGE_INTEGER count;
	DWORD_PTR oldmask = SetThreadAffinityMask(GetCurrentThread(), 0);
	QueryPerformanceCounter(&count);
	SetThreadAffinityMask(GetCurrentThread(), oldmask);
	return((long long int)count.QuadPart);
}

int Manager::timeCount(void(Manager::* function)(void))
{
	int measure=0;
	long long int frequency, start, elapsed;
	QueryPerformanceFrequency((LARGE_INTEGER *)&frequency);
	start = read_QPC();
	(this->*function)();
	elapsed = read_QPC() - start;
	std::cout << "Time [s] = " << std::fixed << std::setprecision(3) << (float)elapsed / frequency << std::endl;
	std::cout << "Time [ms] = " << std::setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
	std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;

	return measure;
}