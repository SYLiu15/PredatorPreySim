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
Default constructor
*******************************************************************************/
Critter::Critter() {
	row = col = stepsSinceBreeding = 0;
	delete_bug = false;
}

/*******************************************************************************
Non default constructor
*******************************************************************************/
Critter::Critter(int rowIn, int colIn, int steps) {
	row = rowIn;
	col = colIn;
	stepsSinceBreeding = steps;
	delete_bug = false;
}

/*******************************************************************************
Accessors
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
bool Critter::getDelete() const {
	return delete_bug;
}

/*******************************************************************************
Mutators
*******************************************************************************/
void Critter::setRow(int rowIn) {
	row = rowIn;
}
void Critter::setCol(int colIn) {
	col = colIn;
}
int Critter::setStepsSinceBreeding(int steps) {
	stepsSinceBreeding = steps;
}
void Critter::setDelete(bool d) {
	delete_bug = d;
}

/*******************************************************************************
Other functions
*******************************************************************************/
/*******************************************************************************
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
/*void Critter::move(Critter ***Grid, int maxRows, int maxCols) { //This function should be called using somecritter.move(&Grid, rows, cols)
	//in order to loop through the array properly, the rows and cols should be passed along with the grid
	//assuming actual array index range is from 0 - maxRows-1, 0 - maxCols-1
	
	//this can be virtual. The Ant version of this probably won't change, however the doodlebug version
	//should be biased for moving towards ants. move_up(), move_right(), move_down(), move_left() can
	//remain the same for all subclasses, can just be inherited.
	
	
	// 0 represents North; 1 East; 2 South; 3 West
	
	
	direction = check_bounds(Grid, maxRows, maxCols);
	
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
}

int Critter::check_bounds(Critter ***Grid, int maxRows, int maxCols) {
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
}
		
		
//separating each direction movement into separate functions will make it modular and reusable elsewhere
void Critter::move_up() {

}
void Critter::move_right() {

}
void Critter::move_down() {

}
void Critter::move_left() {

}*/
