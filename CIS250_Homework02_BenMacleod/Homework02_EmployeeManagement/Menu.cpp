#include "Menu.h"
#include <iostream>;

using namespace std;

Menu::Menu()
{}

Menu::Menu(Database* db)
{
    menuSelection = promptMenu();
    database = db;

    // Once this menu instance has been created,
    // we want to watch for when the menu selection is not-999.
    while (menuSelection != -999)
    {
        switch (menuSelection) {
        case 0:
            menuSelection = promptMenu();
            break;
        case 1:
            system("cls");
            displayAllEmployees(database->getEmployees(), NULL);
            menuSelection = promptSelection(false);
            break;
        case 2:
            system("cls");
            displayOldestEmployee(database->getEmployees());
            menuSelection = promptSelection(false);
            break;
        case 3:
            system("cls");
            displayCompSciBlding(database->getDepartments());
            menuSelection = promptSelection(false);
            break;
        case 4:
            system("cls");
            displayBldingDepts(database->getDepartments(), "A");
            menuSelection = promptSelection(false);
            break;
        case 5:
            system("cls");
            getEmloyeeBySSN(database->getEmployees());
            menuSelection = promptSelection(false);
            break;
        case 6:
            system("cls");
            displayAvgAgeByState(database->getEmployees(), "MI");
            menuSelection = promptSelection(false);
            break;
        }
    }
}

int Menu::promptMenu()
{

    system("cls");

    cout << "---------------------------------------------------------------------" << endl;
    cout << "                     Employee Management System                      " << endl;
    cout << "---------------------------------------------------------------------" << endl;
    cout << "   1. Display All Employees." << endl;
    cout << "   2. Display name of oldest employee." << endl;
    cout << "   3. Display building floor & letter of computer science department." << endl;
    cout << "   4. Display department names in building A." << endl;
    cout << "   5. Find employee by SSN and display information." << endl;
    cout << "   6. Average age of employees who live in michigan." << endl;
    cout << "-999. Exit the program." << endl << endl;

    return promptSelection(true);
}

int Menu::promptSelection(bool isMenu)
{
    int menuSelection;

    cout << "Enter your selection" << (!isMenu ? " (0 for menu, -999 to exit)" : "") << ": ";
    cin >> menuSelection;

    // Because we know -999 means exit project, we will catch it here
    // and return it so we don't have to include it in our range.
    if (menuSelection == -999)
    {
        return -999;
    }

    // Because these menu options are different than the other options we will
    // only check them when isMenu is true.
    if (isMenu && menuSelection < 1 || menuSelection > 6)
    {
        return promptSelection(isMenu);
    }
    else if (!isMenu && menuSelection != 0) {
        return promptSelection(isMenu);
    }

    return menuSelection;
}

/* Display Methods */
void Menu::displayAllEmployees(Employee* employees, Department* departments)
{
    for (int i = 0; i < database->getNumberOfEmployees(); i++)
    {
        const Employee e = employees[i];
        Department d = e.getDept();

        cout << "EMPLOYEE #" << i + 1 << endl;
        cout << "----------" << endl;
        cout << "SSN           : " << e.getSSN() << endl;
        cout << "First Name    : " << e.getFirstName() << endl;
        cout << "Last Name     : " << e.getLastName() << endl;
        cout << "Middle Inital : " << e.getMiddleInital() << endl;
        cout << "Phone Number  : " << e.getPhoneNumber() << endl;
        cout << "City          : " << e.getCity() << endl;
        cout << "State         : " << e.getState() << endl;
        cout << "Age           : " << e.getAge() << endl;
        cout << "Gender        : " << e.getGender() << endl;
        cout << "Dept ID       : " << d.getId() << endl;
        cout << "Dept Name     : " << d.getName() << endl;
        cout << "Blding Letter : " << d.getBuildingLetter() << endl;
        cout << "Blding Floor  : " << d.getBuildingFloor() << endl;
        cout << endl;
    }
}

