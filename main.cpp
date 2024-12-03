#include "fileio.h"

// Example usage
int* highScores;
int size;

// Load high scores at the start of the game
highScores = FileIO::loadHighScores("highscores.txt", size);

// After the game ends, save the new high scores
FileIO::saveHighScores(highScores, size, "highscores.txt");

// Display high scores
FileIO::displayHighScores(highScores, size);

// Cleanup
delete[] highScores; // Free memory when done
