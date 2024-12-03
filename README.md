# COMP2113-Group-3-Project: Save Kai Tak 
**Ready to take off? Let’s see if you have what it takes to save Kai Tak! ✈**
- Watch the demo to get yourself started:

# Team Members 🧑‍💻👩‍💻 
- Bibi Hajirah (3036193578)
- Fatima-Tul-Zahra (3036217037)
- Khan Saahil Alam (3036073558)
- Syed Ali Mohamed Faisal (3035977068)

# Description ✈
**Save Kai Tak** is a text-based mini-game where players control a plane navigating through gaps between buildings, inspired by the mechanics of Flappy Bird. Set against an urban landscape, your objective is to avoid collisions and achieve the highest score.

**Your mission**: Skillfully maneuver your plane through obstacles while facing increasing difficulty and random events. Can you outsmart the challenges and claim the highest score?

# How to play? 🧐
In the main menu, you have the following options:
- **Start Game**: Jump right into the action.
- **Read Backstory**: ??
- **Choose Difficulty**: Select the right level to match your skills, from beginner to expert.
  
**Controls**
- **WASD Keys**: Use these keys to change your plane's direction, navigating the game area to collect points. When you reach the edge of the screen, you will appear on the opposite side.

**Compilation and Execution Instructions**: To play the game follow these simple steps:
1. Compile the game by typing: `make`
2. To start the game, enter:`./SaveKaiTak`. That's it!
3. (Optional) To clean up the project, run: `make clean`

# Features Implemented 🚀
Here’s what makes **Save Kai Tak** special:

**Random Generation of Random Events**
- Each game is unique with randomly generated building heights to create gaps for the plane to navigate through.

**Data Structures for Storing Data**
- Dynamic arrays are used to store high scores and building data, allowing for efficient memory management.

**Dynamic Memory Management**
- The game allocates and deallocates memory for high scores dynamically to optimize resource usage and prevent memory leaks.

**File Input/Output**
- High scores can be saved to and loaded from a text file, enabling persistent storage of player achievements.

**Program Codes in Multiple Files**
- The project is organized into multiple files, including:
  - `main.cpp`: Entry point of the game.
  - `game.h` and `game.cpp`: Core game logic mechanics.
  - `building.h` and `building.cpp`: Management of building generation.
  - `plane.h` and `plane.cpp`: Controls and mechanics for the plane.
  - `fileio.h` and `fileio.cpp`: Handles file input/output for saving and loading scores.

## Libraries 📖
No non-standard C/C++ libraries are used in this project. The code is compatible with standard libraries and does not require additional installations.
