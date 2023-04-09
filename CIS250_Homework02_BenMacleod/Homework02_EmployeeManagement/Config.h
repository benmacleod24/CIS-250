#pragma once
#include <string>

using namespace std;

class Config
{
	private:
		string databaseFileName;

	public:
		Config();

		/* Getters */
		string getDatabaseFileName() const;

		/* Setters */
		void setDatabaseFileName(string);
};

