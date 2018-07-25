/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#include "doodlebug.hpp"

/*******************************************************************************
										Doodlebug::Doodlebug
Default constructor, calls Critter default constructor and initializes steps
 since eating to 0
*******************************************************************************/
Doodlebug::Doodlebug() : Critter() {
	stepsSinceEating = 0;
}

/*******************************************************************************
										Doodlebug::Doodlebug
2-parameter constructor, calls Critter 2-parameter constructor and initializes
 steps since eating to 0
*******************************************************************************/
Doodlebug::Doodlebug(int rowIn, int colIn) : Critter(rowIn, colIn) {
	stepsSinceEating = 0;
}

/*******************************************************************************
	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
										Doodlebug::move
Move function tries to have the Doodlebug eat any adjacent ants. If there are
 no adjacent ants, call the Critter::move method. This method is called at
 the beginning of each 'time step'
*******************************************************************************/
void Doodlebug::move(Critter ***Grid, int maxRows, int maxCols) {
	//This function should be called using somedoodlebug.move(&Grid, maxRows, maxCols)
	//array index range is from 0 - maxRows-1, 0 - maxCols-1

	//Directions:
	//0 Up; 1 Right; 2 Down; 3 Left
	
	//this function checks to see if ants are on adjacent grid elements
	//it selects a direction based on board conditions
	int direction = check_ants(Grid, maxRows, maxCols);
	
	switch(direction) {
		case 0:
			eat_up(Grid);
			break;
		case 1:
			eat_right(Grid);
			break;
		case 2:
			eat_down(Grid);
			break;
		case 3:
			eat_left(Grid);
			break;
		default:
			noEat_move(Grid, maxRows, maxCols); 
			break;	
	}
}

// This function is similar to the check_bounds method, except instead of checking for a nullptr, it checks for an Ant pointer in adjacent locations.

int Doodlebug::check_ant(Critter ***Grid, int maxRows, int maxCols) {
	bool up, down, left, right;
	//check if at top of board. If false, then check if ant is present
	if (row != 0 && (Grid)[row - 1][col]->getStatus() == 'o') {
		up = true;
	}
	else {
		up = false;
	}
	//check if at bottom of board. If false, then check if ant is present
	if (row != maxRows - 1 && (Grid)[row + 1][col]->getStatus() == 'o') {
		down = true;
	}
	else {
		down = false;
	}
	//check if at left of board. If false, then check if ant is present
	if (col != 0 && (Grid)[row][col - 1]->getStatus() == 'o') {
		left = true;
	}
	else {
		left = false;
	}
	//check if at right of board. If false, then check if ant is present
	if (col != maxCols - 1 && (Grid)[row][col + 1]->getStatus() == 'o') {
		right = true;
	}
	else {
		right = false;
	}
	
	//based on which directions are available, generate a random number
	//if no options are available, return a value where no case exists (no ants are nearby)
	if (up == false && right == false && down == false && left == false) {
		return 4;
	}
	else {
		int direction = condition_rand(up, right, down, left);
		return direction;
	}

}

// The same as the Ant counterpart. This function could be implemented in Critter.
int Doodlebug::condition_rand(bool up, bool right, bool down, bool left) {
	int value = rand()%4;
	
	//verify that the random number is an available movement
	if (value == 0 && up == true) {
		return value;
	}
	else if (value == 1 && right == true) {
		return value;
	}
	else if (value == 2 && down == true) {
		return value;
	}
	else if (value == 3 && left == true) {
		return value;
	}
	else {
		//if random number is not an available movement, use recursion to generate a new random number until
		//condition is met
		return condition_rand(up, right, down, left);
	}
}

// These functions are almost identical to Doodlebug::move_up, etc, except they must delete the Ant pointer that they are "eating" before moving. 

