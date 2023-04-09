/**
 * Title: Employee Management System.
 * Author: Ben Macleod
 * Class: CIS-250
 */

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

struct Department
{
    int id;
    string name;
    string buildingLetter;
    int buildingFloor;
};

struct Employee
{
    string ssn;
    string firstName;
    string lastName;
    string middleInital;
    string city;
    string state;
    string gender;
    int age;
    string phoneNumber;
    Department dept;
};

/**
 * Check if a department exist the the current departments vector.
 */
bool doesDepartmentExist(vector<Department> departments, Department d)
{

    for (Department _d : departments)
    {
        if (_d.id == d.id) return true;
    }

    return false;
}

/**
 * Get department by it's id.
 */
Department getDepartmentById(vector<Department> departments, int deptId)
{
    for (Department d : departments)
    {
        if (d.id == deptId)
        {
            return d;
        }
    }
}

/**
 * Build & Display the option header.
 */
void displayOptionHeader(string title)
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

/**
 * Parse the department string and return the new department struct,
 * important to know that this function does not insert into the array.
 */
Department parseDepartmentString(string& src)
{
    Department d;
    int nextCommaPosition;

    /* Department Id */
    nextCommaPosition = src.find(",");
    d.id = stoi(src.substr(0, nextCommaPosition));
    src = src.erase(0, nextCommaPosition + 1);

    /* Department Name */
    nextCommaPosition = src.find(",");
    d.name = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* Building Letter */
    nextCommaPosition = src.find(",");
    d.buildingLetter = src.substr(0, nextCommaPosition)[0];
    src = src.erase(0, nextCommaPosition + 1);

    /* Building Floor */
    nextCommaPosition = src.find(",");
    d.buildingFloor = stoi(src.substr(0, nextCommaPosition));
    src = src.erase(0, nextCommaPosition + 1);

    return d;
}

/**
 * Parse each employee into their own respective structure.
 * 
 * The logic for parsing is repeated. It gets the position of the upcoming token
 * then uses sub string to select that part of the datasource and saves it. Once
 * that is complete it erases it from the string since it's no longer needed.
 */
Employee parseEmployeeString(string& src)
{
    Employee e;
    int nextCommaPosition;

    /* SSN */
    nextCommaPosition = src.find(",");
    e.ssn = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* First Name */
    nextCommaPosition = src.find(",");
    e.firstName = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* Last Name */
    nextCommaPosition = src.find(",");
    e.lastName = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* Middle Inital */
    nextCommaPosition = src.find(",");
    e.middleInital = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* City */
    nextCommaPosition = src.find(",");
    e.city = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* State */
    nextCommaPosition = src.find(",");
    e.state = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    /* Age */
    nextCommaPosition = src.find(",");
    e.age = stoi(src.substr(0, nextCommaPosition));
    src = src.erase(0, nextCommaPosition + 1);

    /* Gender */
    nextCommaPosition = src.find(",");
    e.gender = src.substr(0, nextCommaPosition);
    src = src.erase(0, nextCommaPosition + 1);

    return e;
}

/**
 * Parse a data record into it's respective values and insert them into their
 * correct vectors to be accessed.
 */
void parseDatasource(string src, vector<Employee>& employees, vector<Department>& departments)
{
    Employee emp = parseEmployeeString(src);
    Department dept = parseDepartmentString(src);

    // Because phone number is placed at the end of
    // the data string we need to save the value
    // once everything has been parsed.
    emp.phoneNumber = src;

    // Decided  to save the dept id for which the employee belongs,
    // makes sorting through data much easier.
    emp.dept = dept;

    // Push the employee to the vector.
    employees.push_back(emp);

    // If the department deoesn't exist the we can
    // add it to the vector.
    if (!doesDepartmentExist(departments, dept))
    {
        departments.push_back(dept);
    }
 
}

/**
 * Open the data file and loop through each line parsing it and adding it to the vector,
 * essentially seeding the database for the application.
 */
void seedDatabase(vector<Employee>& employees, vector<Department>& departments)
{
    const string dbName = "EmployeeList.txt";
    fstream db;

    // Open the database file.
    db.open(dbName);

    // If the database was opened
    // perform our seediong logic.
    if (db)
    {
        string row;

        // While not end of file
        // get a new line and perform logic.
        while (!db.eof())
        {
            getline(db, row);
            parseDatasource(row, employees, departments);
        }

        db.close();
    }
    // If we could not open the file, only error would be we
    // can't find the file.
    else {
        system("cls");
        cout << "Error: Could not find database file." << endl;
        cout << "Looking for file: " << dbName << endl;
    }
}

/**
 * Display all employees and all their respective data to the terminal. 
 */
void displayAllEmployees(vector<Employee>& employees, vector<Department>& departments)
{
    for (int i = 0; i < employees.size(); i++)
    {
        const Employee e = employees[i];
        Department d = e.dept;

        cout << "EMPLOYEE #" << i + 1 << endl;
        cout << "----------" << endl;
        cout << "SSN           : " << e.ssn << endl;
        cout << "First Name    : " << e.firstName << endl;
        cout << "Last Name     : " << e.lastName << endl;
        cout << "Middle Inital : " << e.middleInital << endl;
        cout << "Phone Number  : " << e.phoneNumber << endl;
        cout << "City          : " << e.city << endl;
        cout << "State         : " << e.state << endl;
        cout << "Age           : " << e.age << endl;
        cout << "Gender        : " << e.gender << endl;
        cout << "Dept ID       : " << d.id << endl;
        cout << "Dept Name     : " << d.name << endl;
        cout << "Blding Letter : " << d.buildingLetter << endl;
        cout << "Blding Floor  : " << d.buildingFloor << endl;
        cout << endl;
    }
}

