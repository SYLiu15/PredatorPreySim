predPreyGame: main.o game.o grid.o doodlebug.o ant.o critter.o
	g++ -std=c++0x main.o game.o grid.o doodlebug.o ant.o critter.o -o predPreyGame

main.o: main.cpp
	g++ -std=c++0x -c main.cpp

game.o: game.cpp
	g++ -std=c++0x -c game.cpp

grid.o: grid.cpp grid.hpp
	g++ -std=c++0x -c grid.cpp

doodlebug.o: doodlebug.cpp doodlebug.hpp
	g++ -std=c++0x -c doodlebug.cpp

ant.o: ant.cpp ant.hpp
	g++ -std=c++0x -c ant.cpp

critter.o: critter.cpp critter.hpp
	g++ -std=c++0x -c critter.cpp

clean:
	rm *.o predPreyGame