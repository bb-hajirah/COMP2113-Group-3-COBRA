#include <iostream>
#include <ncurses.h>
#include <cstdlib>
#include <unistd.h>
#include "environment.h"

using namespace std;

bool gameOver;
const int width = 40;
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

void Draw(WINDOW* win) {
    werase(win); // Clear the window

    // Draw top border
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, 0, 0, "+");
    for (int i = 0; i < width; i++)
        mvwprintw(win, 0, i + 1, "-");
    mvwprintw(win, 0, width + 1, "+");
    wattroff(win, COLOR_PAIR(1));

    // Draw game area
    for (int i = 0; i < height; i++) {
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, i + 1, 0, "|"); // Left border
        wattroff(win, COLOR_PAIR(1));
        for (int j = 0; j < width; j++) {
            if (i == y && j == x) {
                wattron(win, COLOR_PAIR(2));
                mvwprintw(win, i + 1, j + 1, "O"); // Snake head
                wattroff(win, COLOR_PAIR(2));
            } else if (i == appleY && j == appleX) {
                wattron(win, COLOR_PAIR(3));
                mvwprintw(win, i + 1, j + 1, "A"); // Apple
                wattroff(win, COLOR_PAIR(3));
            } else if (i == bananaY && j == bananaX) {
                wattron(win, COLOR_PAIR(4));
                mvwprintw(win, i + 1, j + 1, "B"); // Banana
                wattroff(win, COLOR_PAIR(4));
            } else if (i == orangeY && j == orangeX) {
                wattron(win, COLOR_PAIR(5));
                mvwprintw(win, i + 1, j + 1, "O"); // Orange
                wattroff(win, COLOR_PAIR(5));
            } else if (i == chocoY && j == chocoX) {
                wattron(win, COLOR_PAIR(6));
                mvwprintw(win, i + 1, j + 1, "C"); // Chocolate
                wattroff(win, COLOR_PAIR(6));
            } else if (i == icecreamY && j == icecreamX) {
                wattron(win, COLOR_PAIR(7));
                mvwprintw(win, i + 1, j + 1, "I"); // Icecream
                wattroff(win, COLOR_PAIR(7));
            } else {
                bool print = false;
                for (int k = 0; k < nTail; k++) {
                    if (tailX[k] == j && tailY[k] == i) {
                        wattron(win, COLOR_PAIR(2));
                        mvwprintw(win, i + 1, j + 1, "o"); // Snake tail
                        wattroff(win, COLOR_PAIR(2));
                        print = true;
                    }
                }
                if (!print) {
                    mvwprintw(win, i + 1, j + 1, " "); // Empty space
                }
            }
        }
        wattron(win, COLOR_PAIR(1));
        mvwprintw(win, i + 1, width + 1, "|"); // Right border
        wattroff(win, COLOR_PAIR(1));
    }

    // Draw bottom border
    wattron(win, COLOR_PAIR(1));
    mvwprintw(win, height + 1, 0, "+");
    for (int i = 0; i < width; i++)
        mvwprintw(win, height + 1, i + 1, "-");
    mvwprintw(win, height + 1, width + 1, "+");
    wattroff(win, COLOR_PAIR(1));

    // Draw the score below the game area
    mvwprintw(win, height + 2, 0, "Score: %d", score);
    wrefresh(win); // Refresh the window to show changes
}
