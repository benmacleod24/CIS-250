/**
 * Name: Ben Macleod
 * Description: Triva game.
 * Date: 3/6/23
 */

#include <iostream>
#include <string>
#include "Player.h"
#include "GameDriver.h"

using namespace std;

int main()
{
    // Initalize the game driver.
    GameDriver game;

    // Varibles
    string isReadyInput;

    // Initalize the players class.
    Player p1("Player #1");
    Player p2("Player #2");

    // Get the players names.
    p1.getPlayerName();
    p2.getPlayerName();

    // Apply a pointer for the game driver.
    game.setPlayer1(&p1);
    game.setPlayer2(&p2);

    // Clear the terminal screen
    system("cls");

    // Display game information
    cout << " PGA Trivia                  " << endl;
    cout << "--------------------------------------------------------" << endl;
    cout << "Questions Per Player: " << game.getQuestionsPerPlayer() << endl;
    cout << "Max Points Per Player: " << game.getQuestionsPerPlayer() * 10 << endl;

    cout << endl;
    cout << "Players: " << endl;
    cout << p1.getName() << endl;
    cout << p2.getName() << endl;
    cout << endl;

    // Make sure they are ready to start.
    cout << "Ready to started? [yes/no]: ";
    cin >> isReadyInput;

    // Check input and perform correct action.
    if (isReadyInput == "yes" || isReadyInput == "y")
    {
        game.startGame();
    }
    else {
        return 0;
    }
}
