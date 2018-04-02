#include <iostream>
#include "List.h"
#include "Structure.h"
#include "Array.h"
#include "Heap.h"
int main() {
	List lista;
	Array aray;
	Heap heap;
	Structure *pointer;
	pointer = &lista;
	pointer = &aray;
	pointer = &heap;

	for (int i = 0; i < 20; i++) {
		pointer->addElement(i);
	}
	pointer->deleteFirst();
	pointer->addElementOnIndex(3, 4);
	pointer->printAll();

	system("PAUSE");
}


