#include <iostream>
#include "Array.h"
int main() {
	Array *testArray=new Array();
	Array *sizeTestArray=new Array(5);
	//testArray->addInt(21);
//	testArray->addInt(37);
//	testArray->printAll();
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->addInt(21);
	sizeTestArray->printAll();
	system("PAUSE");
}