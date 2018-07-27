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

#include <cstdlib>

class Critter {
protected:
	int row;
	int col;
	int stepsSinceBreeding;
	bool already_moved;

public:
	//constructors
	Critter();
	Critter(int, int, int, bool);
	
	//accessors
	int getRow() const;
	int getCol() const;
	int getStepsSinceBreeding() const;
	bool getAlreadyMoved() const;
	
	//mutators
	void setRow(int);
	void setCol(int);
	void setAlreadyMoved(bool am);
	
	//other functions
	virtual void move(Critter ***, int, int);
	
	int check_bounds(Critter ***Grid, int maxRows, int maxCols);
	int condition_rand(bool up, bool right, bool down, bool left);
	
	virtual void move_up(Critter ***Grid) = 0;
	virtual void move_right(Critter ***Grid) = 0;
	virtual void move_down(Critter ***Grid) = 0;
	virtual void move_left(Critter ***Grid) = 0;

	virtual char getStatus() const = 0; // Flag for distinguishing pointers
	
	//virtual void breed() = 0;
	virtual void starve(Critter*** Grid){};
	
	virtual ~Critter() = default; // Default virtual destructor

};


#endif //CRITTER_HPP
