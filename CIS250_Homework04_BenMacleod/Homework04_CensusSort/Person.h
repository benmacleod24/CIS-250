#pragma once
#include <string>

using namespace std;

// 1st Column: Name
// 3rd column: hourly wage
// 4th column: ID
// Last column: Department ID
//

class Person
{
private:
	int id;
	string name;
	double hourlyWage;
	int departmentId;

public:
	static Person parseString(string);

	// Getters 
	int getID() const;
	string getName() const;
	double getHourlyWage() const;
	int getDepartmentID() const;

	// Setters
	void setID(int);
	void setName(string);
	void setHourlyWage(double);
	void setDepartmentID(int);

};

