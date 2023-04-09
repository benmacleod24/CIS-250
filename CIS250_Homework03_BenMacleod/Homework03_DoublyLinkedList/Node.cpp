// Node.cpp - Ben Macleod
// Last Modified: 3/21/23
//

#include "Node.h"

Node::Node()
{};

Node::Node(Pet* d)
{
	data = d;
};

Node::Node(Pet* d, Node* n, Node* p)
{
	data = d;
	nextPtr = n;
	prevPtr = p;
};

/* Getters */
Pet* Node::getData() const
{
	return data;
};

Node* Node::getNextPtr() const
{
	return nextPtr;
};

Node* Node::getPrevPtr() const
{
	return prevPtr;
};

/* Setters */
void Node::setData(Pet* v)
{
	data = v;
};

void Node::setNextPtr(Node* v)
{
	nextPtr = v;
};

void Node::setPrevPtr(Node* v)
{
	prevPtr = v;
};