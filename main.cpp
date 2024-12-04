#include <iostream>
#include <cstdlib>
#include <ncurses.h>
#include "environment.h"
#include "game.h"

void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;

    tailX[0] = x; // Update tail position
    tailY[0] = y;

    for (int i = 1; i < nTail; i++) {
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX; // Move tail positions forward
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir) {
        case LEFT:
            x--;
            break;
        case RIGHT:
            x++;
            break;
        case UP:
            y--;
            break;
        case DOWN:
            y++;
            break;
        default:
            break;
    }

    // Wrap around the screen edges
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y = 0; else if (y < 0) y = height - 1;

    for (int i = 0; i < nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true; // Check for self-collision

    // Check for collisions with food
    if (x == appleX && y == appleY) { // Check for apple collision
        score += 10;
        appleX = rand() % (width - 2) + 1; // Respawn apple
        appleY = rand() % (height - 2) + 1;
        nTail++; // Increase tail size
    }
    if (x == bananaX && y == bananaY) { // Check for banana collision
        score += 10;
        bananaX = rand() % (width - 2) + 1; // Respawn banana
        bananaY = rand() % (height - 2) + 1;
        nTail++; // Increase tail size
    }
    if (x == orangeX && y == orangeY) { // Check for orange collision
        score += 10;
        orangeX = rand() % (width - 2) + 1; // Respawn orange
        orangeY = rand() % (height - 2) + 1;
        nTail++; // Increase tail size
    }
    if (x == chocoX && y == chocoY) { // Check for chocolate collision
        score -= 5;
        chocoX = rand() % (width - 2) + 1; // Respawn chocolate
        chocoY = rand() % (height - 2) + 1;
    }
    if (x == icecreamX && y == icecreamY) { // Check for ice cream collision
        score -= 5;
        icecreamX = rand() % (width - 2) + 1; // Respawn ice cream
        icecreamY = rand() % (height - 2) + 1;
    }
}

void Input() {
    keypad(stdscr, TRUE); // Enable special keys to be captured
    halfdelay(1); // Wait for input for a short time

    int c = getch(); // Get user input
    switch (c) {
        case KEY_LEFT:
            dir = LEFT;
            break;
        case KEY_RIGHT:
            dir = RIGHT;
            break;
        case KEY_UP:
            dir = UP;
            break;
        case KEY_DOWN:
            dir = DOWN;
            break;
        case 'q':
            gameOver = true; // Exit game
            break;
    }
}
