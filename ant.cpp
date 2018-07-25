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

void Ant::move(Critter ****Grid, int maxRows, int maxCols) { //This function should be called using someant.move(&Grid, rows, cols)
	//in order to loop through the array properly, the rows and cols should be passed along with the grid
	//assuming actual array index range is from 0 - maxRows-1, 0 - maxCols-1
	
	// 0 represents North; 1 East; 2 South; 3 West
	
	int direction = rand()%4;
	//direction = check_bounds(Grid, maxRows, maxCols);
	//cout << "this ran" << endl;
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
