#include <iostream>
#include <cstdlib>
#include "Linked_List.h"

Linked_List::Linked_List() {
	first = nullptr;
	last = nullptr;
	size = 0;
}

Linked_List::~Linked_List() {
	while (first != nullptr) {
		delete popLink();
	}
}

//Get=========================================
Link* Linked_List::getfirst() {
	return first;
}

Link* Linked_List::getlast() {
	return last;
}

int Linked_List::getsize() {
	return size;
}

//Set==========================================
void Linked_List::setfirst(Link* newfirst) {
	newfirst->setnext(first);
	first->setprev(newfirst);
	first = newfirst;
	return;
}

void Linked_List::setlast(Link* newlast) {
	newlast->setnext(last);
	last->setprev(newlast);
	last = newlast;
	return;
}

void Linked_List::setsize(int newsize) {
	size = newsize;
	return;
}

//List Functions==============================================================================================
void Linked_List::addlink(int newplace, Link* newLink) {
	if (newLink == nullptr) {
		return;
	}
	Link* temp;
	if (size == 0) {
		first = newLink;
		last = newLink;
	}

	else if (newplace == size + 1) {
		if (size == 1) {
			newLink->setprev(first);
			first->setnext(newLink);
		}
		else {
			last->setnext(newLink);
			newLink->setprev(last);
		}
		last = newLink;
	}
	else if (newplace == 1) {
		if (size == 1) {
			newLink->setnext(last);
			last->setprev(newLink);
		}
		else {
			newLink->setnext(first);
			first->setprev(newLink);
		}
		first = newLink;
	}
	else if (newplace > 1 && newplace < size) {
		temp = findlinkfromnum(newplace);
		temp->setprev(newLink);
		newLink->setprev(temp->getprev());
		newLink->setnext(temp);
	}
	size++;
	return;
}

void Linked_List::append(V_TYPE newconts) {
	Link* temp = new Link;
	temp->setcontents(newconts);
	if (first == nullptr || size == 0 || last == nullptr) {
		first = temp;
		last = temp;
	}
	else if (size == 1) {
		last = temp;
		last->setprev(first);
		first->setnext(last);
	}
	else {
		temp->setprev(last);
		last->setnext(temp);
		last = temp;
	}
	size++;
	return;
}

Link* Linked_List::removelink(int currplace) {
	Link* temp;
	if (size == 0) {
		exit(0);
	}
	else if (size == 1) {
		temp = first;
		first = nullptr;
		size--;
		return temp;
	}
	else if (currplace == 1) {
		temp = first;
		first->getnext()->setprev(nullptr);
		first = first->getnext();
		size--;
		temp->setnext(nullptr);
		temp->setprev(nullptr);
		return temp;
	}
	if (currplace == 2) {
		temp = first->getnext();
		first->setnext(temp->getnext());
		temp->getnext()->setprev(first);
		temp->setnext(nullptr);
		temp->setprev(nullptr);
		return temp;
	}
	else {
		temp = first->getnext()->getnext();
		for (int i = 3; i <= currplace; i++) {
			temp = temp->getnext();
		}
		temp->getprev()->setnext(temp->getnext());
		temp->getnext()->setprev(temp->getprev());
		temp->setnext(nullptr);
		temp->setprev(nullptr);
		size--;
		return temp;
	}
}

Link* Linked_List::popLink() {
	Link* temp = new Link;
	if (first == nullptr) {
		return 0;
	}
	else {
		temp = first;
		first = first->getnext();
		temp->setnext(nullptr);
		if (first != nullptr) {
			first->setprev(nullptr);
		}
		size--;
		return temp;
	}
}

Link* Linked_List::findlinkfromnum(int place) {
	Link* temp;
	temp = first;
	for (int i = 2; i <= place; i++) {
		temp = temp->getnext();
	}
	return temp;
}

void Linked_List::displayList() {
	Link* temp = first;
	std::cout << "| ";
	for (int i = 1; i <= size; i++) {
		temp->displayLink();
		std::cout << " | ";
		temp = temp->getnext();
	}
	std::cout << std::endl;
	return;
}

//Generation=================================================================================================
void Linked_List::enterlist() {
	int newsize, num;
	bool exit = false;
	bool valid = false;
	std::cout << "Do you wish to 1) Manually Enter, 2) Generate from a size of a power of 2, or 3) Generate from a entered size?" << std::endl;
	while (!exit) {
		switch (getch()) {
		case '1':
			system("CLS");
			newsize = makesize();
			for (int i = 1; i <= newsize; i++) {
				std::cout << "Enter a number" << std::endl;
				valid = false;
				while (!valid) {
					std::cin.clear();
					std::cin >> num;
					if (std::cin.fail()) {
						std::cin.clear();
						std::cin.ignore();
						valid = false;
					}
					else {
						valid = true;
					}
				}
				append(num);
				std::cout << "Added to list" << std::endl;
			}
			exit = true;
			break;
		case '2':
			system("CLS");
			std::cout << "Enter the power you want to raise 2 to" << std::endl;
			while (!valid || newsize < 1) {
				std::cin >> newsize;
				if (std::cin.fail()) {
					std::cin.clear();
					std::cin.ignore(10000);
				}
				else if (newsize < 1) {
					std::cout << "Power cannot be <1" << std::endl;
				}
				else {
					valid = true;
				}
			}
			newsize = pow(2, newsize);
			generateList(newsize);
			exit = true;
			break;
		case '3':
			system("CLS");
			newsize = makesize();
			generateList(newsize);
			exit = true;
			break;
		default:
			std::cout << "Enter a 1, 2, or 3" << std::endl;
			break;
		}
	}
	return;
}

int Linked_List::makesize() {
	int newsize;
	bool exit = false;
	std::cout << "Enter the amount of numbers you want to sort" << std::endl;
	while (!exit) {
		std::cin >> newsize;
		if (std::cin.fail()) {
			std::cin.clear();
			std::cin.ignore();
			std::cout << "Enter a valid number" << std::endl;
			exit = false;
		}
		else if (newsize < 2) {
			std::cout << "Amount of numbers cannot be <2" << std::endl;
		}
		else {
			exit = true;
		}
	}
	system("CLS");
	return newsize;
}

void Linked_List::generateList(int newsize) {
	srand(time(NULL));
	for (int i = 1; i <= newsize; i++) {
		\
			append(rand() % 1000 + 1);
	}
	return;
}

//Sorting=================================================================================================================
Linked_List* Linked_List::sortlists(Linked_List* myList, Linked_List* L, Linked_List* R) {
	int temp = L->getsize() + R->getsize();
	for (int i = 1; i <= temp; i++) {
		if (R->getsize() == 0) {
			myList->append(L->popLink()->getcontents());
		}
		else if (L->getsize() == 0) {
			myList->append(R->popLink()->getcontents());
		}
		else {
			if (L->getfirst()->getcontents() > R->getfirst()->getcontents()) {
				myList->append(R->popLink()->getcontents());
			}
			else {
				myList->append(L->popLink()->getcontents());
			}
		}
	}
	delete L;
	delete R;
	return myList;
}

Linked_List* Linked_List::divide(Linked_List* myList) {
	Linked_List* L = new Linked_List;
	Linked_List* R = new Linked_List;
	int newsize = myList->getsize();
	if (newsize > 1) {
		for (int i = 1; i <= newsize / 2; i++) {
			L->append(myList->popLink()->getcontents());
		}
		for (int i = 1; i <= newsize - (newsize / 2); i++) {
			R->append(myList->popLink()->getcontents());
		}
		L = divide(L);
		R = divide(R);
		myList = sortlists(myList, L, R);
	}
	return myList;
}
