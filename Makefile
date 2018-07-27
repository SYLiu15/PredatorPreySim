PROG = simulation
CXX = g++
CXXFLAGS = -std=c++11
CXXFLAGS += -Wall
CXXFLAGS += -pedantic-errors
CXXFLAGS += -g

OBJS = main.o ant.o critter.o doodlebug.o
SRCS = main.cpp ant.cpp critter.cpp doodlebug.cpp

HEADERS = ant.hpp critter.hpp doodlebug.hpp

${PROG}: ${OBJS}
	${CXX} ${OBJS} -o ${PROG}

${OBJS}: ${SRCS} ${HEADERS}
	${CXX} ${CXXFLAGS} -c $(@:.o=.cpp)

clean:
	rm *.o ${PROG}
