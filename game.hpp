/*******************************************************************************
* Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
* Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
* Date: July 18, 2018
* Description:
*
*
*
*******************************************************************************/

#include "grid.hpp"

class Game
{
private:
	Grid* critterBoard;
public:
	Game();
	~Game();
	void run_sim();
};
