// DoublyList.h - Ben Macleod
// Last Modified: 3/22/23
//

#include "Node.h"

#pragma once
class DoublyList
{

private:
	Node* headPtr;
	Node* tailPtr;

public:
	DoublyList();

	/* Methods */
	void appendNode(Pet*);
	void insertNode(Pet*);
	void deleteNode(int);

	/* Display Methods */
	void displayPetDetails(Pet*) const;
	void displayForwards() const;
	void displayBackwards() const;
};

