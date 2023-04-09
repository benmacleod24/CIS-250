// DoublyList.cpp - Ben Macleod
// Last Modified: 3/22/23
//

#include "DoublyList.h"
#include <iostream>

DoublyList::DoublyList()
{
	headPtr = nullptr;
	tailPtr = nullptr;
};

/* Insert at end */
void DoublyList::appendNode(Pet* nodeData)
{
	Node* newNode = new Node(nodeData);

	if (headPtr == nullptr)
	{
		headPtr = newNode;
		tailPtr = newNode;
	}
	else
	{
		// Setting new nodes previous.
		newNode->setPrevPtr(tailPtr);

		// Setting curret tails next.
		tailPtr->setNextPtr(newNode);
		
		// Setting the tail.
		tailPtr = newNode;
	}
};

void DoublyList::insertNode(Pet* nodeData)
{
	Node* newNode = new Node(nodeData);
	Node* searchNode = headPtr;

	// Null header we need to append the node.
	if (headPtr == nullptr)
	{
		appendNode(nodeData);
		return;
	}

	// If the new pet id belongs in the front of the list.
	if (headPtr->getData()->getId() >= newNode->getData()->getId())
	{
		// Set the current heads previous value to new node.
		headPtr->setPrevPtr(newNode);

		// Set new nodes next value to current head.
		newNode->setNextPtr(headPtr);

		// Set new head value.
		headPtr = newNode;

		return;
	}

	// If the new pet id belongs at the end of the list.
	if (tailPtr->getData()->getId() <= newNode->getData()->getId())
	{

		// Set current tails next value to new node.
		tailPtr->setNextPtr(newNode);

		// Set new nodes previous value to current tail.
		newNode->setPrevPtr(tailPtr);

		// Set new tail ptr.
		tailPtr = newNode;

		return;
	}

	while (searchNode != nullptr)
	{

		if (newNode->getData()->getId() <= searchNode->getData()->getId())
		{
			searchNode->getPrevPtr()->setNextPtr(newNode);

			
			if (searchNode->getPrevPtr() != nullptr)
			{
				newNode->setPrevPtr(searchNode->getPrevPtr());
			}

			if (searchNode != nullptr)
			{
				newNode->setNextPtr(searchNode);
			}

			searchNode->setPrevPtr(newNode);

			break;

		}
		searchNode = searchNode->getNextPtr();

	}
}

void DoublyList::deleteNode(int idToDelete)
{
	Node* searchNode = headPtr;

	// If no head, then return.
	if (headPtr == nullptr)
	{
		return;
	}

	// If the head is the node to delete
	if (headPtr->getData()->getId() == idToDelete)
	{
		// Set new head value.
		headPtr = headPtr->getNextPtr();

		// Delete old head ptr.
		delete headPtr->getPrevPtr();

		// Set new head prev ptr to null.
		headPtr->setPrevPtr(nullptr);

		return;
	}

	// If the tail is the node to delete.
	if (tailPtr->getData()->getId() == idToDelete)
	{
		// Set new tail value.
		tailPtr = tailPtr->getPrevPtr();

		// Delete old tail.
		delete tailPtr->getNextPtr();

		// Set new tail next to null.
		tailPtr->setNextPtr(nullptr);

		return;
	}

	// Loop through the node list.
	while (searchNode != nullptr)
	{
		// Until we find a matching id.
		if (searchNode->getData()->getId() == idToDelete)
		{
			// Set the search node's previous node's next value.
			searchNode->getPrevPtr()->setNextPtr(searchNode->getNextPtr());

			// Set the search node's next node's previous value.
			searchNode->getNextPtr()->setPrevPtr(searchNode->getPrevPtr());

			// Delete the current search node.
			delete searchNode;

			// Break out of the loop.
			break;
		}

		searchNode = searchNode->getNextPtr();
	}
};

/* Display Methods */

void DoublyList::displayPetDetails(Pet* pet) const
{
	cout << "ID: " << pet->getId() << endl;
	cout << "Name: " << pet->getName() << endl;
	cout << "Type: " << pet->getType() << endl;
	cout << "Age: " << pet->getAge() << endl;
	cout << endl;
}

void DoublyList::displayForwards() const
{
	Node* searchNode = headPtr;

	cout << "Forward Display" << endl;
	cout << "===============" << endl;

	while (searchNode != nullptr)
	{
		displayPetDetails(searchNode->getData());
		searchNode = searchNode->getNextPtr();
	}

}

void DoublyList::displayBackwards() const
{
	Node* searchNode = tailPtr;

	cout << "Backward Display" << endl;
	cout << "================" << endl;

	while (searchNode != nullptr)
	{
		displayPetDetails(searchNode->getData());
		searchNode = searchNode->getPrevPtr();
	}

}