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

void print_board(Critter ***, int, int);
void reset_flags(Critter ***, int, int);
int getChoice(int, int);


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

	cout << "\nThe simulation will occur on a grid with user provided dimensions" << endl;
	cout << "The number of ants and doodlebugs will be provided by the user and the placement randomized" << endl;
	cout << "\nPlease enter the number of rows for the grid (min-2, max-50): ";
	int arrayLength = getChoice(2, 50);

	cout << "\nPlease enter the number of columns for the grid (min-2, max-50): ";
	int arrayWidth = getChoice(2, 50);
	
	//int arrayLength = 5, arrayWidth = 5;
	
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
	
	//run simulation, repeat until user types 'n'
	int value = 1;
	//print starting location
	print_board(array, arrayLength, arrayWidth);
	cout << "Press enter to continue: ";
	cin.ignore(256,'\n');
	
	//move doodlebugs first
	while (value == 1) {
		for (int i = 0; i < arrayLength; i++) {
			for (int j = 0; j < arrayWidth; j++) {
				if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'X') && (array[i][j]->getAlreadyMoved() == false)) {
					array[i][j]->move(array, arrayLength, arrayWidth);
				}
			}
		}

		//then move ants
		for (int i = 0; i < arrayLength; i++) {
			for (int j = 0; j < arrayWidth; j++) {
				if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'O') && (array[i][j]->getAlreadyMoved() == false)) {
					array[i][j]->move(array, arrayLength, arrayWidth);
				}
			}
		}
	
		//print board
		print_board(array, arrayLength, arrayWidth);
		
		//reset already_moved flags back to false after all moves made
		reset_flags(array, arrayLength, arrayWidth);
		
		//prompt for continue
		string input = "";
		cout << "Press enter to continue (q to quit): ";
		getline(cin, input);
		if (input == "q") {
			value = 0;
		}
	}
	
	//remove all data from memory
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			delete array[i][j];
		}
		delete [] array[i];
	}
	delete [] array;

	return 0;
	
}


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
	
	//initialize temp array
	int **intArray = new int*[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		intArray[i] = new int[arrayWidth];
		for (int j = 0; j < arrayWidth; j++) {
			intArray[i][j] = 0;
		}
	}
	
	while (ants > 0) {
		place_ants(array, arrayLength, arrayWidth);
		ants--;
	}
	while (doodle > 0) {
		place_doodlebugs(array, arrayLength, arrayWidth);
		doodle--;
	}
}

void place_ants(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col;
	do {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
	} while (array[row][col] != nullptr);
	
	array[row][col] = new Ant(row,col,0,false);
}

void place_doodlebugs(Critter ***array, int arrayLength, int arrayWidth) {
	int row, col;
	do {
		row = rand()%arrayLength;
		col = rand()%arrayWidth;
	} while (array[row][col] != nullptr);
	
	array[row][col] = new Doodlebug(row,col,0,false);
}


void print_board(Critter ***array, int arrayLength, int arrayWidth) {
	cout << endl;
	for (int i = 0; i < arrayWidth+2; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < arrayLength; i++) {
		cout << "|";
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] == nullptr) {
				cout << " ";
			}
			else {
				cout << array[i][j]->getStatus();
			}
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < arrayWidth+2; i++) {
		cout << "-";
	}
	cout << endl;
}

void reset_flags(Critter ***array, int arrayLength, int arrayWidth) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] != nullptr) {
				array[i][j]->setAlreadyMoved(false);
			}
		}
	}
}

int getChoice(int minChoice, int maxChoice) {
	int input;
	//cout << "Please enter your choice: ";
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