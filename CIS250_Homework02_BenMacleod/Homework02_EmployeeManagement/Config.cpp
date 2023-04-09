#include "Config.h"
#include <string>

using namespace std;

Config::Config()
{}

string Config::getDatabaseFileName() const
{
	return databaseFileName;
}

void Config::setDatabaseFileName(string v)
{
	databaseFileName = v;
}