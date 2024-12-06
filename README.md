# COMP2113-Group-3-Project: COBRA++ 🐍🍏
**Ready to embark on a healthy adventure? Let’s see if you have what it takes to guide Cobra to a healthier diet! 🌟**
- Watch the demo to get yourself started:

# Team Members 🧑‍💻👩‍💻 
- Bibi Hajirah (3036193578)
- Fatima-Tul-Zahra (3036217037)
- Khan Saahil Alam (3036073558)
- Syed Ali Mohamed Faisal (3035977068)

# Description 🌱
**COBRA++** is an educational text-based snake game where players control a cobra navigating through a world of food. Your objective is to eat healthy foods like apples, bananas, and oranges to earn points, while avoiding unhealthy options like ice cream and chocolate, which will deduct points.

**Your mission**: Help Cobra learn about healthy eating habits while having fun! This game addresses the rising issue of childhood obesity and diet problems by promoting a gamified approach to learning about nutrition.

# How to play? 🧐
In the main menu, you have the following options:
- **Start Game**: Jump right into the action and guide Cobra through the food maze.
- **Read Backstory**: Learn about Cobra’s journey towards a healthy lifestyle.
- **Instructions**
- **Exit**
  
**Controls**
- **Arrow Keys**: Use the up, down, left, and right arrow keys to change Cobra's direction and navigate the game area. When you reach the edge of the screen, you will appear on the opposite side.

**Compilation and Execution Instructions**: To play the game follow these simple steps:
1. Compile the game by typing: `make`
2. To start the game, enter:`./COBRA++`. That's it!
3. (Optional) If you prefer to compile manually, use the following command: `g++ main.cpp environment.cpp game.cpp board.cpp -o COBRA++ -lncurses`

# Features Implemented 🚀
Here’s what makes **COBRA++** special:

- **Nutritional Education**: Players learn about healthy eating habits as they collect nutritious foods and avoid unhealthy options.
- **Dynamic Food Generation**: Each game is unique with randomly generated food items, providing a fresh experience every time you play.
- **Score Tracking**: Players earn points for healthy food consumption and lose points for unhealthy choices, reinforcing positive dietary habits.
- **Multiple Game Levels**: Difficulty increases as players progress, offering a challenging and engaging experience for all skill levels.

  
**Program Codes in Multiple Files**
- The project is organized into multiple files:
- **`main.cpp`**: Entry point of the game.
- **`environment.h` and `environment.cpp`**: Manages the game environment and rendering.
- **`game.h` and `game.cpp`**: Contains the core game logic and mechanics.
- **`board.h` and `board.cpp`**: Handles the game board, including drawing and updating the game state.
- **`Makefile`**: Automates the build process for compiling the project.

## Libraries 📖
No non-standard C/C++ libraries are used in this project. The code is compatible with standard libraries and does not require additional installations.

## Acknowledgment 🙏
We took inspiration from [Youtube video](https://www.youtube.com/watch?v=E_-lMZDi7Uw) by NVitanovic to understand the basic structure of the game.
