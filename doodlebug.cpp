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

/*******************************************************************************
										Doodlebug::getStepsSinceEating

*******************************************************************************/
int Doodlebug::getStepsSinceEating() const {
	return stepsSinceEating;
}