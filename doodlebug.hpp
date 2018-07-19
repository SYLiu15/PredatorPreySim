/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#ifndef DOODLEBUG_HPP
#define DOODLEBUG_HPP

#include "critter.hpp"

class Doodlebug : public Critter {
private:
	int stepsSinceEating;

public:
	Doodlebug(); // Default constructor
	Doodlebug(int rowIn, int colIn); // 2-param constructor

	void move() override;
	void breed() override;

	void starve();

	int getStepsSinceEating() const;

};


#endif //GROUP_PROJECT_DOODLEBUG_HPP
