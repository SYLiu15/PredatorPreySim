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
#include <vector>
#include <cstdlib>

using std::vector;

/*******************************************************************************
	TESTING   TESTING   TESTING   TESTING   TESTING   TESTING   TESTING
									Ant::breed
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Ant's stepsSinceBreeding count is >= 3.
*******************************************************************************/
void Ant::breed(Critter*** critterBoard)
{
	//Create a char vector to hold potential direction of move
	vector<char>  charVect;

	//If an ant has survived for 3 or more steps without breeding
	if (stepsSinceBreeding >= 3)
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
			//Call rand to randomly pick a cell to populate with new ant
			//Randomly selects a char from the vector and places a new ant
			//In that direction
			int choice = charVect[rand() % charVect.size()];

			//Ant breeds to the cell above
			if (choice == 'U')
			{
				critterBoard[row - 1][col] = new Ant(row - 1, col);
			}

			//Ant breeds to the cell to the right
			if (choice == 'R')
			{
				critterBoard[row][col + 1] = new Ant(row, col + 1);
			}

			//Ant breeds to the cell below
			if (choice == 'D')
			{
				critterBoard[row + 1][col] = new Ant(row + 1, col);
			}

			//Ant breeds to the cell to the left
			if (choice == 'L')
			{
				critterBoard[row][col - 1] = new Ant(row, col - 1);
			}

			//Reset stepsSinceBreeding to 0
			stepsSinceBreeding = 0;
		}

		//Otherwise there were no open spaces available 
		//and the ant doesn't breed
	}

	//Otherwise the ant can't breed
}