#include "Reader.h"
#include <fstream>
#include <iostream>


int Reader::sizeOfFile()
{
	string lineOfText;

	// Create & Open file instance.
	fstream file;
	file.open(fileName);

	if (file)
	{
		int count = 0;

		while (getline(file, lineOfText))
		{
			count++;
		}

		return count;
	}

	return 0;
}

Person* Reader::readFile()
{
	string lineOfText;

	// Create array with correct size alloc.
	int sizeOfArray = sizeOfFile();
	Person* arrayOfPeople = new Person[sizeOfArray];

	// Create & Open file instance.
	fstream file;
	file.open(fileName);

	if (file)
	{
		int nextIndex = 0;

		while (getline(file, lineOfText))
		{
			// Parse line of text into a person.
			Person _tempPerson = Person::parseString(lineOfText);

			// Index into array of people.
			arrayOfPeople[nextIndex] = _tempPerson;

			// Increement next index.
			nextIndex++;
		}
	}

	return arrayOfPeople;
}