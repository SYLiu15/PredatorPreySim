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
4-parameter constructor, calls Critter 4-parameter constructor and initializes
 steps since eating to 0
*******************************************************************************/
Doodlebug::Doodlebug(int rowIn, int colIn, int steps, bool am) : Critter(rowIn, colIn, steps, am) {
	stepsSinceEating = 0;
}

/*******************************************************************************
				Doodlebug::Doodlebug
5-parameter constructor, calls Critter 4-parameter constructor and assigns steps
 since eating to the value passed as argument.
*******************************************************************************/
Doodlebug::Doodlebug(int rowIn, int colIn, int stepsB, int stepsEat, bool am) : Critter(rowIn, colIn, stepsB, am) {
    stepsSinceEating = stepsEat;
}

/*******************************************************************************
				Doodlebug::move
Move function tries to have the Doodlebug eat any adjacent ants. It is a void
function that takes parameters of the critter Grid, the int rows and columns of the 
Grid. First it determines if there are any adjacent ants with the check_ants 
method. If there are, it calls the appropriate eat functions. If there are not,
it calls the noEat_move function.
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

/*******************************************************************************
				Doodlebug::check_ant
check_ant is a method that also takes the Grid array, and the two int parameters
of the rows and columns of the grid. It is similar to the check_bounds function,
except instead of checking for a nullptr, it checks for an Ant pointer in
adjacent locations. If it finds one, it calls the Critter::condition_rand
function to choose a direction and return it. If not, it returns 4.
 *******************************************************************************/
int Doodlebug::check_ants(Critter ***Grid, int maxRows, int maxCols) {
	bool up, down, left, right;
	//check if at top of board. If false, then check if ant is present
	if (row != 0 && Grid[row - 1][col] != nullptr && Grid[row - 1][col]->getStatus() == 'O') {
		up = true;
	}
	else {
		up = false;
	}
	//check if at bottom of board. If false, then check if ant is present
	if ((Grid[row][col] != nullptr) && row != maxRows - 1 && Grid[row][col]->getStatus() == 'O') {
		down = true;
	}
	else {
		down = false;
	}
	//check if at left of board. If false, then check if ant is present
	if ((Grid[row][col - 1] != nullptr) && col != 0 && Grid[row][col - 1]->getStatus() == 'O') {
		left = true;
	}
	else {

		left = false;
	}
	//check if at right of board. If false, then check if ant is present
	if ((Grid[row][col + 1] != nullptr) && col != maxCols - 1 && Grid[row][col + 1]->getStatus() == 'O') {
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
		int direction = Critter::condition_rand(up, right, down, left);
		return direction;
	}

}


