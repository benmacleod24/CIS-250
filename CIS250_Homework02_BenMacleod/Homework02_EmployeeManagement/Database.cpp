#include "Database.h"
#include "Department.h"
#include "Employee.h"
#include "Config.h"
#include <fstream>
#include <string>
#include <iostream>


using namespace std;

Database::Database()
{
	employees = nullptr;
	departments = nullptr;
	isReady = false;
	numOfDepts = 0;

	// Initalize the database.
	initalize();
}

Database::Database(Config* c)
{
	employees = nullptr;
	departments = nullptr;
	isReady = false;
	cfg = c;
	numOfDepts = 0;

	// Initalize the database.
	initalize();
}

/* Methods */

/*
	We initalize the database by setting array sizes and seeding it.
*/
void Database::initalize()
{
	// todo: Read the number of employees and size array size.
	employees = new Employee[getNumberOfEmployees()];
	departments = new Department[numOfDepts];

	// Seed the database
	seed();

	// If the arrays where made correctly, set the database to ready.
	if (employees != nullptr && departments != nullptr)
	{
		isReady = true;
	}
}

/*
	Seed the database with the data from the text file.
	todo: Parse the department into it's own object and insert into unique array.
*/
void Database::seed()
{
	fstream file;

	file.open(cfg -> getDatabaseFileName());

	// When the file exist, count number of rows.
	if (file)
	{
		string row;

		// Array index counter.
		int rowNum = 0;

		// Loop through each row and increment number of rows.
		while (!file.eof())
		{
			getline(file, row);

			// Insert employee into the employee array.
			Employee e = Employee::parse(row);
			Department d = Department::parse(row);

			// Because phone number is placed at the end of
			// the data string we need to save the value
			// once everything has been parsed.
			e.setPhoneNumber(row);

			// Set employee department
			e.setDept(d);

			// Insert new employee to the array
			employees[rowNum] = e;

			// Insert a department.
			insertDepartment(d, numOfDepts);


			// Increment row number.
			rowNum++;
		}

		// Close file so it's not left open.
		file.close();
	}
	else
	// File doesn't exist and display file we are looking for.
	{
		system("cls");
		cout << "Error: Could not find database file." << endl;
		cout << "Looking for file: " << cfg -> getDatabaseFileName() << endl;
	}

}

bool Database::doesDepartmentExist(Department dept)
{
	for (int i = 0; i < numOfDepts; i++)
	{
		if (departments[i].getId() == dept.getId()) return true;
	}

	return false;
}

void Database::insertDepartment(Department dept, int size)
{
	if (doesDepartmentExist(dept)) return;

	Department* temp = new Department[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = departments[i];
	}

	temp[size] = dept;
	numOfDepts = numOfDepts + 1;

	delete[] departments;
	departments = temp;

}

/* Getters */
bool Database::getDatabaseState() const
{
	return isReady;
}

int Database::getNumberOfEmployees() const
{
	fstream file;
	int numOfRows = 0;

	file.open(cfg -> getDatabaseFileName());

	// When the file exist, count number of rows.
	if (file)
	{
		string row;

		// Loop through each row and increment number of rows.
		while (!file.eof())
		{
			getline(file, row);
			numOfRows++;
		}

		// Close file so it's not left open.
		file.close();
	}
	else
	// File doesn't exist and display file we are looking for.
	{
		system("cls");
		cout << "Error: Could not find database file." << endl;
		cout << "Looking for file: " << cfg -> getDatabaseFileName() << endl;
	}

	return numOfRows;
} 

Employee* Database::getEmployees() const
{
	return employees;
}

Department* Database::getDepartments() const
{
	return departments;
}

int Database::getNumberOfDepartments() const
{
	return numOfDepts;
}