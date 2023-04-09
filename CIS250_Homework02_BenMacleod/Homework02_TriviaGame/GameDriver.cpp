#include "GameDriver.h"
#include "Question.h"
#include <iostream>

using namespace std;

GameDriver::GameDriver()
{
	hasGameStarted = true;
	questionsPerPlayer = 5;
	p1 = nullptr;
	p2 = nullptr;
};

/* Getters */
bool GameDriver::getGameStarted() const
{
	return hasGameStarted;
};

int GameDriver::getQuestionsPerPlayer() const
{
	return questionsPerPlayer;
}

Player* GameDriver::getPlayer1() const
{
	return p1;
}

Player* GameDriver::getPlayer2() const
{
	return p2;
}

/* Setters */
void GameDriver::setGameStarted(bool v)
{
	hasGameStarted = v;
};

void GameDriver::setPlayer1(Player* v)
{
	p1 = v;
}

void GameDriver::setPlayer2(Player* v)
{
	p2 = v;
}

/* Methods */
void GameDriver::startGame()
{

	// Ask player 1 questions till round over.
	while (p1->getNumOfRounds() < questionsPerPlayer)
	{
		const int round = p1->getNumOfRounds() + 1;
		
		if (round == 1)
		{
			Question q;

			q.setQuestion("Who is the current #1 PGA Tour Pro?");
			q.addAnswer("Justin Thomas", 0);
			q.addAnswer("Jon Rahm", 1);
			q.addAnswer("Max Homa", 2);
			q.addAnswer("Scottie Scheffler", 3);
			q.setCorrectIndex(1);

			q.ask(p1);
		}

		if (round == 2)
		{
			Question q;

			q.setQuestion("Which player has hit the longest drive on the tour?");
			q.addAnswer("Rory McIlroy", 0);
			q.addAnswer("Jon Rahm", 1);
			q.addAnswer("Tiger Woods", 2);
			q.addAnswer("Cameron Champ", 3);
			q.setCorrectIndex(3);

			q.ask(p1);
		}

		if (round == 3)
		{
			Question q;

			q.setQuestion("What year did Brooks Koepka win his first Major Championship?");
			q.addAnswer("2015", 0);
			q.addAnswer("2016", 1);
			q.addAnswer("2017", 2);
			q.addAnswer("2018", 3);
			q.setCorrectIndex(2);

			q.ask(p1);
		}

		if (round == 4)
		{
			Question q;

			q.setQuestion("Who finished their career with more PGA tour wins, Ben Hogan or Arnold Palmer?");
			q.addAnswer("Ben Hogan", 0);
			q.addAnswer("Arnold Palmer", 1);
			q.addAnswer("", 2);
			q.addAnswer("", 3);
			q.setCorrectIndex(0);

			q.ask(p1);
		}

		if (round == 5)
		{
			Question q;

			q.setQuestion("In 2003, who became the World number one golfer, ending the reign of Tiger Woods?");
			q.addAnswer("David Duval", 0);
			q.addAnswer("Vijay Singh", 1);
			q.addAnswer("Phil Mickelson", 2);
			q.addAnswer("Ernie Els", 3);
			q.setCorrectIndex(1);

			q.ask(p1);
		}
	}

	// Clear screen for player 2.
	cout << endl << endl;

	// Ask player 2 questions till round over.
	while (p2->getNumOfRounds() < questionsPerPlayer)
	{
		const int round = p2->getNumOfRounds() + 1;

		if (round == 1)
		{
			Question q;

			q.setQuestion("Spectators at Augusta National who view the Masters are called what?");
			q.addAnswer("Commoners", 0);
			q.addAnswer("Patrons", 1);
			q.addAnswer("Fans", 2);
			q.addAnswer("Invitees", 3);
			q.setCorrectIndex(1);

			q.ask(p2);
		}

		if (round == 2)
		{
			Question q;

			q.setQuestion("What famous body of water guards the 12th Hole at Augusta National?");
			q.addAnswer("Dunbar Pond", 0);
			q.addAnswer("Indian Brook", 1);
			q.addAnswer("Rae's Creek", 2);
			q.addAnswer("Lake Jones", 3);
			q.setCorrectIndex(2);

			q.ask(p2);
		}

		if (round == 3)
		{
			Question q;

			q.setQuestion("Who was the first golfer to make a hole-in-one on television?");
			q.addAnswer("Tony Jacklin", 0);
			q.addAnswer("Justin Thomas", 1);
			q.addAnswer("Tiger Woods", 2);
			q.addAnswer("John Daly", 3);
			q.setCorrectIndex(0);

			q.ask(p2);
		}

		if (round == 4)
		{
			Question q;

			q.setQuestion("What is the longest club in a golf set?");
			q.addAnswer("Pitching Wedge", 0);
			q.addAnswer("3 Wood", 1);
			q.addAnswer("Driver", 2);
			q.addAnswer("Putter", 3);
			q.setCorrectIndex(2);

			q.ask(p2);
		}

		if (round == 5)
		{
			Question q;

			q.setQuestion("How many PGA Majors are there?");
			q.addAnswer("2", 0);
			q.addAnswer("8", 1);
			q.addAnswer("3", 2);
			q.addAnswer("4", 3);
			q.setCorrectIndex(3);

			q.ask(p2);
		}
	}

	finishGame();

	hasGameStarted = true;
}

void GameDriver::finishGame()
{
	system("cls");
	
	if (p1->getPoints() == p2->getPoints())
	{
		cout << "It was a tie!!" << endl;
		cout << "======================================" << endl;
		cout << p1->getName() << ": " << p1->getPoints() << endl;
		cout << p2->getName() << ": " << p2->getPoints() << endl;
	}

	if (p1->getPoints() < p2->getPoints())
	{
		cout << p2->getName() << " won!!" << endl;
		cout << "======================================" << endl;
		cout << p1->getName() << ": " << p1->getPoints() << endl;
		cout << p2->getName() << ": " << p2->getPoints() << endl;
	}

	if (p1->getPoints() > p2->getPoints())
	{
		cout << p1->getName() << " won!!" << endl;
		cout << "======================================" << endl;
		cout << p1->getName() << ": " << p1->getPoints() << endl;
		cout << p2->getName() << ": " << p2->getPoints() << endl;
	}

}