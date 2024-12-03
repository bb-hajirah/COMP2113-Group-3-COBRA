# Save Kai Tak
COMP2113 Group Project: Group 3

# Team Members
**Bibi Hajirah**: 3036193578,
**Fatima-Tul-Zahra**: 3036217037,
**Khan Saahil Alam**: ,
**Syed Ali Mohamed Faisal**:

# Description
**Save Kai Tak** is a text-based mini-game where players control a plane navigating through gaps between buildings, similar to Flappy Bird. The objective is to avoid collisions and achieve the highest score. With random events and increasing difficulty, the game offers engaging and challenging gameplay that emphasizes timing and precision.

# Features
The following features have been implemented in the game, fulfilling the coding requirements:

1. **Generation of Random Events**: 
   - Random building heights are generated to create gaps for the plane to navigate through.

2. **Data Structures for Storing Data**: 
   - Dynamic arrays are used to store high scores and building data, allowing for efficient memory management.

3. **Dynamic Memory Management**: 
   - The game allocates and deallocates memory for high scores dynamically to optimize resource usage and prevent memory leaks.

4. **File Input/Output**: 
   - High scores can be saved to and loaded from a text file, enabling persistent storage of player achievements.

5. **Program Codes in Multiple Files**: 
   - The project is organized into multiple files, including:
     - `main.cpp`: Entry point of the game.
     - `game.h` and `game.cpp`: Game logic implementation.
     - `building.h` and `building.cpp`: Building generation and management.
     - `plane.h` and `plane.cpp`: Plane mechanics.
     - `fileio.h` and `fileio.cpp`: File input/output operations.

## Libraries
No non-standard C/C++ libraries are used in this project. The code is compatible with standard libraries and does not require additional installations.

## Compilation and Execution Instructions with Makefile
A Makefile is included in the project to simplify the compilation process. To build and run the project, follow these steps:

1. **Clone the repository to your local machine:**
   ```bash
   git clone <repository-url>
   cd <repository-name>

2. **Compile the project:**
   ```bash
   make
   g++ main.cpp game.cpp building.cpp plane.cpp fileio.cpp -o SaveKaiTak

3. **Run the game:**
   ```bash
   ./SaveKaiTak
   
4. **Clean the Project:**
   ```bash
   make clean
