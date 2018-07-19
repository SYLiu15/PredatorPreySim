/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#include <iostream>
#include <ctime> // Header file needed to use time

#include "grid.hpp"
#include "ant.hpp"
#include "critter.hpp"

using std::cout;
using std::endl;
using std::cin;

int getChoice (int maxChoice);
void displayRepeatMenu();

int main() {

	cout << "Welcome to Group 13's Predator-Prey Simulation." << endl;

	// Set a random generator seed
	// Referenced from Program 3-32 of C++ Early Objects, 9th Edition
	unsigned seed;

	seed = static_cast<unsigned>(time(0));
	srand(seed);

	cout << "The simulation will occur on a grid whose size you may choose."
			<< endl;
	cout << "Please enter the number of rows for the grid: ";
	int rows = getChoice(400);

	cout << "Please enter the number of columns for the grid: ";
	int cols = getChoice(400);

	Grid critterGrid(rows,cols); // Construct grid

	// Add first ant and doodlebug

	// Prompt user for # of timesteps
	cout << "How many timesteps would you like the simulation to run?" << endl;

	int timesteps = getChoice(20000); // Input validation

	for (int i = 0; i < timesteps; i++) {
		// For each element of the array, find Doodlebug pointers
		for (int j = 0; j < rows; j++) {
			for (int k = 0; k < cols; k++) {
				if ((typeid(critterGrid[j][k]) == typeid(Doodlebug *))) {
					critterGrid[j][k]->move(); // Move all Doodlebugs
					// Check to see if any Doodlebugs should Starve
					if (critterGrid[j][k]->getStepsSinceEating() >= 3) {
						dynamic_cast<Doodlebug *>(critterGrid[j][k])->starve();
					}
				}
			}
		}
		// For each element of the array, find Ant pointers
				// Move all ants
		// For each element of the array, find Doodlebug pointers
				// Breed all eligible Doodlebugs
		// For each element of the array, find Ant pointers
				// Breed all eligible Ants

		// Print grid at end of each time step
		critterGrid.printGrid();
	}

	// Display repeat menu to ask if user would like to run again or quit
	int choice;

	do {
		displayRepeatMenu();
		choice = getChoice(2);

		if (choice == 2) {
			// Repeat everything above

		}
	} while (choice != 2); // Repeat unless user chooses to quit


	return 0;
}

/* getChoice is a function that takes an int parameter and returns an int. It
		* validates the user input to make sure it is within range and an
		* appropriate integer. If it fails, it clears the buffer and asks the user
		* to try again. */

int getChoice(int maxChoice) {
	int input;
	cout << "Please enter your choice: ";
	cin >> input;

	// Try again if input is out of range or fails
	while (input < 1 || input > maxChoice || cin.fail()) {
		cout << "Choice must be an integer between 1 and " << maxChoice << ". "
		     << endl;
		cout << "Please try again: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}

/* displayRepeatMenu is a void function that takes no parameters and
 * displays the option for the user after the user has played through one
 * round. */

void displayRepeatMenu() {
	cout << "\nThank you for playing! " << endl;
	cout << "\n\tPLAY AGAIN? \n \n";
	cout << "1. Repeat Predator-Prey Simulation by choosing 1. " << endl;
	cout << "2. Quit the program by choosing 2." << endl;
}
