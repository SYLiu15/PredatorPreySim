/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#ifndef CRITTER_HPP
#define CRITTER_HPP


class Critter {
protected:
	int row;
	int col;
	int stepsSinceBreeding;

public:
	Critter();
	Critter(int rowIn, int colIn);
	virtual bool move();

	virtual bool breed() = 0;

	int getRow() const;
	int getCol() const;
	void setRow(int rowIn);
	void setCol(int colIn);

	int getStepsSinceBreeding() const;

	virtual ~Critter() = default; // Default virtual constructor

};


#endif //CRITTER_HPP
