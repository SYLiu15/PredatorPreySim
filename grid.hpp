/*******************************************************************************
 * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
 * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
 * Date: July 18, 2018
 * Description:
 *
 *
 *
*******************************************************************************/

#ifndef GRID_HPP
#define GRID_HPP

#include "doodlebug.hpp"
#include "ant.hpp"

#include <iostream>
#include <typeinfo> // for typeid use

class Grid {
private:
	Critter ***critterGrid; // 2-D array of Critter pointers
	int totalRows;
	int totalCols;

public:
	Grid(); // Default constructor to make 20x20 array
	Grid(int rowsIn, int ColsIn); // Constructor for extra credit

	void addAnt(int antRow, int antCol);
	void addDoodlebug(int doodleRow, int doodleCol);

	bool checkBounds(); // IS THIS FUNCTION NECESSARY? ALREADY HAVE BOUNDS
	// CHECKING WITHIN THE addAnt/addDoodlebug function

	void printGrid() const;

	~Grid();


};


#endif //GROUP_PROJECT_GRID_HPP
