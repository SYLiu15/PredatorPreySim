/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#include "critter.hpp"

/*******************************************************************************
** Default constructor
*******************************************************************************/
Critter::Critter() {
	row = col = stepsSinceBreeding = 0;
	already_moved = false;
}

/*******************************************************************************
** Non default constructor
*******************************************************************************/
Critter::Critter(int rowIn, int colIn, int steps, bool am) {
	row = rowIn;
	col = colIn;
	stepsSinceBreeding = steps;
	already_moved = am;
}

/*******************************************************************************
** Accessors
*******************************************************************************/
int Critter::getRow() const {
	return row;
}
int Critter::getCol() const {
	return col;
}
int Critter::getStepsSinceBreeding() const {
	return stepsSinceBreeding;
}
bool Critter::getAlreadyMoved() const {
	return already_moved;
}

/*******************************************************************************
** Mutators
*******************************************************************************/
void Critter::setRow(int rowIn) {
	row = rowIn;
}
void Critter::setCol(int colIn) {
	col = colIn;
}
void Critter::setAlreadyMoved(bool am) {
	already_moved = am;
}

/*******************************************************************************
** Other functions
*******************************************************************************/
/*******************************************************************************
** Critter::move() checks boundary conditions for objects and boundaries using
** check_bounds(). The returned number from check_bounds() is used to select
** a single direction move function. Individual move functions are pure virtual
** and specified within derived classes.
** 
** This function should be called using someobj.move(Grid, maxRows, maxCols),
** where Grid is a Critter ***Grid. 
** 
** Board length is maxRows, width is maxCols.
** Array index range is from 0 - maxRows-1, 0 - maxCols-1.
** 
** Directions:
** 0 Up; 1 Right; 2 Down; 3 Left
*******************************************************************************/
void Critter::move(Critter ***Grid, int maxRows, int maxCols) {
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
	}
}

/*******************************************************************************
** indicates whether up, down, left, right has an available move. Checks for
** board boundaries and presence of any object. Does not differentiate between
** objects.
** Calls condition_rand() to randomize a number depending on the directions
** available.
*******************************************************************************/
int Critter::check_bounds(Critter ***Grid, int maxRows, int maxCols) {
	bool up, down, left, right;
	//check if at top of board. If false, then check for empty space
	if (row != 0 && Grid[row - 1][col] == nullptr) {
		up = true;
	}
	else {
		up = false;
	}
	//check if at bottom of board. If false, then check for empty space
	if (row != maxRows - 1 && Grid[row + 1][col] == nullptr) {
		down = true;
	}
	else {
		down = false;
	}
	//check if at left of board. If false, then check for empty space
	if (col != 0 && Grid[row][col - 1] == nullptr) {
		left = true;
	}
	else {
		left = false;
	}
	//check if at right of board. If false, then check for empty space
	if (col != maxCols - 1 && Grid[row][col + 1] == nullptr) {
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

/*******************************************************************************
** Given a bool for up, down, left, right, randomizes a number and checks to see
** if that direction has an available move. If yes, return that number. If no,
** call the function again using recursion. Repeat until conditions are met.
** 
** If all directions are false, the function will never finish. That condition
** must be checked for before the running this function.
*******************************************************************************/
int Critter::condition_rand(bool up, bool right, bool down, bool left) {
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