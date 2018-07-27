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

/*******************************************************************************
** Increments stepsSinceBreeding. Copies data to new space directly above.
** Sets original pointer to nullptr. Deletes itself.
*******************************************************************************/
void Ant::move_up(Critter ***Grid) {
	stepsSinceBreeding++;
	Grid[row - 1][col] = new Ant(row - 1, col, stepsSinceBreeding, true);
	Grid[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
** Increments stepsSinceBreeding. Copies data to new space directly right.
** Sets original pointer to nullptr. Deletes itself.
*******************************************************************************/
void Ant::move_right(Critter ***Grid) {
	stepsSinceBreeding++;
	Grid[row][col + 1] = new Ant(row, col + 1, stepsSinceBreeding, true);
	Grid[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
** Increments stepsSinceBreeding. Copies data to new space directly below.
** Sets original pointer to nullptr. Deletes itself.
*******************************************************************************/
void Ant::move_down(Critter ***Grid) {
	stepsSinceBreeding++;
	Grid[row + 1][col] = new Ant(row + 1, col, stepsSinceBreeding, true);
	Grid[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
** Increments stepsSinceBreeding. Copies data to new space directly left.
** Sets original pointer to nullptr. Deletes itself.
*******************************************************************************/
void Ant::move_left(Critter ***Grid) {
	stepsSinceBreeding++;
	Grid[row][col - 1] = new Ant(row, col - 1, stepsSinceBreeding, true);
	Grid[row][col] = nullptr;
	delete this;
}

/*******************************************************************************
       				 Ant::breed
Breed function overrides the Critter::breed pure virtual function. It is
 called when the Ant's stepsSinceBreeding count is >= 3.
*******************************************************************************/
void Ant::breed(Critter ***Grid, int maxRows, int maxCols)
{
  int choice = check_bounds(Grid, maxRows, maxCols);
 
  switch (choice)
  {
  case 0:
    Grid[row - 1][col] = new Ant(row - 1, col, 0, true);
    stepsSinceBreeding = 0;
    break;
  case 1:
    Grid[row][col + 1] = new Ant(row, col + 1, 0, true);
  stepsSinceBreeding = 0;
      break;
  case 2:
    Grid[row + 1][col] = new Ant(row + 1, col, 0, true);
    stepsSinceBreeding = 0;
    break;
  case 3:
    Grid[row][col - 1] = new Ant(row, col - 1, 0, true);
    stepsSinceBreeding = 0;
    break;
  }
}

