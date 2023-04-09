#pragma once
#include <string>

using namespace std;

class Player
{
private:
	int points;
	string name;
	int numOfRounds;

public:
	Player();
	Player(string);

	/* Getters */
	int getPoints() const;
	string getName() const;
	int getNumOfRounds() const;

	/* Setters */
	void setPoints(int);
	void setName(string);
	void setNumOfRounds(int);

	/* Methods */
	void getPlayerName();
};

