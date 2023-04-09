// Pet.cpp - Ben Macleod
// Last Modified: 3/21/23
//

#include "Pet.h"

Pet::Pet()
{};

Pet::Pet(int i, int a, string n, string t)
{
	id = i;
	age = a;
	name = n;
	type = t;
};

/* Getters */
int Pet::getId() const
{
	return id;
};

int Pet::getAge() const
{
	return age;
};

string Pet::getName() const
{
	return name;
};

string Pet::getType() const
{
	return type;
}

/* Setters */
void Pet::setId(int v)
{
	id = v;
};

void Pet::setAge(int v)
{
	age = v;
};

void Pet::setName(string v)
{
	name = v;
};

void Pet::setType(string v)
{
	type = v;
};