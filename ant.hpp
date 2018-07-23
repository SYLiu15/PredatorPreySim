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

#include "critter.hpp"

class Ant : public Critter{
public:
	// Default constructor calls Critter default constructor
	Ant() : Critter() {};

	// 2-param constructor calls Critter 2-param constructor
	Ant(int rowIn, int colIn) : Critter(rowIn, colIn) {};

	void breed(Critter***);

};


#endif //GROUP_PROJECT_ANT_HPP
