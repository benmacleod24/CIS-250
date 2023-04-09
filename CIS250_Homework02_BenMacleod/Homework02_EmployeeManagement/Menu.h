#include "Employee.h"
#include "Department.h"
#include "Database.h"
#pragma once

class Menu
{
private:
	int menuSelection;
	Database* database;
public:
	Menu();
	Menu(Database*);
	int promptMenu();
	int promptSelection(bool);
	
	// Display Methods
	void displayAllEmployees(Employee*, Department*);
	void displayOldestEmployee(Employee*);
	void displayOptionHeader(string);
	void getEmloyeeBySSN(Employee*);
	void displayAvgAgeByState(Employee*, string);
	void displayCompSciBlding(Department*);
	void displayBldingDepts(Department*, string);
};

