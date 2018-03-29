#include <iostream>
#include "List.h"
int main() {
	List testList;
	
	testList.addElement(1);
	testList.addElement(2);
	testList.addElement(3);
	testList.addElement(4);
	testList.addElement(5);
	testList.addElementOnIndex(9, 3);
	testList.addElementOnBeginning(400);
	std::cout << testList.getVaule(3) << std::endl;
	testList.deleteIndex(3);
	testList.contains(1);
	testList.showAll();


	system("PAUSE");
}