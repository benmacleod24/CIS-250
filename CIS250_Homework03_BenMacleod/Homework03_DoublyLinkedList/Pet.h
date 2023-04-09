// Pet.h - Ben Macleod
// Last Modified: 3/21/23
//

#pragma once
#include <string>

using namespace std;

class Pet
{
private:
	int id;
	int age;
	string name;
	string type;

public:
	Pet();
	Pet(int, int, string, string);

	/* Getters */
	int getId() const;
	int getAge() const;
	string getName() const;
	string getType() const;

	/* Setters */
	void setId(int);
	void setAge(int);
	void setName(string);
	void setType(string);
};

