#include "Menu.h"
#include "Person.h"
#include "Sorter.h"
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

using namespace std;
using namespace chrono;

Menu::Menu(Person* p, int sizeOfArray)
{
	people = p;
	Menu::sizeOfArray = sizeOfArray;
	greet();
}


void Menu::greet()
{
	system("cls");
	cout << "This application is going to read a large text file, and sort it different ways." << endl;
	cout << "Which sorting method would you like to use?" << endl;
	cout << "1.)   Bubble Sort" << endl;
	cout << "2.)   Insertion Sort" << endl << endl;

	cout << "Make your selection: ";
	cin >> selection;

	handleSelection();

	if (selection > 2 || selection < 1) return greet();
}

void Menu::handleSelection()
{
	if (selection == 1)
	{
		system("cls");
		displayBubbleSort();
	}

	if (selection == 2)
	{
		system("cls");
		displayInsertSort();
	}
}

void Menu::displayBubbleSort()
{
	// Start Time  Clock Here
	high_resolution_clock::time_point start = high_resolution_clock::now();

	// Run sort method.
	Sorter::bubbleSort(people, sizeOfArray);

	// Set end clock here after sort.
	high_resolution_clock::time_point end = high_resolution_clock::now();

	// Time varibles
	duration<double, milli> time = end - start;
	double seconds = time.count() / 1000;
	double minuites = time.count() / 1000 / 60;

	cout << "Bubble Sort Method  " << endl;
	cout << "Execution Time (mins): " << minuites << endl;
	cout << "Execution Time (secs): " << seconds << endl;
	cout << endl;

	cout << "First Ten" << endl;
	cout << endl;
	cout << setw(24) << left << "ID" << setw(26) << left << "Name" << "Hourly Wage" << endl;
	cout << "=====================================================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(24) << left << people[i].getID();
		cout << setw(26) << left << people[i].getName();
		cout << people[i].getHourlyWage();
		cout << endl;
	}

	cout << endl << "Last Ten" << endl;
	cout << endl;
	cout << setw(24) << left << "ID" << setw(26) << left << "Name" << "Hourly Wage" << endl;
	cout << "=====================================================================" << endl;
	for (int i = sizeOfArray - 10; i < sizeOfArray; i++)
	{
		cout << setw(24) << left << people[i].getID();
		cout << setw(26) << left << people[i].getName();
		cout << people[i].getHourlyWage();
		cout << endl;
	}

}

void Menu::displayInsertSort()
{
	// Start Time  Clock Here
	high_resolution_clock::time_point start = high_resolution_clock::now();

	// Run sort method.
	Sorter::insertSort(people, sizeOfArray);

	// Set end clock here after sort.
	high_resolution_clock::time_point end = high_resolution_clock::now();

	// Time varibles
	duration<double, milli> time = end - start;
	double seconds = time.count() / 1000;
	double minuites = time.count() / 1000 / 60;

	cout << "Insertion Sort Method  " << endl;
	cout << "Execution Time (mins): " << minuites << endl;
	cout << "Execution Time (secs): " << seconds << endl;
	cout << endl;

	cout << "First Ten" << endl;
	cout << endl;
	cout << setw(24) << left << "ID" << setw(26) << left << "Name" << "Hourly Wage" << endl;
	cout << "=====================================================================" << endl;
	for (int i = 0; i < 10; i++)
	{
		cout << setw(24) << left << people[i].getID();
		cout << setw(26) << left << people[i].getName();
		cout << people[i].getHourlyWage();
		cout << endl;
	}

	cout << endl << "Last Ten" << endl;
	cout << endl;
	cout << setw(24) << left << "ID" << setw(26) << left << "Name" << "Hourly Wage" << endl;
	cout << "=====================================================================" << endl;
	for (int i = sizeOfArray - 10; i < sizeOfArray; i++)
	{
		cout << setw(24) << left << people[i].getID();
		cout << setw(26) << left << people[i].getName();
		cout << people[i].getHourlyWage();
		cout << endl;
	}

}