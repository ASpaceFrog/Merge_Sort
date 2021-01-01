#include <iostream>
#include <cstdlib>
#include "Link.h"

Link::Link() {
	prev = nullptr;
	next = nullptr;
	contents = -1;
}

Link::~Link() {
}

//Get=======================================================
Link* Link::getprev() {
	return prev;
}

Link* Link::getnext() {
	return next;
}

V_TYPE Link::getcontents() {
	return contents;
}

//Set=======================================================
void Link::setprev(Link* newLink) {
	prev = newLink;
	return;
}

void Link::setnext(Link* newLink) {
	next = newLink;
	return;
}

void Link::setcontents(V_TYPE newContents) {
	contents = newContents;
	return;
}

//Functions======================================================
void Link::displayLink() {
	std::cout << contents;
	return;
}
