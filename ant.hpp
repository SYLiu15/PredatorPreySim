/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#ifndef ANT_HPP
#define ANT_HPP

#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include <cstdlib>

#include "critter.hpp"

class Ant : public Critter{
public:
	// Default constructor
	Ant() : Critter() {};

	// Non default constructor
	Ant(int rowIn, int colIn, int steps, bool am) : Critter(rowIn, colIn, steps, am) {};
	
	//other functions
	//move functions called using inherited move() from Critter;
	virtual void move_up(Critter ***Grid);
	virtual void move_right(Critter ***Grid);
	virtual void move_down(Critter ***Grid);
	virtual void move_left(Critter ***Grid);

	char getStatus() const override {
		return 'O';
	}
	
	virtual void breed();
};


#endif //GROUP_PROJECT_ANT_HPP
