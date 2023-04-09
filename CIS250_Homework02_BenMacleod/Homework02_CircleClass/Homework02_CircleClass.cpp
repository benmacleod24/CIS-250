/**
 * Name: Ben Macleod
 * Description: Program that creates a new circle class based on the radius the user gives. It will then generate the area, diameter, circumference of the circle and display it to the user.
 * Date: 3/6/23
 */

#include <iostream>
#include "Circle.h"

// Namespaces
using namespace std;

// Entry Point
int main()
{
    // Initalize the circle;
    Circle circle;
    
    // Varible to get inputs.
    float radiusInput;
    string runAgain;

    // Ask for the radius.
    cout << "Please enter a radius for the circle: ";
    cin >> radiusInput;

    // Set the new radius the user entered.
    circle.setRadius(radiusInput);

    // Clear the console.
    system("cls");

    // Display the circles properties.
    cout << "Area: " << circle.getArea() << endl;
    cout << "Diameter: " << circle.getDiameter() << endl;
    cout << "Circumference: " << circle.getCircumference() << endl;
    cout << endl;

    // Ask if they want to try again.
    cout << "Would you like to try again? (yes/no): ";
    cin >> runAgain;

    // If they want to run again recurse main.
    if (runAgain == "yes" || runAgain == "y")
    {
        system("cls");
        return main();
    }

    return 0;
}
