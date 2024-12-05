#include "board.h"

Board::Board(int w, int h) : width(w), height(h) {
    startX = (COLS - width) / 2;
    startY = (LINES - height) / 2;

    win = newwin(height + 2, width + 2, startY, startX);
    scoreWin = newwin(3, width + 2, startY + height + 2, startX); // Create the score window below the board

    box(win, 0, 0);
    box(scoreWin, 0, 0); // Box the score window
    wrefresh(win);
    wrefresh(scoreWin); // Refresh the score window
}

Board::~Board() {
    delwin(win);
    delwin(scoreWin); // Clean up the score window
}

void Board::draw() {
    wrefresh(win);
}

void Board::drawScore(int score) {
    werase(scoreWin); // Clear the score window
    box(scoreWin, 0, 0); // Redraw the box around the score window
    mvwprintw(scoreWin, 1, 1, "Score: %d", score);
    wrefresh(scoreWin);
}

WINDOW* Board::getWindow() const {
    return win;
}

WINDOW* Board::getScoreWindow() const {
    return scoreWin; // Return the score window object
}
