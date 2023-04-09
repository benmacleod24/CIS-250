#pragma once
#include "Person.h"

class Menu
{
private:
	int selection;
	int sizeOfArray;
	Person* people;
public:
	Menu(Person*, int);
	void greet();
	void handleSelection();
	void displayBubbleSort();
	void displayInsertSort();
};

