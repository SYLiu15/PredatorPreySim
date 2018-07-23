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
	bool delete_bug;

public:
	//constructors
	Critter();
	Critter(int, int);
	
	//accessors
	int getRow() const;
	int getCol() const;
	int getStepsSinceBreeding() const;
	bool getDelete() const;
	
	//mutators
	void setRow(int);
	void setCol(int);
	void setDelete(bool);
	
	//other functions
	virtual void move() = 0;
	virtual void breed() = 0; //this needed?
	virtual void starve() = 0; //this needed? Rubric seems to suggest it is

	
	//what is this?
	virtual ~Critter() = default; // Default virtual constructor

};


#endif //CRITTER_HPP
