/*******************************************************************************
* Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
* Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
* Date: July 18, 2018
* Description:
*
*
*
*******************************************************************************/

#include "game.hpp"

Game::Game()
{
	critterBoard = new Grid();
}

Game::~Game()
{
	delete critterBoard;
	critterBoard = nullptr;
}

void Game::run_sim()
{
	//Ask user for number of steps to simulate

	//While loop to run the game loop

		//Print the board

		//Move doodlebugs

		//Move ants

		//Starve doodlebugs

		//Breed doodlebugs

	//Ask user if they want to run the simulation again
}
