#include "Person.h"
#include <iostream>
#include <vector>

Person Person::parseString(string input)
{
	Person _person;
	vector<string> values;

	int N = 0;
	int startOfValue = 0;
	while (N < input.length())
	{

		// Character we are testing is a whitespace.
		if (input[N] == ' ')
		{

			// The Character in position N - 1 is not a whitespace
			// we can assume is the end of a value.
			if (input[N - 1] != ' ')
			{
				int endOfValue = N - startOfValue;
				const string value = input.substr(startOfValue, endOfValue);

				// Push value into vector.
				values.push_back(value);

				// Reset the startOfValue to N.
				startOfValue = N;
			}

			// The Character in position N + 1 is not a whitespace
			// we can assume is the start of a value.
			if (input[N + 1] != ' ')
			{
				startOfValue = N + 1;
			}
		}

		N++;
	}

	// Add final value into the vector, because of 
	const int endOfValue = input.length() - startOfValue;
	values.push_back(input.substr(startOfValue, endOfValue));

	// Construct person class, because we inserted the values
	// based on how we read the string, we can read each value easily.
	//

	// Name
	_person.setName(values[0]);

	// Hourly Wage
	_person.setHourlyWage(stod(values[2]));

	// ID
	_person.setID(stoi(values[3]));

	// Department ID
	_person.setDepartmentID(stoi(values[4]));

	return _person;
};

// Getters 
int Person::getID() const
{
	return id;
};

string Person::getName() const
{
	return name;
};

double Person::getHourlyWage() const
{
	return hourlyWage;
};

int Person::getDepartmentID() const
{
	return departmentId;
};

// Setters
void Person::setID(int v)
{
	id = v;
};

void Person::setName(string v)
{
	name = v;
};

void Person::setHourlyWage(double v)
{
	hourlyWage = v;
};

void Person::setDepartmentID(int v)
{
	departmentId = v;
};