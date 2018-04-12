#include "Manager.h"

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
	while (!(std::cin >> choice)) {
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
		case 3: {
			for (int i = 0; i < numberMeasurments; i++)
			{
				createArrayOfElements();
				fillWithRandom();
				delete[] elementsArray;
				givenInt = (rand() % structureSize + ((int)structureSize / 10));
				measurementTab[i] = timeCount(&Manager::containsRandom);
				structure->clearAll();

			}
			countMeasure();
			break; }
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
		case 5: {setMeasureTabSize(); structureMenu(); break; }
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
		}

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
	system("cls");
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
	std::cout << "Welcome to Manual Mode" << std::endl;
	std::cout << "Here you wil be able to manipulate the structure!" << std::endl;
	std::cout << "Your structure is: " << std::endl;
	switch (structureType)
	{
	case list: {std::cout << "List" << std::endl; break; }
	case array: {std::cout << "Array" << std::endl; break; }
	case heap: {std::cout << "Heap" << std::endl; break; }
	case redBlackTree: { std::cout << "Red Black Tree" << std::endl; break; }
	}
	std::cout << "Actual Size is: " << structureSize << std::endl;
	if (structureType == heap || structureType == redBlackTree)
		treesMenu();
	else
		manualMenu();
//
//		
//		int choice = 0;
//		bool exit = false;
//		while (exit == false)
//		{
//#undef max
//			while (!(std::cin >> choice)) {
//				std::cin.clear();
//				std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//				std::cout << "Invalid input.  Try again: ";
//			}
//			switch (choice) {
//			case 0: {
//				exit = true; break; }
//			case 1: {structure->printAll();
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//				break; }
//			case 2: {setaddSubType(); system("Pause");
//				system("cls");
//				manualMode(); break;  break; }
//			case 3:
//			{
//				getNumber();
//				if (structureType == heap || structureType == redBlackTree)
//				{
//					structure->addElement(givenInt); structureSize = structure->size;
//				}
//				else {
//					switch (operationType)
//					{
//
//
//					case end: {structure->addElement(givenInt); structureSize = structure->size;  break; }
//					case beginning: {structure->addElementOnBeginning(givenInt); structureSize = structure->size; break; }
//					case indexType: {ManualModeAddIndexChoose(); break; }
//					}
//				}
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//			}
//			case 4:
//			{
//				if (structureSize <= 0)
//				{
//					std::cout << "Structure is empty" << std::endl;
//					break;
//				}
//				if (structureType == heap || structureType == redBlackTree)
//				{
//					std::cout << "I will delete given int if it exist" << std::endl;
//					getNumber();
//					structure->deleteIndex(givenInt);
//				}
//				else
//				{
//					switch (operationType)
//					{
//
//
//					case end: {structure->deleteLastElement(); structureSize = structure->size;  break; }
//					case beginning: {structure->deleteFirst(); structureSize = structure->size; break; }
//					case indexType: {ManualModeSubIndexChoose(); }
//					}
//				}
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//				break;
//				structureSize = structure->size;
//			}
//			case 5:
//			{
//				getNumber();
//				if (structure->contains(givenInt))
//					std::cout << "FOUND IT! There is a: " << givenInt << "in structure" << std::endl;
//				else
//					std::cout << " There is no: " << givenInt << " in structure" << std::endl;
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//				break;
//			}
//			case 6:
//			{	if (structureSize <= 0)
//			{
//				std::cout << "Structure is empty" << std::endl;
//				break;
//			}
//			if (structureType == redBlackTree)
//			{
//				std::cout << "Nodes are not indexed. Use this function for Heap, List or Array please" << std::endl;
//				break;
//			}
//			else
//			{
//				getNumber();
//				if (givenInt < structureSize && givenInt >= 0)
//					std::cout << "Vaule in the index " << givenInt << "is " << structure->getVaule(givenInt) << std::endl;
//				else
//					std::cout << "Wrong Index! Should be: 0 to " << structureSize - 1 << std::endl;
//
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//				break;
//			}
//			}
//			case 7: {
//				std::cout << "You will change structure now. I will rewrite a structure" << std::endl;
//				type newType = structureType;
//				std::cout << "What type should be a new structure?" << std::endl;
//				std::cout << "1.List" << std::endl;
//				std::cout << "2.Heap" << std::endl;
//				std::cout << "3.Array" << std::endl;
//				std::cout << "4.Red-Black Tree" << std::endl;
//				std::cout << "0.Return" << std::endl;
//				int choice = 0;
//#undef max
//				while (!(std::cin >> choice)) {
//					std::cin.clear();
//					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
//					std::cout << "Invalid input.  Try again: ";
//				}
//				while (choice < 0 || choice >4)
//				{
//					std::cout << "Error give me 0-4" << std::endl;
//					std::cin >> choice;
//				}
//				switch (choice)
//				{
//				case 1: {
//					newType = list;
//					break; }
//				case 2: {
//					newType = heap;
//
//					break; }
//				case 3: {
//					newType = array;
//					break; }
//				case 4: {
//					newType = redBlackTree;
//					break; }
//				case 0: {break; }
//				default: {std::cout << "Error give me 0-4" << std::endl; }
//
//
//						 break;
//				}
//
//				system("cls");
//				rewriteStructure(newType);
//				structureType = newType;
//				system("Pause");
//				system("cls");
//				manualMode(); break;
//				break; }
//			case 8: {
//				structure->clearAll();
//				std::cout << "Give me the file name" << std::endl;
//				std::string fileName;
//				std::cin >> fileName;
//				std::cout << fileName;
//				std::fstream file;
//				file.open(fileName);
//				if (file.is_open())
//				{
//
//					std::cout << "The file has been loaded" << std::endl;
//					std::string line;
//					getline(file, line);
//					//Geting 1st line as size
//					int StructureFileSize;
//					StructureFileSize = std::stoi(line);
//					for (int i = 0; i < StructureFileSize; i++)
//					{
//						getline(file, line);
//						structure->addElement(std::stoi(line));
//					}
//				}
//				else
//					std::cout << " ERROR. Coudn't load the file" << std::endl;
//				system("Pause");
//				system("cls");
//				structureSize = structure->size;
//				manualMode(); break;
//
//
//			}
//			case 9: {
//				std::cout << "Give structure size" << std::endl;
//				std::cin >> structureSize;
//				createArrayOfElements();
//				fillWithRandom();
//				system("Pause");
//				system("cls");
//				manualMode();
//				break;
//			}
//
//			default: {
//				system("cls");
//				manualMode(); }
//			}
//		}
//		system("Pause");
}


