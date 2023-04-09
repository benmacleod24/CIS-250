#pragma once
#include <string>
#include "Player.h"

using namespace std;

class Question
{
private:
	string question;
	string* answers;
	int correctIndex;
public:
	Question();

	string getQuestion() const;
	string* getAnswers() const;
	
	void setQuestion(string);
	void addAnswer(string,int);
	void setCorrectIndex(int);

	bool isCorrectAnswer(int);
	void awardPoints(Player*);

	void ask(Player*);
};

