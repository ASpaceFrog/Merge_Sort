#ifndef LINK_H
#define LINK_H
#include<string>
#define V_TYPE int

class Link {
public:
	Link();
	virtual ~Link();

	//Get==========================
	Link* getprev();
	Link* getnext();
	V_TYPE getcontents();

	//Set==========================
	void setprev(Link*);
	void setnext(Link*);
	void setcontents(V_TYPE);

	//Funcitons====================
	void displayLink();

private:
	Link* prev;
	Link* next;
	V_TYPE contents;
};

#endif // LINK_H
