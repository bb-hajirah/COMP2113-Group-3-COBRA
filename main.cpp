#include "fileio.h"

int main() {
    // for fileio.h/cpp
    int* highScores; // pointer for storing high scores
    int size; // variable to hold the size of the scores array

    // load high scores at the start of the game
    highScores = FileIO::loadHighScores("highscores.txt", size);

    // after the game ends, save the new high scores
    FileIO::saveHighScores(highScores, size, "highscores.txt");

    // display high scores
    FileIO::displayHighScores(highScores, size);

    // cleanup: Free memory allocated for high scores
    delete[] highScores; // call this to prevent memory leaks

    return 0; // exit the program
}
