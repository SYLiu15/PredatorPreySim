#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <typeinfo>

#include "ant.hpp"
#include "critter.hpp"
#include "doodlebug.hpp"

void place_bugs(Critter ***, int, int);
void place_ants(Critter ***, int, int);
void place_doodlebugs(Critter ***, int, int);

void move_bugs(Critter ***, int, int);
void move_ants(Critter ***, int, int);
void breed_bugs(Critter ***, int, int);

void print_board(Critter ***, int, int);
void runRound(Critter ***, int, int);
void reset_flags(Critter ***, int, int);
int getChoice(int, int);

void startSim();
void repeatRoundMenu();
void repeatMenu();

int main() {
	cout << "\n\n\n\n";
	cout << "***********************************************" << endl;
	cout << "Welcome to Group 13's Predator-Prey Simulation." << endl;
	cout << "***********************************************" << endl;
	// Set a random generator seed
	// Referenced from Program 3-32 of C++ Early Objects, 9th Edition
	unsigned seed;

	seed = static_cast<unsigned>(time(0));
	srand(seed);

	startSim();

	// Ask if user would like to play again and loop until they don't
	int repeatChoice;
	do {
		repeatMenu();
		repeatChoice = getChoice(1,2);

		switch(repeatChoice) {
			case 1:
				cout << "\n\n\n\n";
				startSim();
				break;
			case 2:
				break;
			default:
				break;
		}
	} while (repeatChoice != 2);

	return 0;
	
}
/*******************************************************************************
startSim is a void function without parameters. It allows the user to enter
the size of board and constructs the board. It calls the appropriate functions
to place bugs, print, run each round, and ask for the user to repeat.
*******************************************************************************/
void startSim() {

	cout << "\nThe simulation will occur on a grid with user provided dimensions" << endl;
	cout << "The number of ants and doodlebugs will be provided by the user and the placement randomized" << endl;
	cout << "\nPlease enter the number of rows for the grid (min-2, max-50): ";
	int arrayLength = getChoice(2, 50);

	cout << "\nPlease enter the number of columns for the grid (min-2, max-50): ";
	int arrayWidth = getChoice(2, 50);
		
	//initialize array of Critter pointers
	Critter ***array = new Critter**[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		array[i] = new Critter*[arrayWidth];
		for (int j = 0; j < arrayWidth; j++) {
			array[i][j] = nullptr;
		}
	}
	
	//prompt for and randomize bug location
	place_bugs(array, arrayLength, arrayWidth);
	
	//run simulation, repeat until user types 'q'
	//print starting location
	print_board(array, arrayLength, arrayWidth);

	//run first round of simulation
	runRound(array, arrayLength, arrayWidth);

	int repeatRound;
	do {
		repeatRoundMenu();
		repeatRound = getChoice(1,2);

		switch(repeatRound) {
			case 1: {
				//cout << "The simulation will run on the same grid." << endl;
				runRound(array, arrayLength, arrayWidth);
				break;
				}
			case 2:
				break;
			default:
				break;
		}
	} while (repeatRound != 2);
	
	//remove all data from memory
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			delete array[i][j];
		}
		delete [] array[i];
	}
	delete [] array;
}
/*******************************************************************************
runRound is a void function that takes paramters of the Critter pointer board,
its length and width. It runs the simulation for the number of steps that the 
user has specified, then destructs the board.
*******************************************************************************/
void runRound(Critter ***array, int arrayLength, int arrayWidth) {
	//prompt user for # of timesteps
	cout << "How many timesteps would you like the simulation to run? (min-1, max-20000): ";
	int timesteps = getChoice(1,20000); // Input validation

	int stepCount = 0;
		
	// removed value=1 from while condition
	while (stepCount < timesteps) {
		move_bugs(array, arrayLength, arrayWidth);
		move_ants(array, arrayLength, arrayWidth);
		
		breed_bugs(array, arrayLength, arrayWidth);
		
		
		//reset already_moved flags back to false after all moves made
		reset_flags(array, arrayLength, arrayWidth);

		//increment step counter
		stepCount++;
		
		//prompt for continue
		//REMOVE THIS ***********************************************
		//this stops the sim at every step, used it for testing.
		//Need to implement ability to stop at every step.
		//******************************
		/*string input = "";
		cout << "Press enter to run next step (q to quit): ";
		getline(cin, input);
		if (input == "q") {
			break;
		}*/
		//******************************
	}
	//print board
	print_board(array, arrayLength, arrayWidth);
}


