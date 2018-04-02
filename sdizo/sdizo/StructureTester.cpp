#include <iostream>
#include "List.h"
#include "Structure.h"
int main() {
	List lista;
	Structure *pointer;
	pointer = &lista;
	for (int i = 0; i < 20; i++) {
		pointer->addElement(i);
	}
	pointer->deleteFirst();
	pointer->addElementOnIndex(3, 4);
	pointer->printAll();

	system("PAUSE");
}