/**
 * Filter and find the oldest employee and display them to the terminal.
 */
void displayOldestEmployee(vector<Employee>& employees)
{
    Employee oldestEmployee = employees[0];

    for (Employee e : employees)
    {
        // If the next employee is older than the current
        // change the oldest employee.
        if (e.age > oldestEmployee.age)
        {
            oldestEmployee = e;
        }
    }

    displayOptionHeader("Oldest Employee Name");
    cout << oldestEmployee.lastName << ", " << oldestEmployee.firstName << " " << oldestEmployee.middleInital << endl;
    cout << "Age: " << oldestEmployee.age << endl;
}

/**
 * Display building info for the computer science building.
 */
void displayCompSciBlding(vector<Department> departments)
{
    displayOptionHeader("Computer Science Building Info");

    // Loop through departments
    for (Department d : departments)
    {
        // If the department name is comp sci lets
        // display the building info.
        if (d.name == "Computer Science")
        {
            cout << "Building: " << d.buildingLetter << "   Floor: " << d.buildingFloor << endl;
        }
    }
}

/**
 * Display departments in a building.
 */
void displayBldingDepts(vector<Department> departments, string deptLetter)
{
    const string title = "Building " + deptLetter + " Departments";
    displayOptionHeader(title);

    for (Department d : departments)
    {
        if (d.buildingLetter == deptLetter)
        {
            cout << d.name << endl;
        }
    }
}

/**
 * Display the average age of employees in a certain state.
 */
void displayAvgAgeByState(vector<Employee> employees, string state)
{
    int totalAges = 0;
    int totalNumInState = 0;

    displayOptionHeader("Average age for employees who live in " + state);

    // Loop through employees.
    for (Employee e : employees)
    {
        // Check if their state matches filter term.
        if (e.state == state)
        {
            // Add to total age & num of employees in state.
            totalAges = totalAges + e.age;
            totalNumInState++;
        }
    }

    // Display average age to the terminal, did compute average in here instead of varible.
    cout << "Average age of employees in " << state << " is: " << (totalAges / totalNumInState) << endl;

}


/**
 * Find an employee by their SSN. This function handles the input portion of finding the
 * employee.
 */
void getEmloyeeBySSN(vector<Employee> employees, vector<Department> departments)
{
    string ssn = "";

    displayOptionHeader("Find Employee by SSN");
    
    // State Managment
    // Employee found to display results if an employee
    // is not found.
    bool employeeFound = false;

    cout << "Enter employee SSN (xxx-xx-xxxx): ";
    cin >> ssn;

    for (Employee e : employees)
    {
        if (e.ssn == ssn)
        {
            // Set the employee found to true.
            employeeFound = true;

            // Get the employee department information.
            Department d = e.dept;

            cout << "----------" << endl;
            cout << "SSN           : " << e.ssn << endl;
            cout << "First Name    : " << e.firstName << endl;
            cout << "Last Name     : " << e.lastName << endl;
            cout << "Middle Inital : " << e.middleInital << endl;
            cout << "Phone Number  : " << e.phoneNumber << endl;
            cout << "City          : " << e.city << endl;
            cout << "State         : " << e.state << endl;
            cout << "Age           : " << e.age << endl;
            cout << "Gender        : " << e.gender << endl;
            cout << "Dept ID       : " << d.id << endl;
            cout << "Dept Name     : " << d.name << endl;
            cout << "Blding Letter : " << d.buildingLetter << endl;
            cout << "Blding Floor  : " << d.buildingFloor << endl;
            cout << endl;
        }
    }

    // If an employee is not found tell the user.
    if (!employeeFound)
    {
        cout << "Employee with the SSN '" << ssn << "' could not be found." << endl;
    }

}

/**
 * Prompt for a menu selection from the user, verify and check input is a valid option.
 */
int promptSelection(bool isMenu)
{
    int menuSelection;

    cout << "Enter your selection" << (!isMenu ? " (0 for menu, -999 to exit)" : "") << ": ";
    cin >> menuSelection;

    // Because we don't -999 means exit project, we will catch it here
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

/**
 * Display the menu and prompt for a selection when doing so.
 */
int promptMenu()
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

/**
 * TODO: I would like to organize into different files for cleaner
 * code but that is a once everything is done issue.
 * 
 * TODO: Build menu functionality and sorting features.
 */
int main()
{
    // Databases*
    vector<Employee> employees;
    vector<Department> departments;

    // Seed/Init the database.
    seedDatabase(employees, departments);
    
    // Prompt for inital menu selection.
    int menuSelection = promptMenu();

    while (menuSelection != -999)
    {

        switch (menuSelection) {
        case 0:
            menuSelection = promptMenu();
            break;
        case 1:
            system("cls");
            displayAllEmployees(employees, departments);
            menuSelection = promptSelection(false);
            break;
        case 2:
            system("cls");
            displayOldestEmployee(employees);
            menuSelection = promptSelection(false);
            break;
        case 3:
            system("cls");
            displayCompSciBlding(departments);
            menuSelection = promptSelection(false);
            break;
        case 4:
            system("cls");
            displayBldingDepts(departments, "A");
            menuSelection = promptSelection(false);
            break;
        case 5:
            system("cls");
            getEmloyeeBySSN(employees, departments);
            menuSelection = promptSelection(false);
            break;
        case 6:
            system("cls");
            displayAvgAgeByState(employees, "MI");
            menuSelection = promptSelection(false);
            break;
        }
    }

    system("cls");
}