void Manager::treesMenu() {
	std::cout << "1. Print Structure " << std::endl;
	std::cout << "2. Add element" << std::endl;
	std::cout << "3. delete element from structure" << std::endl;
	std::cout << "4. delete all same elements (int) from structure" << std::endl;
	std::cout << "5. Check if int is in structure" << std::endl;
	std::cout << "6. Change Structure" << std::endl;
	std::cout << "7. Load Structure form txt file" << std::endl;
	std::cout << "8. Fill With random" << std::endl;
	std::cout << "9. Clear All" << std::endl;
	std::cout << "0. Exit to Main Menu " << std::endl;
	int choice = 0;
	bool exit = false;
	while (exit == false)
	{
		int choice = makeChoice();
		if (choice >= 0 && choice <= 9) {}
		else {
			system("cls");
			manualMode();
		}
		switch (choice) {
		case 0: {exit = true; break; }
		case 1: {structure->printAll();
			system("Pause");
			manualMode();
			break; }
		case 2: {getNumber(); structure->addElement(givenInt); structureSize = structure->size; manualMode(); break; }
		case 3: {
			if (structureSize <= 0)
			{
			std::cout << "Structure is empty" << std::endl;
			break;
			}
			else
			{
				std::cout << "I will delete given int if it exist" << std::endl;
				getNumber();
				structure->deleteIndex(givenInt);
			}
			manualMode();
			break; }
		case 4: {
			if (structureSize <= 0)
			{
				std::cout << "Structure is empty" << std::endl;
				break;
			}
			else {
				std::cout << "I will delete given int if it exist" << std::endl;
				getNumber();
				while (structure->contains(givenInt)) 
				{
					structure->deleteIndex(givenInt);
				}
			
			}
			
			manualMode(); break; }
		case 5: {manualModeCheckIfIntExist(); manualMode(); break; }
		case 6: {manualModeStructureChange(); manualMode(); break; }
		case 7: {manualModeStructureFromFile(); manualMode(); break; }
		case 8: {manualModeFillStructure(); manualMode(); break; }
		case 9: {structure->clearAll(); manualMode(); break; }
		}
	}
}

