#ifndef FILEIO_H
#define FILEIO_H

#include <string>
#include <vector>

// Functions to handle file I/O for the game
class FileIO {
public:
    // Saves the high scores to a file
    static void saveHighScores(const std::vector<int>& scores, const std::string& filename);

    // Loads the high scores from a file
    static std::vector<int> loadHighScores(const std::string& filename);

    // A utility function to display high scores
    static void displayHighScores(const std::vector<int>& scores);
};

#endif // FILEIO_H
