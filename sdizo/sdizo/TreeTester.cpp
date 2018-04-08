#include "Structure.h"
#include "RBTree.h"
#include <iostream>
#include "List.h"

int main() {

	Structure *x;
	x = new RBTree();
	for (int i = 0; i < 20; i++)
	{
		x->addElement(std::rand()%100);
	}
	
	x->printAll();
	system("pause");
	return 0;
}