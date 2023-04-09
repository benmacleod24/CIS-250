// Node.h - Ben Macleod
// Last Modified: 3/21/23
//

#pragma once
#include "Pet.h"

class Node
{
private:
	Pet* data;
	Node* nextPtr;
	Node* prevPtr;

public:
	Node();
	Node(Pet*);
	Node(Pet*, Node*, Node*);

	/* Getters */
	Pet* getData() const;
	Node* getNextPtr() const;
	Node* getPrevPtr() const;

	/* Setters */
	void setData(Pet*);
	void setNextPtr(Node*);
	void setPrevPtr(Node*);
};

