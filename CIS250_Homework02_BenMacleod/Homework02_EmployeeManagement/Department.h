#pragma once
#include <string>

using namespace std;

class Department
{
private:
    int id;
    string name;
    string buildingLetter;
    int buildingFloor;
public:
	static Department parse(string&);
    int getId() const;
    string getName() const;
    string getBuildingLetter() const;
    int getBuildingFloor() const;


};

