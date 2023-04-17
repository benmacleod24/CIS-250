#include <iostream>
#include <fstream>

using namespace std;

void readTextFile(char maze[40][40])
{
	string lineOfText;

	// Create & Open file instance.
	fstream file;
	file.open("maze.txt");

	if (file)
	{
        // Because the index of the array starts at 0, we must account for that.
        int row = -1;
		
		// Get first line of text.
		getline(file, lineOfText);
		
		// Loop through the line of text, and parse into 2D array.
		for (int i = 0; i < lineOfText.length(); i++)
		{
			if (i % 40 == 0) row++;
			maze[row][i % 40] = lineOfText[i];
		}

	}

	file.close();
}

void displayMaze(char maze[40][40])
{
	// For Each Row
	for (int r = 0; r < 40; r++)
	{
		// Loop through each column
		for (int c = 0; c < 40; c++)
		{
			// Print that point in the array.
			cout << maze[r][c];
		}

		cout << endl;
	}
}

int main()
{
    // If you wish to use a different just change the number [x][y] format.
    char maze[40][40];

	// Read text file and prepare maze array.
    readTextFile(maze); 

	// Display original maze.
	displayMaze(maze);
}