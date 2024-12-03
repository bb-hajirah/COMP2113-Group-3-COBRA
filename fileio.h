#ifndef FILEIO_H
#define FILEIO_H

#include <string>

// Functions to handle file I/O for the game
class FileIO {
public:
    // Saves the high scores to a file
    static void saveHighScores(int* scores, int size, const std::string& filename);

    // Loads the high scores from a file
    static int* loadHighScores(const std::string& filename, int& size);

    // A utility function to display high scores
    static void displayHighScores(int* scores, int size);
};

#endif // FILEIO_H
