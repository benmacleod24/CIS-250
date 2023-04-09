#include "Question.h"
#include <iostream>;
#include <iomanip>;
#include <string>;

using namespace std;

Question::Question() {
	answers = new string[4];
}

string Question::getQuestion() const
{
	return question;
};
string* Question::getAnswers() const
{
	return answers;
};

void Question::setQuestion(string v)
{
	question = v;
};
void Question::addAnswer(string v, int position)
{
	answers[position] = v;
};
void Question::setCorrectIndex(int v)
{
	correctIndex = v;
};

bool Question::isCorrectAnswer(int v)
{
	if (v == correctIndex)
	{
		return true;
	}

	return false;
}

void Question::awardPoints(Player* p)
{
	const int newPoints = p->getPoints() + 10;
	p->setPoints(newPoints);
}

void Question::ask(Player* p)
{
	int resp;
	string complete;

	system("cls");

	cout << " " << p->getName() << setw(25) << "Total Points: " << p->getPoints() << setw(25) << "Question #: " << p->getNumOfRounds() + 1 << endl;
	cout << "====================================================================================" << endl << endl; 

	cout << question << endl;
	cout << endl;

	// Print each answer
	for (int i = 0; i < 4; i++)
	{
		cout << "#" << i + 1 << " " << answers[i] << endl;
	}

	cout << endl;

	cout << "Enter your answer: ";
	cin >> resp;

	if (isCorrectAnswer(resp - 1))
	{
		awardPoints(p);
		cout << "Awesome! You earned 10 pts." << endl;
	}
	else
	{
		cout << "Wrong Answer! No points earned." << endl;
	}

	cout << endl;

	while (tolower(complete[0]) != 'y')
	{
		
		cout << "Ready to continue? (y/n): ";
		cin >> complete;

		p->setNumOfRounds(p->getNumOfRounds() + 1);
	}

	
}