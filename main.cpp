#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include "environment.h"
#include "game.h"

int main() {
    initscr();          // Start ncurses mode
    noecho();           // Don't echo pressed keys
    cbreak();           // Disable line buffering
    curs_set(0);        // Hide the cursor

    Setup();

    while (!gameOver) {
        Draw();
        Input();
        Logic();
        usleep(100000); // Sleep to control speed of the game
    }

    // Clean up: free dynamically allocated memory
    delete[] tailX;
    delete[] tailY;

    endwin();          // End ncurses mode and clean up

    return 0;
}
