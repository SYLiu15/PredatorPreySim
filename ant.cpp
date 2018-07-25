/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/
#include "ant.hpp"

void Ant::move(Critter ****Grid, int maxRows, int maxCols) {
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
	}
}

int Ant::check_bounds(Critter ****Grid, int maxRows, int maxCols) {
	bool up, down, left, right;
	//check if at top of board. If false, then check for empty space
	if (row != 0 && (*Grid)[row - 1][col] == nullptr) {
		up = true;
	}
	else {
		up = false;
	}
	//check if at bottom of board. If false, then check for empty space
	if (row != maxRows - 1 && (*Grid)[row + 1][col] == nullptr) {
		down = true;
	}
	else {
		down = false;
	}
	//check if at left of board. If false, then check for empty space
	if (col != 0 && (*Grid)[row][col - 1] == nullptr) {
		left = true;
	}
	else {
		left = false;
	}
	//check if at right of board. If false, then check for empty space
	if (col != maxCols - 1 && (*Grid)[row][col + 1] == nullptr) {
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

int Ant::condition_rand(bool up, bool right, bool down, bool left) {
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

void Ant::move_up(Critter ****Grid) {
	stepsSinceBreeding++;
	(*Grid)[row - 1][col] = new Ant(row - 1, col, stepsSinceBreeding, true);
	(*Grid)[row][col] = nullptr;
	delete this;
}
void Ant::move_right(Critter ****Grid) {
	stepsSinceBreeding++;
	(*Grid)[row][col + 1] = new Ant(row, col + 1, stepsSinceBreeding, true);
	(*Grid)[row][col] = nullptr;
	delete this;
}
void Ant::move_down(Critter ****Grid) {
	stepsSinceBreeding++;
	(*Grid)[row + 1][col] = new Ant(row + 1, col, stepsSinceBreeding, true);
	(*Grid)[row][col] = nullptr;
	delete this;
}
void Ant::move_left(Critter ****Grid) {
	stepsSinceBreeding++;
	(*Grid)[row][col - 1] = new Ant(row, col - 1, stepsSinceBreeding, true);
	(*Grid)[row][col] = nullptr;
	delete this;
}


/*******************************************************************************
	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
									Ant::breed
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Ant's stepsSinceBreeding count is >= 3.
*******************************************************************************/
