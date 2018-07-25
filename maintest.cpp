#include <iostream>
using std::cout;
using std::cin;
using std::endl;
#include <string>
using std::string;
#include <typeinfo>

#include "ant.hpp"
#include "critter.hpp"

void print_board(Critter ***);
void print_board(Critter ***array, int arrayLength, int arrayWidth);
void reset_flags(Critter ****array, int arrayLength, int arrayWidth);


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
	array[2][2] = new Ant(2,2,0,false);
	
	//run simulation, repeat until user types 'n'
	int value = 1;
	//print starting location
	print_board(array, arrayLength, arrayWidth);
	cout << "Press enter to continue: ";
	cin.ignore(256,'\n');
	
	while (value == 1) {
		for (int i = 0; i < arrayLength; i++) {
			for (int j = 0; j < arrayWidth; j++) {
				if (array[i][j] != nullptr && array[i][j]->getAlreadyMoved() == false) {
					cout << "Got here" << endl;
					array[i][j]->move(&array, arrayLength, arrayWidth);
				}
			}
		}
		
		//print board
		print_board(array, arrayLength, arrayWidth);
		
		//reset already_moved flags back to false after all moves made
		reset_flags(&array, arrayLength, arrayWidth);
		
		//prompt for continue
		string input = "";
		cout << "Press enter to continue (n to quit): ";
		getline(cin, input);
		if (input == "n") {
			value = 0;
		}
	}
	
	//remove all data from memory
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			delete array[i][j];
		}
		delete [] array[i];
	}
	delete [] array;
	
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
				cout << "*";
			}
		}
		cout << "|" << endl;
	}
	for (int i = 0; i < arrayLength+2; i++) {
		cout << "-";
	}
	cout << endl;
}

void reset_flags(Critter ****array, int arrayLength, int arrayWidth) {
	for (int i = 0; i < arrayLength; i++) {
		for (int j = 0; j < arrayWidth; j++) {
			if ((*array)[i][j] != nullptr) {
				(*array)[i][j]->setAlreadyMoved(false);
			}
		}
	}
}