#include "Manager.h"



Manager::Manager()
{
	structureExist = false;
	found = false;
	exit  = false;
}


Manager::~Manager()
{
	delete structure;
	
}
//Menus



void Manager::setStructurePointer()
{
	switch (structureType) 
	{
	case list: { listPointer = new List(); structure = listPointer;  break; }
	case heap: { heapPointer = new Heap(); structure = heapPointer;  break; }
	case array: { arrayPointer = new Array(); structure = arrayPointer;  break; }
	case redBlackTree: { treePointer = new RBTree(); structure = treePointer;  break; }
	}
	std::cout << "Structure has been created. Size = 0" << std::endl;
	std::cout << "Going back to StructureMenu " << std::endl;
	while (numberMeasurments < 1) {
		setMeasureTabSize();
		std::cin.clear();
	}
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

void Manager::addOnEnd()
{
	structure->addElement(givenInt);
}

void Manager::fillOnRandomIndex()
{
		structure->addElementOnIndex(givenInt, elementsArray[givenInt-((int)structureSize/10)]);
}

void Manager::addOnBeginning()
{
	structure->addElementOnBeginning(givenInt);
}

void Manager::deleteRandom()
{
	structure->deleteIndex(givenInt - ((int)structureSize / 10));

}

void Manager::deleteFirst()
{
	structure->deleteFirst();
}

void Manager::deleteLast()
{
	structure->deleteLastElement();
}

void Manager::containsRandom()
{
	structure->contains(givenInt);
}

void Manager::IsOnIndex()
{
	structure->getVaule(givenInt);
}

//Utility functions
//It creates array of random ints
void Manager::createArrayOfElements()
{
	if (structureSize <= 0)
	{
		std::cout << "I need more than 0 elements in the structure" << std::endl;
	}
	elementsArray = new int[structureSize];

	for (int i = 0; i < structureSize; i++) {
		elementsArray[i] = (rand() % 1000) - 500; //-50 to49;
	}
	//std::cout << "I created an array of ints (0 to 9999 vaule) we will add it to the structure" << std::endl;

}
void Manager::outPutStars()
{
	for (int i = 0; i < 80; i++)
		std::cout << "*";
}

int Manager::getNumber()
{
	std::cout << "Give me number or int" << std::endl;
#undef max
	while (!(std::cin >> givenInt)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	return givenInt;
}

int Manager::getIndex()
{
	return 0;
}

void Manager::ManualModeAddIndexChoose()
{
	if (structureExist == true) {
		if (structureSize == 0) {
			std::cout << "Structure Size is " << structureSize << std::endl;
			std::cout << "I will add your element on the 0 index " << structureSize << std::endl;
			structure->addElementOnBeginning(givenInt);
		}
		else {
			std::cout << "On what index? From 0 to " << structureSize << std::endl;
#undef max
			while (!(std::cin >>index)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			if (index <= structureSize) {
				structure->addElementOnIndex(givenInt, index);
			}
			else
				ManualModeAddIndexChoose();

		}
	}
	else
		std::cout << "You need to build a structure first" << std::endl; 

	structureSize = structure->size;
}

void Manager::ManualModeSubIndexChoose()
{
	if (structureExist == true) {
		if (structureSize == 0) {
			std::cout << "Structure is already empty " << std::endl;	
		}
		else {
			std::cout << "On what index? From 0 to " << structureSize << std::endl;
#undef max
			while (!(std::cin >> index)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			if (index <= structureSize) {
				structure->deleteIndex(givenInt);
			}
			else
				ManualModeSubIndexChoose();

		}
	}
	else
		std::cout << "You need to build a structure first" << std::endl;

	structureSize = structure->size;
}

void Manager::rewriteStructure(enum type newType)
{
	Structure *tmpPointer;
	switch (newType)
	{
	
	case list: {
		tmpPointer = new List();
		for (int i = 0; i < structureSize; i++)
		{
			tmpPointer->addElement(structure->getVaule(i));
			
		}
		structure = tmpPointer;
		break; }
	case heap: {	tmpPointer = new Heap();
		for (int i = 0; i < structureSize; i++)
		{
			tmpPointer->addElement(structure->getVaule(i));

		}
		structure = tmpPointer;
		break; }
	case redBlackTree: {
		tmpPointer = new RBTree();
		for (int i = 0; i < structureSize; i++)
		{
			tmpPointer->addElement(structure->getVaule(i));

		}
		structure = tmpPointer;
		break; }
	case array: {	tmpPointer = new Array();
		for (int i = 0; i < structureSize; i++)
		{
			tmpPointer->addElement(structure->getVaule(i));

		}
		structure = tmpPointer;
		break; }
	}

}


void Manager::measureADD()
{
	if (structureType == heap || structureType == redBlackTree) {
		std::cout << "I'm filling structure with random numbers." << std::endl;
		for (int i = 0; i < numberMeasurments; i++)
		{
			createArrayOfElements();
			measurementTab[i] = timeCount(&Manager::fillWithRandom);
			structure->clearAll();
			delete[] elementsArray;
		}
	}
	else
	{
		switch (operationType)
		{
		case indexType:
			{
			
	
			std::cout << "I'm filling structure with random numbers. I'm adding a new random element on the random index" << std::endl;

				for (int i = 0; i < numberMeasurments; i++)
				{
				createArrayOfElements();
				fillWithRandom();
				givenInt = (rand() % structureSize + ((int)structureSize/10));
				measurementTab[i] = timeCount(&Manager::fillOnRandomIndex);
				structure->clearAll();
				delete[] elementsArray;
				}
				break; 
			}
		case beginning:
			{
			std::cout << "I'm filling structure with random numbers. I'm adding a new random element on the beginning" << std::endl;
			for (int i = 0; i < numberMeasurments; i++) {
				createArrayOfElements();
				fillWithRandom();
				measurementTab[i] = timeCount(&Manager::addOnBeginning);
				delete[] elementsArray;
			}
				break;
			}
		case end:
		{
			std::cout << "I'm filling structure with random numbers. I'm adding a new random element on the end" << std::endl;
		
			for (int i = 0; i < numberMeasurments; i++)
			{
				createArrayOfElements();
				fillWithRandom();
				measurementTab[i] = timeCount(&Manager::addOnEnd);
				delete[] elementsArray;
				
			}
			break;
		}
		}
		
		}
		countMeasure();
	}


void Manager::measureDEL()
{
	if (structureType == heap || structureType == redBlackTree) {
		createArrayOfElements();
		fillWithRandom();
		std::cout << "I'm filling structure with random numbers. I'm getting and deleting 1st element" << std::endl;
		for (int i = 0; i < numberMeasurments; i++) {
			createArrayOfElements();
			fillWithRandom();
			measurementTab[i] = timeCount(&Manager::deleteFirst);
			structure->clearAll();
			delete[] elementsArray;

		}
	}
	else
	{
		switch (operationType)
		{
		case indexType:
		{
		
			std::cout << "I'm filling structure with random numbers. I'm deleting random element" << std::endl;
			for (int i = 0; i < numberMeasurments; i++)
			{
				createArrayOfElements();
				fillWithRandom();
				givenInt = (rand() % structureSize + ((int)structureSize / 10));
				measurementTab[i] = timeCount(&Manager::deleteRandom);
				structure->clearAll();
				delete[] elementsArray;
			}
			break;
		}
		case beginning:
		{
			std::cout << "I'm filling structure with random numbers. I'm deleting first element" << std::endl;
			
			for (int i = 0; i < numberMeasurments; i++) {
				createArrayOfElements();
				fillWithRandom();
				givenInt = rand() % structureSize;
				measurementTab[i] = timeCount(&Manager::deleteFirst);
				structure->clearAll();
				delete[] elementsArray;
			}
			break;
		}
		case end:
		{
			std::cout << "I'm filling structure with random numbers. I'm deleting last element " << std::endl;
		
			for (int i = 0; i < numberMeasurments; i++)
			{
				createArrayOfElements();
				fillWithRandom();
				givenInt = rand() % structureSize;
				measurementTab[i] = timeCount(&Manager::deleteLast);
				structure->clearAll();
				delete[] elementsArray;
				
			}
			break;
		}
		}

		

	}
	countMeasure();
}
void Manager::measureFindIndex()
{
	for (int i = 0; i < numberMeasurments; i++) {
		createArrayOfElements();
		fillWithRandom();
		delete[] elementsArray;
		givenInt = rand() % (structureSize);
		measurementTab[i] = timeCount(&Manager::IsOnIndex);
		structure->clearAll();

	}
	countMeasure();
}

void Manager::measureContains()
{
		for (int i = 0; i < numberMeasurments; i++) {
			createArrayOfElements();
			fillWithRandom();
			delete[] elementsArray;
			givenInt = (rand() % structureSize + ((int)structureSize / 10));
			measurementTab[i] = timeCount(&Manager::containsRandom);
			structure->clearAll();

		}
		countMeasure();

}


void Manager::setMeasureTabSize()
{
	using namespace std;
#undef max
		std::cout << "How many measurments do you want to do?";
		while (!(std::cin >> numberMeasurments)) {
			std::cin.clear();
			cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}
		measurementTab = new int[numberMeasurments];
		
		
	
}

void Manager::setStructureSize()
{

	std::cout << "What should be structure END size?";
#undef max
	while (!(std::cin >> structureSize)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	while (structureSize <= 0)
	{
		std::cout << "ERROR";
		std::cout << "What should be structure END size?";
#undef max
		while (!(std::cin >> structureSize)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}
	}

}

void Manager::countMeasure()
{
	std::cout << "Counting average measurment" << std::endl;
	measurement = 0;
	for (int i = 0; i < numberMeasurments; i++) {
		measurement += measurementTab[i];
	}
	measurement = measurement / numberMeasurments;
	std::cout << "Average time is: " << measurement << " [us] " << std::endl;
	system("pause");
	system("cls");
	structureMenu();
}



void Manager::setaddSubType()
{
	std::cout << "0 = Add on random index" << std::endl;
	std::cout << "1 = Add on beginning index" << std::endl;
	std::cout << "2 = Add on endIndex" << std::endl;

	std::cout << "If structure is a heap remeber that it will be heapified if necessary" << std::endl;
	int choice = 0;
#undef max
	while (!(std::cin >> choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	switch (choice) {
	case 0: {operationType = indexType; break; }
	case 1: {operationType = beginning; break; }
	case 2: {operationType = end; break; }
	default: {
		
		system("cls");
		std::cout << "error. Give me the type! 0 1 2" << std::endl;
		setaddSubType();
	}
	}
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
//	std::cout << "Time [s] = " << std::fixed << std::setprecision(3) << (float)elapsed / frequency << std::endl;
//	std::cout << "Time [ms] = " << std::setprecision(0) << (1000.0 * elapsed) / frequency << std::endl;
//	std::cout << "Time [us] = " << std::setprecision(0) << (1000000.0 * elapsed) / frequency << std::endl << std::endl;
	measure = (1000000.0 * elapsed) / frequency;
	return measure;
}