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
#include <cstdlib>
#include <vector>

using std::vector;

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
	TESTING   TESTING   TESTING   TESTING   TESTING   TESTING   TESTING
										Doodlebug::breed
Breed function overrides the Critter::breed pure virtual function. It is
called when the Doodlebug's stepsSinceBreeding count is >= 8. It takes a pointer 
to a pointer to a pointer to a critter as input. The function intializes a char 
vector that will hold chars to specify direction in which the doodlebugg breeds. 
The logic tests for empty adjacent cells above, below, to the right and left of 
the doodlebug, and adds U, D, R, and L chars to the vetor. The fucntion then 
rendomly chooses one of these chars and creates a new doodlebug object into the 
corrsponding cell. If there are no empty adjacent cells then nothing happens.
*******************************************************************************/
void Doodlebug::breed(Critter*** critterBoard)
{
	//Create a char vector to hold potential direction of move
	vector<char>  charVect;

	//If a doodlebug has survived for 8 or more steps without breeding
	if (stepsSinceBreeding >= 8)
	{
		//Loop to check each adjacent cell starting with up
		for (int i = 0; i < 4; i++)
		{
			//Checks adjacent cell above
			if (i == 0)
			{
				//If there isn't a pointer to a critter in the cell
				if (critterBoard[row - 1][col] == nullptr)
				{
					charVect.push_back('U');
				}
			}

			//Checks adjacent cell to the right
			if (i == 1)
			{
				//If there isn't a pointer to a critter in the cell
				if (critterBoard[row][col + 1] == nullptr)
				{
					charVect.push_back('R');
				}
			}

			//Checks adjacent cell below
			if (i == 2)
			{
				//If there isn't a pointer to a critter in the cell
				if (critterBoard[row + 1][col] == nullptr)
				{
					charVect.push_back('D');
				}
			}

			//Checks adjacent cell to the left
			if (i == 3)
			{
				//If there isn't a pointer to a critter in the cell
				if (critterBoard[row][col - 1] == nullptr)
				{
					charVect.push_back('L');
				}
			}
		}

		//If the vector has elements in it
		if (!charVect.empty())
		{
			//Call rand to randomly pick a cell to populate with new doodlebug
			//Randomly selects a char from the vector and places a new doodlebug
			//In that direction
			int choice = charVect[rand() % charVect.size()];

			//Ant breeds to the cell above
			if (choice == 'U')
			{
				critterBoard[row - 1][col] = new Doodlebug(row - 1, col);
			}

			//Ant breeds to the cell to the right
			if (choice == 'R')
			{
				critterBoard[row][col + 1] = new Doodlebug(row, col + 1);
			}

			//Ant breeds to the cell below
			if (choice == 'D')
			{
				critterBoard[row + 1][col] = new Doodlebug(row + 1, col);
			}

			//Ant breeds to the cell to the left
			if (choice == 'L')
			{
				critterBoard[row][col - 1] = new Doodlebug(row, col - 1);
			}

			//Reset stepsSinceBreeding to 0
			stepsSinceBreeding = 0;
		}

		//Otherwise there were no open spaces available 
		//and the doodlebug doesn't breed
	}

	//Otherwise the dooodlebug can't breed
}



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