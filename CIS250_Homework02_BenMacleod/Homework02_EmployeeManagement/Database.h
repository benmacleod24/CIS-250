#pragma once

#include "Employee.h"
#include "Department.h"
#include "Config.h"
#include <string>

using namespace std;

class Database
{
	private:
		Employee* employees;
		Department* departments;
		bool isReady;
		Config* cfg;
		int numOfDepts;

	public:
		Database();
		Database(Config*);

		/* Methods */
		void initalize();
		void seed();
		void insertDepartment(Department, int);
		bool doesDepartmentExist(Department);

		/* Getters */
		int getNumberOfEmployees() const;
		bool getDatabaseState() const;
		Employee* getEmployees() const;
		Department* getDepartments() const;
		int getNumberOfDepartments() const;

		/* Setters */
	
};