/*******************************************************************************
** Prompt user for the number of ants and doodlebugs to place. Uses arrayLength
** and arrayWidth to determine the maximum amount the user can provide.
** Runs place_ant and place_doodlebugs function until all bugs have been placed.
*******************************************************************************/
void place_bugs(Critter ***array, int arrayLength, int arrayWidth) {
	//get number of ants
	cout << "\nEnter the number of ants (min-1, max-" << arrayLength*arrayWidth-1 << "): ";
	int ants = getChoice(1, arrayLength*arrayWidth-1);
	
	//get number of doodlebugs
	if (ants < arrayLength*arrayWidth-1) {
		cout << "\nEnter the number of doodlebugs (min-1, max-" << arrayLength*arrayWidth - ants << "): ";
	}
	else {
		cout << "\nEnter the number of doodlebugs (max-1): ";
	}
	int doodle = getChoice(1, arrayLength*arrayWidth - ants);
	
	//Add bugs if still remaining
	while (ants > 0) {
		place_ants(array, arrayLength, arrayWidth);
		ants--;
	}
	while (doodle > 0) {
		place_doodlebugs(array, arrayLength, arrayWidth);
		doodle--;
	}
}

/*******************************************************************************
** randomizes coordinate on the board until the location is nullptr. Places ant if true.
*******************************************************************************/
void place_ants(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col;
	do {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
	} while (array[row][col] != nullptr);
	
	array[row][col] = new Ant(row,col,0,false);
}

/*******************************************************************************
** randomizes coordinate on the board until the location is nullptr. Places doodlebug if true.
*******************************************************************************/
void place_doodlebugs(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col;
	do {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
	} while (array[row][col] != nullptr);
	
	array[row][col] = new Doodlebug(row,col,0,false);
}


/*******************************************************************************
** Determine number of doodlebugs, randomize coordinates to select doodlebugs to move,
** continue until no doodlebugs left.
** OR
** 10000 iterations have been reach, at which it would likely take too long to resolve,
** reverts back to original behavior and scans from left to right, top to bottom.
**
** Result is that behavior is overall more randomized. No visible tendency of bugs to
** move to one area of the board.
*******************************************************************************/
void move_bugs(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col, iteration = 0, numBugs = 0;
	
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'X') && (array[i][j]->getAlreadyMoved() == false)) {
				numBugs++;
			}
		}
	}
	//cout << "\n\nNumber of bugs is " << numBugs << endl;
	
	while (numBugs > 0) {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
		
		if ((array[row][col] != nullptr) && (array[row][col]->getStatus() == 'X') && (array[row][col]->getAlreadyMoved() == false)) {
			array[row][col]->move(array, arrayLength, arrayWidth);
			numBugs--;
		}
		iteration++;
		
		if (iteration > 10000) {
			for (int i = 0; i < arrayLength; i++) {
				for (int j = 0; j < arrayWidth; j++) {
					if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'X') && (array[i][j]->getAlreadyMoved() == false)) {
						array[i][j]->move(array, arrayLength, arrayWidth);
					}
				}
			}
			numBugs = 0;
		}
	}
	//cout << "Took " << iteration << " iterations" << endl;
}

/*******************************************************************************
** Same behavior as move_bugs
*******************************************************************************/
void move_ants(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col, iteration = 0, numBugs = 0;
	
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'O') && (array[i][j]->getAlreadyMoved() == false)) {
				numBugs++;
			}
		}
	}
	//cout << "Number of ants is " << numBugs << endl;
	
	while (numBugs > 0) {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
		
		if ((array[row][col] != nullptr) && (array[row][col]->getStatus() == 'O') && (array[row][col]->getAlreadyMoved() == false)) {
			array[row][col]->move(array, arrayLength, arrayWidth);
			numBugs--;
		}
		iteration++;
		
		if (iteration > 10000) {
			for (int i = 0; i < arrayLength; i++) {
				for (int j = 0; j < arrayWidth; j++) {
					if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'O') && (array[i][j]->getAlreadyMoved() == false)) {
						array[i][j]->move(array, arrayLength, arrayWidth);
					}
				}
			}
			numBugs = 0;
		}
	}
	//cout << "Took " << iteration << " iterations" << endl;
}

