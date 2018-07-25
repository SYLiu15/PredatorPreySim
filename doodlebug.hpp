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
	Doodlebug(int rowIn, int colIn, int stpes, bool am); 

	void move(Critter ***, int , int) override;
	int check_ants(Critter ***Grid, int maxRows, int maxCols);

	void eat_up(Critter ***Grid);
	void eat_right(Critter ***Grid);
	void eat_down(Critter ***Grid);
	void eat_left(Critter ***Grid);

	void noEat_move(Critter ***Grid, int maxRows, int maxCols); 

	void move_up(Critter ***Grid) override;
	void move_right(Critter ***Grid) override;
	void move_down(Critter ***Grid) override;
	void move_left(Critter ***Grid) override;
		
	//void breed() override;

	//void starve();

	int getStepsSinceEating() const;

	// For printing on board
	char getStatus() const override {
		return 'X';
	}

};

#endif //DOODLEBUG_HPP
