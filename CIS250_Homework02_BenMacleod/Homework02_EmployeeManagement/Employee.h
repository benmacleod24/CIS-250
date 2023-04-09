#pragma once
#include <string>
#include "Department.h"

using namespace std;

class Employee
{
private:
    string ssn;
    string firstName;
    string lastName;
    string middleInital;
    string city;
    string state;
    string gender;
    int age;
    string phoneNumber;
    Department dept;

public:
	static Employee parse(string&);

    /* Getters */
    string getSSN() const;
    string getFirstName() const;
    string getLastName() const;
    string getMiddleInital() const;
    string getCity() const;
    string getState() const;
    string getGender() const;
    string getPhoneNumber() const;
    int getAge() const;
    Department getDept() const;

    /* Setters */
    void setSSN(string);
    void setFirstName(string);
    void setLastName(string);
    void setMiddleInital(string);
    void setCity(string);
    void setState(string);
    void setGender(string);
    void setPhoneNumber(string);
    void setAge(int);
    void setDept(Department);
};

