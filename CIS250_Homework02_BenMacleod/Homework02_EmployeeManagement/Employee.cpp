#include "Employee.h"
#include <string>

using namespace std;

 Employee Employee::parse(string& src)
 {
	 Employee e;
     int nextCommaPosition;

     /* SSN */
     nextCommaPosition = src.find(",");
     e.ssn = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* First Name */
     nextCommaPosition = src.find(",");
     e.firstName = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* Last Name */
     nextCommaPosition = src.find(",");
     e.lastName = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* Middle Inital */
     nextCommaPosition = src.find(",");
     e.middleInital = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* City */
     nextCommaPosition = src.find(",");
     e.city = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* State */
     nextCommaPosition = src.find(",");
     e.state = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     /* Age */
     nextCommaPosition = src.find(",");
     e.age = stoi(src.substr(0, nextCommaPosition));
     src = src.erase(0, nextCommaPosition + 1);

     /* Gender */
     nextCommaPosition = src.find(",");
     e.gender = src.substr(0, nextCommaPosition);
     src = src.erase(0, nextCommaPosition + 1);

     return e;
 }

 string Employee::getSSN() const
 {
     return ssn;
 };

string Employee::getFirstName() const
{
    return firstName;
};

string Employee::getLastName() const
{
    return lastName;
};

string Employee::getMiddleInital() const
{
    return middleInital;
};

string Employee::getCity() const
{
    return city;
};

string Employee::getState() const
{
    return state;
};

string Employee::getGender() const
{
    return gender;
};

string Employee::getPhoneNumber() const
{
    return phoneNumber;
};

int Employee::getAge() const
{
    return age;
};

Department Employee::getDept() const
{
    return dept;
}

/* Setters */
void Employee::setPhoneNumber(string v) {
    phoneNumber = v;
}

void Employee::setDept(Department v)
{
    dept = v;
}