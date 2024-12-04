#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include "environment.h"

using namespace std;

bool gameOver;
const int width = 20;
const int height = 20;
int x, y, appleX, appleY, bananaX, bananaY, orangeX, orangeY, chocoX, chocoY, icecreamX, icecreamY, score;
int *tailX; // Pointer for dynamic tail X coordinates
int *tailY; // Pointer for dynamic tail Y coordinates
int nTail;
eDirection dir;

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    score = 0;

    // Initialize food positions
    appleX = rand() % (width - 2) + 1;
    appleY = rand() % (height - 2) + 1;
    bananaX = rand() % (width - 2) + 1;
    bananaY = rand() % (height - 2) + 1;
    orangeX = rand() % (width - 2) + 1;
    orangeY = rand() % (height - 2) + 1;
    chocoX = rand() % (width - 2) + 1;
    chocoY = rand() % (height - 2) + 1;
    icecreamX = rand() % (width - 2) + 1;
    icecreamY = rand() % (height - 2) + 1;

    // Initialize dynamic arrays for tail
    tailX = new int[100]; // Allocate memory for tail X coordinates
    tailY = new int[100]; // Allocate memory for tail Y coordinates
}

void Draw() {
    clear(); // Clear the screen

    // Draw top border
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    // Draw game area
    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                printw("#"); // Left border
            if (i == y && j == x)
                printw("O"); // Snake head
            else if (i == appleY && j == appleX)
                printw("A"); // Apple
            else if (i == bananaY && j == bananaX)
                printw("B"); // Banana
            else if (i == orangeY && j == orangeX)
                printw("O"); // Orange
            else if (i == chocoY && j == chocoX)
                printw("C"); // Chocolate
            else if (i == icecreamY && j == icecreamX)
                printw("I"); // Icecream
            else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        printw("o"); // Snake tail
                        print = true;
                    }
                }
                if (!print)
                    printw(" "); // Empty space
            }

            if (j == width - 1)
                printw("#"); // Right border
        }
        printw("\n");
    }

    // Draw bottom border
    for (int i = 0; i < width + 2; i++)
        printw("#");
    printw("\n");

    printw("Score: %d\n", score);
    refresh(); // Refresh the screen to show changes
}

