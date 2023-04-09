#include "Department.h"
#include <iostream>

Department Department::parse(string& src)
{
    Department d;
    int nextCommaPosition;

    /* Department Id */
    nextCommaPosition = src.find(",");
    d.id = stoi(src.substr(0, nextCommaPosition));
    src = src.erase(0, nextCommaPosition + 1);

    /* Department Name */
    nextCommaPosition = src.find(",");
    d.name = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* Building Letter */
    nextCommaPosition = src.find(",");
    d.buildingLetter = src.substr(0, nextCommaPosition)[0];
    src = src.erase(0, nextCommaPosition + 1);

    /* Building Floor */
    nextCommaPosition = src.find(",");
    d.buildingFloor = stoi(src.substr(0, nextCommaPosition));
    src = src.erase(0, nextCommaPosition + 1);

    return d;
}

/* Getters */
int Department::getId() const
{
    return id;
}

string Department::getName() const
{
    return name;
}

string Department::getBuildingLetter() const
{
    return buildingLetter;
}

int Department::getBuildingFloor() const
{
    return buildingFloor;
}