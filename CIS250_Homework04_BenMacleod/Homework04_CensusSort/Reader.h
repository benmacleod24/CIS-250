#pragma once
#include "Person.h"

class Reader
{
private:
	string fileName = "Census.txt";
public:
	Person* readFile();
	int sizeOfFile();
};