/*******************************************************************************
				Doodlebug::eat_up
Doodlebug::eat_up is almost identical to the Doodlebug::move_up function,
except it must also delete the Ant pointer that it is "eating" before moving. It
is a void function that takes the parameter of the grid.
*******************************************************************************/
void Doodlebug::eat_up(Critter ***Grid) {
	stepsSinceBreeding++;
	stepsSinceEating = 0;
	delete Grid[row - 1][col];
	(Grid)[row - 1][col] = new Doodlebug(row - 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}
	
/*******************************************************************************
				Doodlebug::eat_right
Doodlebug::eat_right is almost identical to the Doodlebug::move_right function,
except it must also delete the Ant pointer that it is "eating" before moving. It
is a void function that takes the parameter of the grid.
*******************************************************************************/
void Doodlebug::eat_right(Critter ***Grid) {
	stepsSinceBreeding++;
	stepsSinceEating = 0;	
	delete Grid[row][col + 1];
	(Grid)[row][col + 1] = new Doodlebug(row, col + 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::eat_down
Doodlebug::eat_down is almost identical to the Doodlebug::move_down function,
except it must also delete the Ant pointer that it is "eating" before moving. It
is a void function that takes the parameter of the grid.
*******************************************************************************/
void Doodlebug::eat_down(Critter ***Grid) {
	stepsSinceBreeding++;
	stepsSinceEating = 0;	
	delete Grid[row + 1][col];
	(Grid)[row + 1][col] = new Doodlebug(row + 1, col, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::eat_left
Doodlebug::eat_left is almost identical to the Doodlebug::move_left function,
except it must also delete the Ant pointer that it is "eating" before moving. It
is a void function that takes the parameter of the grid.
*******************************************************************************/
void Doodlebug::eat_left(Critter ***Grid) {
	stepsSinceBreeding++;
	stepsSinceEating = 0;	
	delete Grid[row][col - 1];
	(Grid)[row][col - 1] = new Doodlebug(row, col - 1, stepsSinceBreeding, true);
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::noEat_move
Doodlebug::noEat_move is a void function that is called if there are no adjacent
Ants. It takes the parameters of the Grid, and the int values of rows and cols.
It calls the Critter::move function and depending on the random direction,
will then call the overridden functions of move_up, move_right, move_down, or
move_left.
*******************************************************************************/
void Doodlebug::noEat_move(Critter ***Grid, int maxRows, int maxCols) {
    stepsSinceEating++;
    stepsSinceBreeding++;
    Critter::move(Grid, maxRows, maxCols);
}


/*******************************************************************************
				Doodlebug::move_up
Doodlebug::move_up is a void function that takes the parameter of the grid. It 
increments the steps since breeding variable, adds a new Doodlebug to the new
location, and removes the old one.
*******************************************************************************/
void Doodlebug::move_up(Critter ***Grid) {
	//stepsSinceBreeding++;
	(Grid)[row - 1][col] = new Doodlebug(row - 1, col, stepsSinceBreeding, stepsSinceEating, true);
	if(dynamic_cast<Doodlebug *>((Grid)[row-1][col])->getStepsSinceEating() >= 3){
		(Grid)[row-1][col]->starve(Grid);
	}
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::move_right
Doodlebug::move_right is a void function that takes the parameter of the grid. It 
increments the steps since breeding variable, adds a new Doodlebug to the new
location, and removes the old one.
*******************************************************************************/
void Doodlebug::move_right(Critter ***Grid) {
	//stepsSinceBreeding++;
	(Grid)[row][col + 1] = new Doodlebug(row, col + 1, stepsSinceBreeding, stepsSinceEating, true);
	if(dynamic_cast<Doodlebug *>((Grid)[row][col+1])->getStepsSinceEating() >= 3){
		(Grid)[row][col+1]->starve(Grid);
	}
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::move_down
Doodlebug::move_down is a void function that takes the parameter of the grid. It 
increments the steps since breeding variable, adds a new Doodlebug to the new
location, and removes the old one.
*******************************************************************************/
void Doodlebug::move_down(Critter ***Grid) {
	//stepsSinceBreeding++;
	(Grid)[row + 1][col] = new Doodlebug(row + 1, col, stepsSinceBreeding, stepsSinceEating, true);
	if(dynamic_cast<Doodlebug *>((Grid)[row+1][col])->getStepsSinceEating() >= 3){
		(Grid)[row+1][col]->starve(Grid);
	}
	(Grid)[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
				Doodlebug::move_left
Doodlebug::move_left is a void function that takes the parameter of the grid. It 
increments the steps since breeding variable, adds a new Doodlebug to the new
location, and removes the old one.
*******************************************************************************/
void Doodlebug::move_left(Critter ***Grid) {
	//stepsSinceBreeding++;
	(Grid)[row][col - 1] = new Doodlebug(row, col - 1, stepsSinceBreeding, stepsSinceEating, true);
	if(dynamic_cast<Doodlebug *>((Grid)[row][col - 1])->getStepsSinceEating() >= 3){
		(Grid)[row][col - 1]->starve(Grid);
	}
	(Grid)[row][col] = nullptr;
	delete this;
}


/*******************************************************************************
				Doodlebug::breed
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Doodlebug's stepsSinceBreeding count is >= 8. The function
 chooses a random adjacent spot to breed a new Doodlebug to. If it is
 occupied, it should look for another. If all spaces are occupied, no breed
 occurs. The bool function returns true if the Doodlebug breeds, and sets the
 stepsSinceBreed variable to 0. It returns false if the Doodlebug is unable
 to breed.
*******************************************************************************/
void Doodlebug::breed(Critter*** Grid, int maxRows, int maxCols)  
{  
    int choice = check_bounds(Grid, maxRows, maxCols);  
  
    switch (choice)  
    {  
    case 0:  
      Grid[row - 1][col] = new Doodlebug(row - 1, col, 0, true);  
      stepsSinceBreeding = 0;  
      break;  
    case 1:  
      Grid[row][col + 1] = new Doodlebug(row, col + 1, 0, true);  
      stepsSinceBreeding = 0;  
      break;  
    case 2:  
      Grid[row + 1][col] = new Doodlebug(row + 1, col, 0, true);  
      stepsSinceBreeding = 0;  
      break;  
    case 3:  
      Grid[row][col - 1] = new Doodlebug(row, col - 1, 0, true);  
      stepsSinceBreeding = 0;  
      break; 
    } 
} 

/*******************************************************************************
				Doodlebug::starve
  Starve function sets the element that was occupied by the starved doodlebug to
  nullptr. The function has one parameter which is a triple pointer to a Critter
  object.
*******************************************************************************/
void Doodlebug::starve(Critter ***Grid) {
    int col = this->getCol();
    int row = this->getRow();
    (Grid)[row][col] = nullptr;
    delete this;
}

/*******************************************************************************
			Doodlebug::getStepsSinceEating
Doodlebug::getStepsSinceEating is a function without parameters that returns the
int value of the stepsSinceEating member variable. 
*******************************************************************************/
int Doodlebug::getStepsSinceEating() const {
	return stepsSinceEating;
}
