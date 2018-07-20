///*******************************************************************************
// * Program: CS 162 Group Project: Predator-Prey Simulation - Group 13
// * Names: William Darnell, Suyang Liu, Paul Min, Brian Sprague, Angela Wen
// * Date: July 18, 2018
// * Description:
// *
// *
// *
//*******************************************************************************/
//
//#include "grid.hpp"
//
///*******************************************************************************
//	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
//									Grid::Grid
//Default constructor, no extra credit
//
//Should we also initialize the first ants/doodlebugs here?
//*******************************************************************************/
//Grid::Grid() {
//	totalRows = 20;
//	totalCols = 20;
//
//	// Could someone check my syntax for the initialization below?
//	critterGrid = new Critter** [totalRows];
//	for (int i = 0; i < totalRows; i++) {
//		critterGrid[i] = new Critter* [totalCols];
//	}
//
//	// Point all elements of critterGrid to nullptr
//	for (int i = 0; i < totalRows; i++) {
//		for (int j = 0; j < totalCols; j++) {
//			critterGrid[i][j] = nullptr;
//		}
//	}
//
//}
//
///*******************************************************************************
//									Grid::Grid
//Constructor that takes rows and cols param from user
//*******************************************************************************/
//Grid::Grid(int rowsIn, int colsIn) {
//	totalRows = rowsIn;
//	totalCols = colsIn;
//
//	// Could someone check my syntax for the initialization below?
//	critterGrid = new Critter** [totalRows];
//	for (int i = 0; i < totalRows; i++) {
//		critterGrid[i] = new Critter* [totalCols];
//	}
//
//	// Point all elements of critterGrid to nullptr
//	for (int i = 0; i < totalRows; i++) {
//		for (int j = 0; j < totalCols; j++) {
//			critterGrid[i][j] = nullptr;
//		}
//	}
//
//}
//
///*******************************************************************************
//	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
//									Grid::addAnt
//
//*******************************************************************************/
//void Grid::addAnt(int antRow, int antCol) {
//	if (antRow > 0 && antRow < totalRows && antCol > 0 && antCol < totalCols) {
//		critterGrid[antRow][antCol] = new Ant(antRow, antCol);
//	}
//}
//
///*******************************************************************************
//	INCOMPLETE 	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE	INCOMPLETE
//									Grid::addAnt
//
//*******************************************************************************/
//void Grid::addDoodlebug(int doodleRow, int doodleCol) {
//	if (doodleRow > 0 && doodleRow < totalRows && doodleCol > 0 && doodleCol <
//	                                                               totalCols) {
//		critterGrid[doodleRow][doodleCol] = new Ant(doodleRow, doodleCol);
//	}
//}
//
///*******************************************************************************
//									Grid::printGrid
//
//*******************************************************************************/
//void Grid::printGrid() const {
//
//	std::cout << "- ";
//	for (int i = 0; i < totalCols; i++) {
//		std::cout << "- ";
//	}
//	std::cout << "- " << std::endl;
//
//	// Iterate through grid
//	for (int i = 0; i < totalRows; i++) {
//		for (int j = 0; j < totalCols; j++) {
//			std::cout << "| ";
//
//			// If critter is an Ant, print 'O'
//			if (typeid(critterGrid[i][j]) == typeid(Ant *)) {
//				std::cout << "O ";
//			}
//
//			// Else if critter is a Doodlebug, print 'X'
//			else if (typeid(critterGrid[i][j]) == typeid(Doodlebug *)) {
//				std::cout << "X ";
//			}
//
//			// Else no critter, print blank
//			else {
//				std::cout << "  ";
//			}
//
//			std::cout << "|" << std::endl;
//
//		}
//	}
//
//	std::cout << "- ";
//	for (int i = 0; i < totalCols; i++) {
//		std::cout << "- ";
//	}
//	std::cout << "- " << std::endl;
//}
//
///*******************************************************************************
//									Grid::~Grid
//Destructor
//*******************************************************************************/
//Grid::~Grid() {
//	for (int i = 0; i < totalRows; i++) {
//		delete[] critterGrid[i];
//	}
//
//	delete[] critterGrid;
//}