#------------------------------------------------------------------------------
#  Makefile for Maze Generator Program
#
#  make                     makes Generate executable
#  make clean               removes all binaries
#------------------------------------------------------------------------------

MAIN           			   = Generate
DISJOINT_SET           = DisjointSet
MAZE_GENERATOR         = MazeGenerator
LOGGER                 = Logger
LOGGER_HEADER          = ../Logger/$(LOGGER).h
LOGGER_SOURCE          = ../Logger/$(LOGGER).cpp
LOGGER_OBJECT  				 = $(LOGGER).o
SOURCE								 = $(MAIN).cpp
OBJECT								 = $(MAIN).o
DISJOINT_SET_HEADER    = $(DISJOINT_SET).h
DISJOINT_SET_SOURCE    = $(DISJOINT_SET).cpp
DISJOINT_SET_OBJECT    = $(DISJOINT_SET).o
MAZE_GENERATOR_HEADER  = $(MAZE_GENERATOR).h
MAZE_GENERATOR_SOURCE  = $(MAZE_GENERATOR).cpp
MAZE_GENERATOR_OBJECT  = $(MAZE_GENERATOR).o
COMPILE                = g++ -Wall -g -std=c++17 -c
LINK						       = g++ -Wall -g -std=c++17 -o
MEMCHECK               = valgrind --leak-check=full
CLEAN 								 = rm -f $(MAIN) *.o *~ *.txt *.out

$(MAIN): $(OBJECT) $(MAZE_GENERATOR_OBJECT) $(DISJOINT_SET_OBJECT) $(LOGGER_OBJECT)
	$(LINK) $(MAIN) $(OBJECT) $(MAZE_GENERATOR_OBJECT) $(DISJOINT_SET_OBJECT) $(LOGGER_OBJECT)

$(OBJECT): $(SOURCE) $(MAZE_GENERATOR_HEADER) $(LOGGER_HEADER)
	$(COMPILE) $(SOURCE)

$(MAZE_GENERATOR_OBJECT): $(MAZE_GENERATOR_SOURCE) $(MAZE_GENERATOR_HEADER) $(DISJOINT_SET_HEADER)
	$(COMPILE) $(MAZE_GENERATOR_SOURCE)

$(DISJOINT_SET_OBJECT): $(DISJOINT_SET_SOURCE) $(DISJOINT_SET_HEADER) $(LOGGER_HEADER)
	$(COMPILE) $(DISJOINT_SET_SOURCE)

$(LOGGER_OBJECT): $(LOGGER_SOURCE) $(LOGGER_HEADER)
	$(COMPILE) $(LOGGER_SOURCE)

clean:
	$(CLEAN)
