// Title: Census Sort
// Name: Ben Macleod
// Date: 04.05.23
//

#include <iostream>
#include "Reader.h"
#include "Person.h"
#include "Sorter.h"
#include "Menu.h"

using namespace std;

int main()
{
	// Alloc a person ptr.
	Person* people;

	// Initalize a reader, to get data.
	Reader reader;

	// Read file and set to returned value.
	people = reader.readFile();

	// Initalize the menu & prompts.
	Menu menu(people, reader.sizeOfFile());
}
