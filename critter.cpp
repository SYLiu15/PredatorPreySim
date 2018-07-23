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
/*******************************************************************************
** Suyang updated this
*******************************************************************************/
void Critter::move(Critter ***Grid, int maxRows, int maxCols) { //This function should be called using somecritter.move(&Grid, rows, cols)
	//in order to loop through the array properly, the rows and cols should be passed along with the grid
	
	int direction = rand()/4;
	// 0 represents North; 1 East; 2 South; 3 West
	// If anyone wants to make this an enum, be my guest!

	// Need to somehow implement bounds checking + check if those squares on
			// the board are occupied yet (checking if it is empty with nullptr
					// or not)...having a hard time imagining how to access the
							// Grid class from here.

	// Should we make move() breed() and starve() friend functions to the Grid
			// class?
	
	
	//LOGIC FOR BOUNDS CHECKING
	//given getRow() and getCol(), check if:
		//row = maxRows
		//row = 0
		//col = maxCols
		//col = 0
	//if any are true, the case is a boundary condition, respective move is not allowed
	
	//LOGIC FOR CRITTER CHECKING
	//given getRow() and getCol(), check if:
		//row + 1 is occupied
		//row - 1 is occupied
		//col + 1 is occupied
		//col - 1 is occupied
	//if any are true, the critter cannot move in those directions
	
	//I will work on bounds checking again tomorrow, I have ideas but not enough time today. Anyone else is free to add more to this.
	
	//AFTER checking these, select a direction to move
	//each individual direction move should be separated into a function
	void Critter::move() { //this can be virtual. The Ant version of this probably won't change, however the doodlebug version
				//should be biased for moving towards ants. move_up(), move_right(), move_down(), move_left() can
				//remain the same for all subclasses, can just be inherited.
		switch(direction) {
			case 0:
				move_up();
				break;
			case 1:
				move_right();
				break;
			case 2:
				move_down();
				break;
			case 3:
				move_left();
				break;
		}
	} //NO PROTOTYPE, WON'T COMPILE
	
	//separating each direction movement into separate functions will make it modular and reusable elsewhere
	void Critter::move_up() {
		
	}
	void Critter::move_right() {
		
	}
	void Critter::move_down() {
		
	}
	void Critter::move_left() {
		
	}
	
	
	//remove this?
	/*
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
	*/


}
