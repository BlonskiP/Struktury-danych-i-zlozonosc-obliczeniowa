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
void Manager::mainMenu()
{
	
#undef max
	outPutStars();
	std::cout << "Welcome. Its a project made by Piotr Blonski" << std::endl;
	std::cout << "It will measure speed of operations on data structures which I implemented" << std::endl;
	std::cout << "Which one do you want to check?" << std::endl;
	std::cout << "1. Array" << std::endl;
	std::cout << "2. List" << std::endl;
	std::cout << "3. Heap" << std::endl;
	std::cout << "4. Red Black Tree" << std::endl;
	std::cout << "0. EXIT" << std::endl;
	outPutStars();
	std::cout << std::endl;
	while (!(std::cin >>choice)) {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		std::cout << "Invalid input.  Try again: ";
	}
	switch (choice)
	{
	case 1:structureType = array;  break;
	case 2:structureType = list; break;
	case 3:structureType = heap; break;
	case 4:structureType = redBlackTree; break;
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
	delete measurementTab;
	measurementTab = new int[numberMeasurments]; //clear table
#undef max
	outPutStars();
	std::cout << "It will measure speed of operations on data structures which I implemented" << std::endl;
	
	if (structureExist == true) {
		structure->clearAll();
		std::cout << "Your structure is Ready for experiment" << std::endl;
		std::cout << "Will make  measurments and arithmetic average " << std::endl;
		std::cout << "1.Measure ADD algorithms" << std::endl;
		std::cout << "2.Measure DELETE algorithms" << std::endl;
		std::cout << "3.Measure Search algorithms" << std::endl;
		std::cout << "4 .(List and Array) .Measure GetIndex Value algorithms" << std::endl;
	    std::cout << "5. Set number of measurments Actual is" << numberMeasurments << std::endl;
		std::cout << "6. Set structure size. Actual is " << structureSize << std::endl;
		std::cout << "7.(List and Array) Set add/sub type Actual is " << operationType << std::endl;
		std::cout << "8. Go To Manual structure mode " << std::endl;
		std::cout << "9. Change Structure: " << std::endl;
		std::cout << "0.EXIT " << std::endl;
		std::cout << "Your structure is: " << std::endl;
		switch (structureType)
		{
		case list: {std::cout << "List" << std::endl; break; }
		case array: {std::cout << "Array" << std::endl; break; }
		case heap: {std::cout << "Heap" << std::endl; break; }
		case redBlackTree: {std::cout << "Red Black Tree" << std::endl; break; }
		}
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}
		switch (choice) 
		{
		case 1: {measureADD(); break; }
		case 2: {measureDEL(); break; }
		case 3: {measureContains(); break; }
		case 4: {
			if (structureType == list || structureType == array) {
				measureFindIndex();
			}
			else {
				std::cout << "Your structure type must be array or list" << std::endl;
				system("pause");
				system("cls");
			}
			structureMenu();
				break; }
		case 5: {setMeasureTabSize(); structureMenu();break; }
		case 6: {setStructureSize(); structureMenu(); break; }
		case 7: {
			if (structureType == list || structureType == array) {
				setaddSubType();
			}
			else 
			{
				std::cout << "Your structure type must be array or list" << std::endl;
				system("pause");
				system("cls");
			}
			structureMenu();
			 break; }
		case 8: {structureExist = false;  manualMode(); structureMenu(); break; }
		case 9: {
			type newType = structureType;
			std::cout << "What type should be a new structure?" << std::endl;
			std::cout << "1.List" << std::endl;
			std::cout << "2.Heap" << std::endl;
			std::cout << "3.Array" << std::endl;
			std::cout << "4.Red-Black Tree" << std::endl;
			std::cout << "0.Return" << std::endl;
			int choice = 0;
#undef max
			while (!(std::cin >> choice)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			while (choice < 0 || choice >4)
			{
				std::cout << "Error give me 0-4" << std::endl;
				std::cin >> choice;
			}
			switch (choice)
			{
			case 1: {
				newType = list;
				structureType = newType;
				listPointer = new List();
				structure = listPointer;
				break; }
			case 2: {
				newType = heap;
				structureType = newType;
				heapPointer = new Heap();
				structure = heapPointer;
				break; }
			case 3: {
				newType = array;
				structureType = newType;
				arrayPointer = new Array();
				structure = arrayPointer;
				break; }
			case 4: {
				newType = redBlackTree;
				structureType = newType;
				treePointer = new RBTree();
				structure = treePointer;
				break; }
			case 0: {break; }
			default: {std::cout << "Error give me 0-4" << std::endl; }


					 break;
			}
			

			system("cls");
			structureMenu();
			break; 
		}//to do
		case 0: {break; }
		default: {
			system("cls");
			std::cout << "Give 0-9 to preced" << std::endl;
			structureMenu();
			 }
		}

	}
	else {
		std::cout << "We will create Structure now." << std::endl;
		setStructurePointer();
	}
	
	
	
	
}

void Manager::manualMode()
{
	structureSize = structure->size;
	if (structureExist == false) {
		switch (structureType)
		{
		case list: { listPointer = new List(); structure = listPointer;  break; }
		case heap: { heapPointer = new Heap(); structure = heapPointer;  break; }
		case array: { arrayPointer = new Array(); structure = arrayPointer;  break; }
		case redBlackTree: {treePointer = new RBTree(); structure = treePointer;  break; }
		}
		structureSize = 0;
		structureExist = true;
	}
	system("cls");
	std::cout << "Welcome to Manual Mode" << std::endl;
	std::cout << "Here you wil be able to manipulate the structure!" << std::endl;
	std::cout << "Your structure is: " << std::endl;
	switch (structureType)
	{
	case list: {std::cout << "List" << std::endl; break; }
	case array: {std::cout << "Array" << std::endl; break; }
	case heap:{std::cout << "Heap" << std::endl; break;}
	case redBlackTree:{ std::cout << "Red Black Tree" << std::endl; break; }
	}
	std::cout << "Actual Size is: " << structureSize << std::endl;
	std::cout << "Choose operation: " << operationType << std::endl;
	std::cout << "0. Exit to Main Menu " << std::endl;
	std::cout << "1. Print Structure " << std::endl;
	std::cout << "2. Set operacion type (index,beginning,end For List and Array)" << std::endl;
	std::cout << "3. Add int to structure"<< std::endl;
	std::cout << "4. delete int from structure" << std::endl;
	std::cout << "5. Check if int is in structure" << std::endl;
	std::cout << "6. Get vaule from index(Not for Red Black Tree)" << std::endl;
	std::cout << "7. Change Structure" << std::endl;
	std::cout << "8. Load Structure form txt file" << std::endl;
	int choice = 0;
	bool exit = false;
	while (exit == false)
	{
#undef max
		while (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
			std::cout << "Invalid input.  Try again: ";
		}
		switch (choice) {
		case 0: {
			exit = true; break; }
		case 1: {structure->printAll(); 
			system("Pause");
			system("cls");
			manualMode(); break;
			break; }
		case 2: {setaddSubType(); system("Pause");
			system("cls");
			manualMode(); break;  break; }
		case 3:
		{
			getNumber();
			if (structureType == heap || structureType == redBlackTree)
			{
				structure->addElement(givenInt); structureSize = structure->size;
			}else{
			switch (operationType)
				{
				
				
			case end: {structure->addElement(givenInt); structureSize = structure->size;  break; }
			case beginning: {structure->addElementOnBeginning(givenInt); structureSize = structure->size; break; }
			case indexType: {ManualModeAddIndexChoose(); break; }
				}
			}
			system("Pause");
			system("cls");
			manualMode(); break;
		}
		case 4:
		{
			if (structureSize <= 0)
			{
				std::cout << "Structure is empty" << std::endl;
				break;
			}
			if (structureType == heap || structureType == redBlackTree)
			{
				std::cout << "I will delete given int if it exist" << std::endl;
				getNumber();
				structure->deleteIndex(givenInt);
			}else
			{
			switch (operationType)
				{
				
				 
			case end: {structure->deleteLastElement(); structureSize = structure->size;  break; }
			case beginning: {structure->deleteFirst(); structureSize = structure->size; break; }
			case indexType: {ManualModeSubIndexChoose(); }
				}
			}
			system("Pause");
			system("cls");
			manualMode(); break;
			break; 
			structureSize = structure->size;
		}
		case 5:
		{
			getNumber();
			if (structure->contains(givenInt))
				std::cout << "FOUND IT! There is a: " << givenInt << "in structure" << std::endl;
			else
				std::cout << " There is no: " << givenInt << " in structure" << std::endl;
			system("Pause");
			system("cls");
			manualMode(); break;
			break;
		}
		case 6:
		{	if (structureSize <= 0)
			{
			std::cout << "Structure is empty" << std::endl;
			break;
			}
			if (structureType == redBlackTree)
			{
				std::cout << "Nodes are not indexed. Use this function for Heap, List or Array please" << std::endl;
				break;
			}
			else
			{
				getNumber();
				if (givenInt < structureSize && givenInt >= 0)
					std::cout << "Vaule in the index " << givenInt << "is " << structure->getVaule(givenInt) << std::endl;
				else
					std::cout << "Wrong Index! Should be: 0 to " << structureSize - 1 << std::endl;

				system("Pause");
				system("cls");
				manualMode(); break;
				break;
			}
		}
		case 7: {
			std::cout << "You will change structure now. I will rewrite a structure" << std::endl;
			type newType = structureType;
			std::cout << "What type should be a new structure?" << std::endl;
			std::cout << "1.List" << std::endl;
			std::cout << "2.Heap" << std::endl;
			std::cout << "3.Array" << std::endl;
			std::cout << "4.Red-Black Tree" << std::endl;
			std::cout << "0.Return" << std::endl;
			int choice = 0;
#undef max
			while (!(std::cin >> choice)) {
				std::cin.clear();
				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
				std::cout << "Invalid input.  Try again: ";
			}
			while (choice < 0 || choice >4)
			{
				std::cout << "Error give me 0-4" << std::endl;
				std::cin >> choice;
			}
			switch (choice)
			{
			case 1: {
				newType = list;
				break; }
			case 2: {
				newType = heap;
		
				break; }
			case 3: {
				newType = array;
				break; }
			case 4: {
				newType = redBlackTree;
				break; }
			case 0: {break; }
			default: {std::cout << "Error give me 0-4" << std::endl; }

		
					 break;
			}
			
			system("cls");
			rewriteStructure(newType);
			structureType = newType;
			system("Pause");
			system("cls");
			manualMode(); break;
			break; }
		case 8: {
			structure->clearAll();
			std::cout << "Give me the file name" << std::endl;
			std::string fileName;
			std::cin >> fileName;
			std::cout << fileName;
			std::fstream file;
			file.open(fileName);
			if (file.is_open())
			{

				std::cout << "The file has been loaded" << std::endl;
				std::string line;
				getline(file, line);
				//Geting 1st line as size
				int StructureFileSize;
				StructureFileSize = std::stoi(line);
				for (int i = 0; i < StructureFileSize; i++)
				{
					getline(file, line);
					structure->addElement(std::stoi(line));
				}
			}
			else
				std::cout << " ERROR. Coudn't load the file" << std::endl;
			system("Pause");
			system("cls");
			structureSize = structure->size;
			manualMode(); break;

			
			 }

		default: {
			system("cls");
			manualMode(); }
		 }
	}
	system("Pause");
	
}



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

void Manager::fillOnRandomIndex()
{
		structure->addElementOnIndex(givenInt, elementsArray[givenInt]);
}

void Manager::addOnBeginning()
{
	structure->addElementOnBeginning(givenInt);
}

void Manager::deleteRandom()
{
	structure->deleteIndex(givenInt);

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
				givenInt = rand() % structureSize;
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
				measurementTab[i] = timeCount(&Manager::fillWithRandom);
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
				givenInt = rand() % structureSize;
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
		givenInt = rand() % (structureSize);
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