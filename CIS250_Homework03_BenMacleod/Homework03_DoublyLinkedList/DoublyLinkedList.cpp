// Double Linked List.cpp - Ben Macleod
// Last Modified: 3/22/23
//

#include <iostream>
#include "DoublyList.h"

using namespace std;

void appendFiveElements(DoublyList* list)
{
    // Used to create new pets without multiple varibles.
    Pet* pet;

    pet = new Pet(10, 2, "John", "Dog");
    list->appendNode(pet);

    pet = new Pet(20, 1, "Rocco", "Rabbit");
    list->appendNode(pet);

    pet = new Pet(30, 4, "Earl", "Graffe");
    list->appendNode(pet);

    pet = new Pet(40, 4, "Bob", "Monkey");
    list->appendNode(pet);

    pet = new Pet(50, 4, "Sally", "Panda");
    list->appendNode(pet);

    /* Displaying the list */
    list->displayForwards();
    list->displayBackwards();
}

void insertThreeElements(DoublyList* list)
{
    // Used to create new pets without multiple varibles.
    Pet* pet;

    // Insert into begining
    pet = new Pet(5, 7, "Ben", "Zebra");
    list->insertNode(pet);

    // Insert into middle.
    pet = new Pet(23, 7, "Mimi", "Cat");
    list->insertNode(pet);

    // Insert into end.
    pet = new Pet(54, 7, "Jack", "Bird");
    list->insertNode(pet);

    // Insert into middle again.
    pet = new Pet(25, 7, "Berry", "Hippo");
    list->insertNode(pet);

    /* Displaying the list */
    list->displayForwards();
    list->displayBackwards();

}


void deleteFiveElements(DoublyList* list)
{
    list->deleteNode(5);
    list->deleteNode(25);
    list->deleteNode(54);
    list->deleteNode(40);

    /* Displaying the list */
    list->displayForwards();
    list->displayBackwards();

}

void menuPrompt(DoublyList* list)
{
    int option;
    string runAgain;

    cout << "1.) Append 5 Elements" << endl;
    cout << "2.) Insert 3 Elements" << endl;
    cout << "3.) Delete 5 Elements" << endl;

    cout << endl << "Which Action Do you want to Perform?: ";
    cin >> option;

    system("cls");

    switch (option)
    {
    case 1:
        cout << endl << "Appending 5 Elements" << endl;
        appendFiveElements(list);
        break;

    case 2:
        cout << endl << "Inserting 3 Elements" << endl;
        insertThreeElements(list);
        break;

    case 3:
        cout << endl << "Deleting 5 Elements" << endl;
        deleteFiveElements(list);
        break;
    }

    cout << "Would you like to run again? (y/n): ";
    cin >> runAgain;

    if (runAgain == "y" || runAgain == "yes")
    {
        system("cls");
        return menuPrompt(list);
    }
}

int main()
{
    DoublyList list;
    menuPrompt(&list);
;}
