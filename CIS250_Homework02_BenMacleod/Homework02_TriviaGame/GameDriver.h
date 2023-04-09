#pragma once
#include "Player.h"

class GameDriver
{
private:
	bool hasGameStarted;
	int questionsPerPlayer;
	Player* p1;
	Player* p2;

public:
	GameDriver();

	/* Getters */
	bool getGameStarted() const;
	int getQuestionsPerPlayer() const;
	Player* getPlayer1() const;
	Player* getPlayer2() const;

	/* Setters */
	void setGameStarted(bool);
	void setPlayer1(Player*);
	void setPlayer2(Player*);

	/* Methods */
	void startGame();
	void finishGame();
};

