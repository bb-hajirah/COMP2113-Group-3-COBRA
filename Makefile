# Makefile for COBRA++ game

CXX = g++
CXXFLAGS = -pedantic-errors -std=c++11
LDFLAGS = -lncurses

# Targets
all: COBRA++

# Compile and link all source files into the executable
COBRA++: main.cpp environment.cpp game.cpp board.cpp
	$(CXX) $(CXXFLAGS) main.cpp environment.cpp game.cp    p board.cpp -o COBRA++ $(LDFLAGS)

# Clean target to remove generated files
clean:
	rm -f COBRA++

.PHONY: clean