void Menu::displayOldestEmployee(Employee* employees)
{
    Employee oldestEmployee = employees[0];

    for (int i = 0; i < database->getNumberOfEmployees(); i++)
    {
        Employee e = employees[i];

        // If the next employee is older than the current
        // change the oldest employee.
        if (e.getAge() > oldestEmployee.getAge())
        {
            oldestEmployee = e;
        }
    }

    displayOptionHeader("Oldest Employee Name");
    cout << oldestEmployee.getLastName() << ", " << oldestEmployee.getFirstName() << " " << oldestEmployee.getMiddleInital() << endl;
    cout << "Age: " << oldestEmployee.getAge() << endl;
}

void Menu::displayOptionHeader(string title)
{
    string dashedBar = "";
    for (int i = 0; i < title.length() + 2; i++)
    {
        dashedBar = dashedBar + "-";
    }

    cout << dashedBar << endl;
    cout << " " << title << endl;
    cout << dashedBar << endl;
}

void Menu::getEmloyeeBySSN(Employee* employees)
{
    string ssn = "";

    displayOptionHeader("Find Employee by SSN");

    // State Managment
    // Employee found to display results if an employee
    // is not found.
    bool employeeFound = false;

    cout << "Enter employee SSN (xxx-xx-xxxx): ";
    cin >> ssn;

    for (int i = 0; i < database->getNumberOfEmployees(); i++)
    {
        Employee e = employees[i];

        if (e.getSSN() == ssn)
        {
            // Set the employee found to true.
            employeeFound = true;

            // Get the employee department information.
            Department d = e.getDept();

            cout << "----------" << endl;
            cout << "SSN           : " << e.getSSN() << endl;
            cout << "First Name    : " << e.getFirstName() << endl;
            cout << "Last Name     : " << e.getLastName() << endl;
            cout << "Middle Inital : " << e.getMiddleInital() << endl;
            cout << "Phone Number  : " << e.getPhoneNumber() << endl;
            cout << "City          : " << e.getCity() << endl;
            cout << "State         : " << e.getState() << endl;
            cout << "Age           : " << e.getAge() << endl;
            cout << "Gender        : " << e.getGender() << endl;
            cout << "Dept ID       : " << d.getId() << endl;
            cout << "Dept Name     : " << d.getName() << endl;
            cout << "Blding Letter : " << d.getBuildingLetter() << endl;
            cout << "Blding Floor  : " << d.getBuildingFloor() << endl;
            cout << endl;
        }
    }

    // If an employee is not found tell the user.
    if (!employeeFound)
    {
        cout << "Employee with the SSN '" << ssn << "' could not be found." << endl;
    }

}

void Menu::displayAvgAgeByState(Employee* employees, string state)
{
    int totalAges = 0;
    int totalNumInState = 0;

    displayOptionHeader("Average age for employees who live in " + state);

    // Loop through employees.
    for (int i = 0; i < database->getNumberOfEmployees(); i++)
    {
        Employee e = employees[i];

        // Check if their state matches filter term.
        if (e.getState() == state)
        {
            // Add to total age & num of employees in state.
            totalAges = totalAges + e.getAge();
            totalNumInState++;
        }

    }

    // Display average age to the terminal, did compute average in here instead of varible.
    cout << "Average age of employees in " << state << " is: " << (totalAges / totalNumInState) << endl;

}

void Menu::displayCompSciBlding(Department* departments)
{
    displayOptionHeader("Computer Science Building Info");

    // Loop through departments
    for (int i = 0; i < database->getNumberOfDepartments(); i++)
    {
        Department d = departments[i];

        // If the department name is comp sci lets
        // display the building info.
        if (d.getName() == "Computer Science")
        {
            cout << "Building: " << d.getBuildingLetter() << "   Floor: " << d.getBuildingFloor() << endl;
        }
    }
}

void Menu::displayBldingDepts(Department* departments, string deptLetter)
{
    const string title = "Building " + deptLetter + " Departments";
    displayOptionHeader(title);

    for (int i = 0; i < database->getNumberOfDepartments(); i++)
    {
        Department d = departments[i];

        if (d.getBuildingLetter() == deptLetter)
        {
            cout << d.getName() << endl;
        }
    }
}


