#include <iostream>
#include "Database.h"
#include "Config.h"
#include "Menu.h"

using namespace std;

int main()
{
	Config config;

	// Set config values.
	config.setDatabaseFileName("EmployeeList.txt");

	// Initalize the database with config.
	Database database(&config);

	// If the database did not initalize end program.
	if (!database.getDatabaseState())
	{
		cout << "Database failed to initalize, please retry the program." << endl;
		return 0;
	}

	Menu menu(&database);

}