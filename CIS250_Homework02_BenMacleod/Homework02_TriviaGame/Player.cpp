#include "Player.h"
#include <iostream>

using namespace std;

Player::Player()
{
	points = 0;
	numOfRounds = 0;
};

Player::Player(string _name)
{
	points = 0;
	name = _name;
	numOfRounds = 0;
};

/* Getters */
int Player::getPoints() const
{
	return points;
};

string Player::getName() const
{
	return name;
};

int Player::getNumOfRounds() const
{
	return numOfRounds;
}

/* Setters */
void Player::setPoints(int p)
{
	points = p;
};

void Player::setName(string n)
{
	name = n;
};

void Player::setNumOfRounds(int v)
{
	numOfRounds = v;
}

/* Methods */
void Player::getPlayerName()
{
	// Store old name incase no name is entered.
	string oldName = name;

	// Ask the players name.
	cout << oldName <<" what is your name: ";
	getline(cin, name);

	// If the name is empty, set to old.
	if (name == "")
	{
		name = oldName;
	}
}