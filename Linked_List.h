#ifndef LINKED_LIST_H
#define LINKED_LIST_H
#include <string>
#include <ctime>
#include <cmath>
#include <ctime>
#include <conio.h>
#include "Link.h"

class Linked_List {
public:
	Linked_List();
	virtual ~Linked_List();

	//Get====================================
	Link* getfirst();
	Link* getlast();
	int getsize();

	//Set====================================
	void setfirst(Link*);
	void setlast(Link*);
	void setsize(int);

	//Functions==============================
	void addlink(int, Link*);
	void append(V_TYPE);
	Link* removelink(int);
	Link* popLink();
	Link* findlinkfromnum(int);
	void displayList();
	void enterlist();
	void generateList(int);
	int makesize();

	//Merge Sort Funcitons===================
	Linked_List* divide(Linked_List*);
	Linked_List* sortlists(Linked_List*, Linked_List*, Linked_List*);

private:
	Link* first = new Link;
	Link* last = new Link;
	int size;
};

#endif // LINKED_LIST_H
