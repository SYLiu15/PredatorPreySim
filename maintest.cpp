#include <iostream>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <typeinfo>

#include "ant.hpp"
#include "critter.hpp"
#include "doodlebug.hpp"

void print_board(Critter ***array, int arrayLength, int arrayWidth);
void reset_flags(Critter ***array, int arrayLength, int arrayWidth);


int main() {
	srand(time(NULL));

	int arrayLength = 5, arrayWidth = 5;

	//initialize array of Critter pointers
	Critter ***array = new Critter**[arrayLength];
	for (int i = 0; i < arrayLength; i++) {
		array[i] = new Critter*[arrayWidth];
		for (int j = 0; j < arrayWidth; j++) {
			array[i][j] = nullptr;
		}
	}

	//create single ant
	array[2][2] = new Ant(2, 2, 3, false);
	array[2][1] = new Ant(2, 1, 0, false);
	array[2][3] = new Ant(2, 3, 0, false);
	//array[0][2] = new Ant(0, 2, 0, false);
	//array[2][0] = new Ant(2, 0, 0, false);

	//create new doodlebug
	//array[2][2] = new Doodlebug(2, 2, 8, false);

	//run simulation, repeat until user types 'n'
	int value = 1;
	//print starting location
	print_board(array, arrayLength, arrayWidth);
	cout << "Press enter to continue: ";
	cin.ignore(256, '\n');
	int steps = 10;


	//breed ants
	while (value == 1) {
		//for (int i = 0; i < steps; i++)
		//{
		//	for (int i = 0; i < arrayLength; i++)
		//	{
		//		for (int j = 0; j < arrayWidth; j++)
		//		{
		//			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'X') && (array[i][j]->getAlreadyMoved() == false))
		//			{
		//				array[i][j]->move(array, arrayLength, arrayWidth);
		//				array[i][j]->breed(array, arrayLength, arrayWidth);
		//			}
		//		}
		//	}


		//	//then move ants
		//	for (int i = 0; i < arrayLength; i++)
		//	{
		//		for (int j = 0; j < arrayWidth; j++)
		//		{
		//			if ((array[i][j] != nullptr) && (array[i][j]->getStatus() == 'O') && (array[i][j]->getAlreadyMoved() == false))
		//			{
		//				array[i][j]->move(array, arrayLength, arrayWidth);
		//				array[i][j]->breed(array, arrayLength, arrayWidth);
		//			}
		//		}
		//	}

		//	//print board
		//	print_board(array, arrayLength, arrayWidth);
		//}
		//reset already_moved flags back to false after all moves made
		array[2][2]->breed(array, arrayLength, arrayWidth);
		print_board(array, arrayLength, arrayWidth);
		reset_flags(array, arrayLength, arrayWidth);

		//prompt for continue
		string input = "";
		cout << "Press enter to continue (q to quit): ";
		getline(cin, input);
		if (input == "q")
		{
			value = 0;
		}


		//remove all data from memory
		for (int i = 0; i < arrayLength; i++)
		{
			for (int j = 0; j < arrayWidth; j++)
			{
				delete array[i][j];
			}

			delete[] array[i];
		}

		delete[] array;

		return 0;
	}
}

void print_board(Critter ***array, int arrayLength, int arrayWidth) {
	cout << endl;
	for (int i = 0; i < arrayLength+2; i++) {
		cout << "-";
	}
	cout << endl;
	for (int i = 0; i < arrayLength; i++) {
		cout << "|";
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] == nullptr) {
				cout << " ";
			}
			else {
				cout << array[i][j]->getStatus();
			}
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < arrayLength+2; i++) {
		cout << "-";
	}
	cout << endl;
}

void reset_flags(Critter ***array, int arrayLength, int arrayWidth) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if (array[i][j] != nullptr) {
				array[i][j]->setAlreadyMoved(false);
			}
		}
	}
}
