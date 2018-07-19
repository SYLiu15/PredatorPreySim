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
#include <cstdlib> // Header file needed for random number generation

/*******************************************************************************
											Critter::Critter
Default constructor
*******************************************************************************/
Critter::Critter() {
	row = col = stepsSinceBreeding = 0;
}

/*******************************************************************************
											Critter::Critter

*******************************************************************************/
Critter::Critter(int rowIn, int colIn) {
	row = rowIn;
	col = colIn;
	stepsSinceBreeding = 0;
}

/*******************************************************************************
											Critter::getRow

*******************************************************************************/
int Critter::getRow() const {
	return row;
}

/*******************************************************************************
											Critter::getCol

*******************************************************************************/
int Critter::getCol() const {
	return col;
}

/*******************************************************************************
											Critter::setRow

*******************************************************************************/
void Critter::setRow(int rowIn) {
	row = rowIn;
}

/*******************************************************************************
											Critter::setCol

*******************************************************************************/
void Critter::setCol(int colIn) {
	col = colIn;
}

/*******************************************************************************
								Critter::getStepsSinceBreeding

*******************************************************************************/
int Critter::getStepsSinceBreeding() const {
	return stepsSinceBreeding;
}

/*******************************************************************************
											Critter::move
INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE INCOMPLETE
 Critter::move is a virtual function without parameters that returns a bool
 value. It attempts to randomly move a critter to a direction, and stays in
 place if that cell is occupied or if it would go off the grid. If it
 successfully moves, the function returns true. If not, it returns false. It
 should also increment the stepsSinceBreed variable at each move.
*******************************************************************************/
void Critter::move() {

	int direction = rand()/4;
	// 0 represents North; 1 East; 2 South; 3 West
	// If anyone wants to make this an enum, be my guest!

	// Need to somehow implement bounds checking + check if those squares on
			// the board are occupied yet (checking if it is empty with nullptr
					// or not)...having a hard time imagining how to access the
							// Grid class from here.

	// Should we make move() breed() and starve() friend functions to the Grid
			// class?

	switch(direction) {
		case 0:
			setRow(getRow() - 1); // Move one row up
		case 1:
			setCol(getCol() + 1); // Move one col to the right
		case 2:
			setRow(getRow() + 1); // Move one row down
		case 3:
			setCol(getCol() - 1); // Move one col to the left
	}


}