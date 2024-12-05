# Makefile for COBRA++

# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -g -lncurses

# Source files
SRC = main.cpp environment.cpp game.cpp board.cpp

# Header files (optional, for reference)
HDR = environment.h game.h board.h

# Executable name
TARGET = COBRA++

# Build target
all: $(TARGET)

# Link the object files into the final executable
$(TARGET): $(SRC)
	$(CXX) $(SRC) -o $(TARGET) $(CXXFLAGS)

# Clean up the build
clean:
	rm -f $(TARGET) *.o
