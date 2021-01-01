#include <iostream>
#include <cstdlib>
#include "Linked_List.h"

int main() {
	Linked_List* myList = new Linked_List;
	myList->enterlist();
	system("CLS");
	std::cout << "Here is the current list" << std::endl;
	myList->displayList();
	myList = myList->divide(myList);
	std::cout << std::endl << "Here is the sorted list" << std::endl;
	myList->displayList();
	return 0;
}