/*******************************************************************************
** scans from left to right, top to bottom, runns breed() on each bug.
** doodlebugs run first.
*******************************************************************************/
void breed_bugs(Critter ***array, int arrayLength, int arrayWidth) {
	//breed doodlebugs
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'X') && (array[i][j]->getStepsSinceBreeding() >= 8)) {
				array[i][j]->breed(array, arrayLength, arrayWidth);
			}
		}
	}
	//then breed ants
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'O') && (array[i][j]->getStepsSinceBreeding() >= 3)) {
				array[i][j]->breed(array, arrayLength, arrayWidth);
			}
		}
	}
}

/*******************************************************************************
print_board is a void function that takes parameters of the Critter grid, 
the int value of the grid length and width. It prints the grid with O
representing Ant pointers and X representing Doodlebug pointers.
*******************************************************************************/
void print_board(Critter ***array, int arrayLength, int arrayWidth) {
	cout << endl;
	for (int i = 0; i < arrayWidth+2; i++) {
		if (i == arrayWidth+1) {
			cout << "-";
		}
		else {
			cout << "--";
		}
	}
	cout << endl;
	for (int i = 0; i < arrayLength; i++) {
		cout << "|";
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] == nullptr) {
				cout << "  ";
			}
			else {
				if (array[i][j]->getStatus() == 'O') {
					cout << " \033[37;40m" << array[i][j]->getStatus() << "\033[0m";
				}
				else {
					cout << " \033[31;40m" << array[i][j]->getStatus() << "\033[0m";
				}
			}
		}
		cout << " |" << endl;
	}
	for (int i = 0; i < arrayWidth+2; i++) {
		if (i == arrayWidth+1) {
			cout << "-";
		}
		else {
			cout << "--";
		}
	}
	cout << endl;
}

/*******************************************************************************
reset_flags is a void function that takes parameters of the Critter grid, 
the int value of the grid length and width. It sets all boolean flags of all
existing Critters' alreadyMoved variable to false for the next round.
*******************************************************************************/
void reset_flags(Critter ***array, int arrayLength, int arrayWidth) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] != nullptr) {
				array[i][j]->setAlreadyMoved(false);
			}
		}
	}
}
/*******************************************************************************
repeatMenu is a void function without parameters. It prompts the user
 to continue running the simulation on the same board or exit the current board.
*******************************************************************************/
void repeatRoundMenu() {
	//cout << "\nThe simulation has run for the number of timesteps you entered." << endl;
    cout << "Would you like to continue for more timesteps?" << endl;
	cout << "1. Enter more steps to run" << endl;
	cout << "2. Quit current simulation" << endl;
	cout << "Choose an option: ";
}
/*******************************************************************************
getChoice is a function that takes a min and max int parameter, and performs
input validation. It returns the int value of user input.
*******************************************************************************/
int getChoice(int minChoice, int maxChoice) {
	int input;
	cin >> input;

	// Try again if input is out of range or fails
	while (input < minChoice || input > maxChoice || cin.fail()) {
		if (maxChoice == minChoice) {
			cout << "Input must be " << maxChoice << ", ";
		}
		else {
			cout << "Input must be an integer between " << minChoice << " and " << maxChoice << ", ";
		}
		cout << "please retry input: ";
		cin.clear();
		cin.ignore(256, '\n');
		cin >> input;
	}

	// Flush buffer after successful input
	cin.clear();
	cin.ignore(256, '\n');

	return input;
}

/*******************************************************************************
repeatMenu is a void function without parameters. It prompts the user
 to continue to play again or exit the simulation.
*******************************************************************************/
void repeatMenu() {
	cout << "\n\n\n\nThank you for playing the Predator-Prey Simulation! " << endl;
	cout << "\n\tPLAY AGAIN? \n \n";
	cout << "1. Restart simulation" << endl;
	cout << "2. Quit" << endl;
	cout << "Choose an option: ";
}