void Doodlebug::eat_up(Critter ***Grid) {
	stepsSinceBreeding++;
	delete Grid[row - 1][col];
	(Grid)[row - 1][col] = new Doodlebug(row - 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;

void Doodlebug::eat_right(Critter ***Grid) {
	stepsSinceBreeding++;
	delete Grid[row][col + 1];
	(Grid)[row][col + 1] = new Doodlebug(row, col + 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}
void Doodlebug::eat_down(Critter ***Grid) {
	stepsSinceBreeding++;
	delete Grid[row + 1][col];
	(Grid)[row + 1][col] = new Doodlebug(row + 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}
void Doodlebug::eat_left(Critter ***Grid) {
	stepsSinceBreeding++;
	delete Grid[row][col - 1];
	(Grid)[row][col - 1] = new Doodlebug(row, col - 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}

void Doodlebug::noEat_move(Critter ***Grid, int maxRows, int maxCols) {
	// This part is the same as Ant::move
	
	//This function should be called using someant.move(&Grid, maxRows, maxCols)
	//array index range is from 0 - maxRows-1, 0 - maxCols-1
	
	//Directions:
	//0 Up; 1 Right; 2 Down; 3 Left
	
	//this function selects a direction based on board conditions
	int direction = check_bounds(Grid, maxRows, maxCols);
	
	switch(direction) {
		case 0:
			move_up(Grid);
			break;
		case 1:
			move_right(Grid);
			break;
		case 2:
			move_down(Grid);
			break;
		case 3:
			move_left(Grid);
			break;
		default:
			break;
	}
}


// The same as the Ant counterpart. This function could be implemented in Critter.
int Doodlebug::check_bounds(Critter ***Grid, int maxRows, int maxCols) {
	bool up, down, left, right;
	//check if at top of board. If false, then check for empty space
	if (row != 0 && (Grid)[row - 1][col] == nullptr) {
		up = true;
	}
	else {
		up = false;
	}
	//check if at bottom of board. If false, then check for empty space
	if (row != maxRows - 1 && (Grid)[row + 1][col] == nullptr) {
		down = true;
	}
	else {
		down = false;
	}
	//check if at left of board. If false, then check for empty space
	if (col != 0 && (Grid)[row][col - 1] == nullptr) {
		left = true;
	}
	else {
		left = false;
	}
	//check if at right of board. If false, then check for empty space
	if (col != maxCols - 1 && (Grid)[row][col + 1] == nullptr) {
		right = true;
	}
	else {
		right = false;
	}
	
	//based on which directions are available, generate a random number
	//if no options are available, return a value where no case exists (ant does nothing)
	if (up == false && right == false && down == false && left == false) {
		return 4;
	}
	else {
		int direction = condition_rand(up, right, down, left);
		return direction;
	}
}

// These are the same as the Ant counterparts, but they place new Doodlebugs

void Doodlebug::move_up(Critter ***Grid) {
	stepsSinceBreeding++;
	(Grid)[row - 1][col] = new Doodlebug(row - 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;

void Doodlebug::move_right(Critter ***Grid) {
	stepsSinceBreeding++;
	(Grid)[row][col + 1] = new Doodlebug(row, col + 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}
void Doodlebug::move_down(Critter ***Grid) {
	stepsSinceBreeding++;
	(Grid)[row + 1][col] = new Doodlebug(row + 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}
void Doodlebug::move_left(Critter ***Grid) {
	stepsSinceBreeding++;
	(Grid)[row][col - 1] = new Doodlebug(row, col - 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}




/*******************************************************************************
	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
										Doodlebug::breed
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Doodlebug's stepsSinceBreeding count is >= 8. The function
 chooses a random adjacent spot to breed a new Doodlebug to. If it is
 occupied, it should look for another. If all spaces are occupied, no breed
 occurs. The bool function returns true if the Doodlebug breeds, and sets the
 stepsSinceBreed variable to 0. It returns false if the Doodlebug is unable
 to breed.
*******************************************************************************/

/*******************************************************************************
	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
										Doodlebug::starve
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Doodlebug::stepsSinceEating variable is >= 3. It removes the
 Doodlebug from the grid by setting the grid location to nullptr. It returns
 true if completed.
*******************************************************************************/
void Doodlebug::starve() {

}
/*******************************************************************************
										Doodlebug::getStepsSinceEating

*******************************************************************************/
int Doodlebug::getStepsSinceEating() const {
	return stepsSinceEating;
}
