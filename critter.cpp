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
	already_moved = false;
}

/*******************************************************************************
Non default constructor
*******************************************************************************/
Critter::Critter(int rowIn, int colIn, int steps, bool am) {
	row = rowIn;
	col = colIn;
	stepsSinceBreeding = steps;
	already_moved = am;
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
bool Critter::getAlreadyMoved() const {
	return already_moved;
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
void Critter::setAlreadyMoved(bool am) {
	already_moved = am;
}