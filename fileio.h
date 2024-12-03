#ifndef FILEIO_H
#define FILEIO_H

#include <string>

// Functions to handle file I/O operation for the game
class FileIO {
public:
    // Saves the high scores to a file
    // scores: pointer to an array of integers representing high scores
    // size: number of scores in the array
    // filename: name of the file to save the scores to
    static void saveHighScores(int* scores, int size, const std::string& filename);

    // Loads the high scores from a file
    // filename: name of the file to load scores from
    // size: reference to an integer that will hold the number of scores loaded
    // Returns: pointer to an array of integers containing the loaded high scores
    static int* loadHighScores(const std::string& filename, int& size);

    // A utility function to display high scores to the console
    static void displayHighScores(int* scores, int size);
};

#endif // FILEIO_H
