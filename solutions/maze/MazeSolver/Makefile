#------------------------------------------------------------------------------
#  Makefile for Maze Solver Program
#
#  make                     makes Solver executable
#  make clean               removes all binaries
#------------------------------------------------------------------------------

MAIN       			    = Solver
LINKED_LIST         = LinkedList
QUEUE               = Queue
MAZE_SOLVER         = MazeSolver
LOGGER              = Logger
LOGGER_HEADER       = ../Logger/$(LOGGER).h
LOGGER_SOURCE       = ../Logger/$(LOGGER).cpp
LOGGER_OBJECT  		  = $(LOGGER).o
SOURCE					    = $(MAIN).cpp
OBJECT							= $(MAIN).o
MAZE_SOLVER_HEADER  = $(MAZE_SOLVER).h
MAZE_SOLVER_SOURCE  = $(MAZE_SOLVER).cpp
MAZE_SOLVER_OBJECT  = $(MAZE_SOLVER).o
LINKED_LIST_HEADER  = $(LINKED_LIST).h
QUEUE_HEADER        = $(QUEUE).h
COMPILE             = g++ -Wall -g -std=c++17 -c
LINK				        = g++ -Wall -g -std=c++17 -o
MEMCHECK            = valgrind --leak-check=full
CLEAN 						  = rm -f $(MAIN) *.o *~ *.txt *.out

$(MAIN): $(OBJECT) $(MAZE_SOLVER_OBJECT) $(LOGGER_OBJECT)
	$(LINK) $(MAIN) $(OBJECT) $(MAZE_SOLVER_OBJECT) $(LOGGER_OBJECT)

$(OBJECT): $(SOURCE) $(MAZE_SOLVER_HEADER) $(LOGGER_HEADER)
	$(COMPILE) $(SOURCE)

$(MAZE_SOLVER_OBJECT): $(MAZE_SOLVER_SOURCE) $(MAZE_SOLVER_HEADER) $(QUEUE_HEADER) $(LINKED_LIST_HEADER)
	$(COMPILE) $(MAZE_SOLVER_SOURCE)

$(LOGGER_OBJECT): $(LOGGER_SOURCE) $(LOGGER_HEADER)
	$(COMPILE) $(LOGGER_SOURCE)

clean:
	$(CLEAN)