void Manager::manualMenu() {
	std::cout << "1. Print Structure " << std::endl;
	std::cout << "2. Add element on end" << std::endl;
	std::cout << "3. Add element on beginning" << std::endl;
	std::cout << "4. Add element on on index" << std::endl;
	std::cout << "5. delete element from structure" << std::endl;
	std::cout << "6. delete all same elements (int) from structure" << std::endl;
	std::cout << "7. delete index element from structure" << std::endl;
	std::cout << "8. Check if int is in structure" << std::endl;
	std::cout << "9. Get vaule from index" << std::endl;
	std::cout << "10. Change Structure" << std::endl;
	std::cout << "11. Load Structure form txt file" << std::endl;
	std::cout << "12. Fill With random" << std::endl;
	std::cout << "0. Exit to Main Menu " << std::endl;
	int choice = 0;
	bool exit = false;
	while (exit == false)
	{
		int choice = makeChoice();
		if (choice >= 0 && choice <= 12) {}
		else {
			system("cls");
			manualMenu();
		}
		switch (choice) {
		case 0: {exit = true; break; }
		case 1: {structure->printAll();
			system("Pause");
			system("cls");
			manualMode();
			break; }
		case 2: {getNumber(); structure->addElement(givenInt);  manualMode(); break; }
		case 3: {getNumber(); structure->addElementOnBeginning(givenInt); manualMode(); break; }
		case 4: {getNumber(); getIndex(); structure->addElementOnIndex(givenInt, index); manualMode(); break; }
		case 5: {getNumber(); structure->deleteInt(givenInt); manualMode(); break;
			
			break; }
		case 6: {break; }
		case 7: {
			if (structureSize <= 0)
			{
				std::cout << "Structure is empty" << std::endl;
				break;
			}
			else
			{
				std::cout << "I will delete given int if it exist" << std::endl;
				getNumber();
				structure->deleteIndex(givenInt);
			}
			manualMode();
			break;
		}
		case 8: {break; }
		case 9: {break; }
		case 10: {break; }
		case 11: {break; }
		case 12: {break; }

		}
	}
}

int Manager::makeChoice() {
	int choice;
	#undef max
				while (!(std::cin >> choice)) {
					std::cin.clear();
					std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
					std::cout << "Invalid input.  Try again: ";
				}
				return choice;

}
void Manager::manualModeCheckIfIntExist() {
	getNumber();
	if (structure->contains(givenInt))
	std::cout << "FOUND IT! There is a: " << givenInt << "in structure" << std::endl;
	else
    std::cout << " There is no: " << givenInt << " in structure" << std::endl;
					system("Pause");

	
}

void Manager::manualModeStructureChange() {
	system("cls");
	std::cout << "You will change structure now. I will rewrite a structure" << std::endl;
	type newType = structureType;
	std::cout << "What type should be a new structure?" << std::endl;
	std::cout << "1.List" << std::endl;
	std::cout << "2.Heap" << std::endl;
	std::cout << "3.Array" << std::endl;
	std::cout << "4.Red-Black Tree" << std::endl;
    std::cout << "0.Return" << std::endl;
	int choice = makeChoice();
	if (choice > 0 && choice <= 4)
	{
	
		switch (choice)
		{
		case 1: {newType = list; break; }
		case 2: {newType = heap; break; }
		case 3: {newType = array; break; }
		case 4: {newType = redBlackTree; break; }
		case 0: {break; }
		}
		rewriteStructure(newType);
		structureType = newType;
	}
	else
	{
		system("cls");
		std::cout << "ERROR Give me 0 - 4" << std::endl;
		manualModeStructureChange();
	}
}

void Manager::manualModeStructureFromFile(){

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
		structure->clearAll();
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


}

void Manager::manualModeFillStructure() {
	std::cout << "Give structure size" << std::endl;
	int newStructureSize = makeChoice();
	if (newStructureSize > 0) {
		structure->clearAll();
		structureSize = newStructureSize;
		createArrayOfElements();
		fillWithRandom();
	}
	else
		std::cout << "You can't have - size structure" << std::endl;
	system("Pause");
	
}