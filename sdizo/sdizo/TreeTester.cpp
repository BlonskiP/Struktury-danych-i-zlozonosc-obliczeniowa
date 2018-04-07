#include "Structure.h"
#include "RBTree.h"
#include <iostream>
#include "List.h"

int main() {

	Structure *x;
	x = new RBTree();
	x->addElement(3);

	system("pause");
	return 0;
}