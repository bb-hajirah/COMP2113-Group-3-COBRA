#ifndef BOARD_H
#define BOARD_H

#include <ncurses.h>

class Board {
public:
    Board(int width, int height);
    ~Board();
    void draw();
    void drawScore(int score); // Add this method to draw the score
    WINDOW* getWindow() const;
    WINDOW* getScoreWindow() const; // Add this method to get the score window

private:
    int width, height;
    int startX, startY;
    WINDOW* win;
    WINDOW* scoreWin; // Add a window for the score
};

#endif
