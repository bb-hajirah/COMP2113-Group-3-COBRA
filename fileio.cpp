#include "fileio.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void FileIO::saveHighScores(const std::vector<int>& scores, const std::string& filename) {
    std::ofstream outFile(filename);
    if (outFile.is_open()) {
        for (const int score : scores) {
            outFile << score << std::endl; // Save each score on a new line
        }
        outFile.close();
        std::cout << "High scores saved to " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for writing: " << filename << std::endl;
    }
}

std::vector<int> FileIO::loadHighScores(const std::string& filename) {
    std::vector<int> scores;
    std::ifstream inFile(filename);
    if (inFile.is_open()) {
        int score;
        while (inFile >> score) {
            scores.push_back(score); // Read scores from file
        }
        inFile.close();
        std::cout << "High scores loaded from " << filename << std::endl;
    } else {
        std::cerr << "Unable to open file for reading: " << filename << std::endl;
    }
    return scores;
}

void FileIO::displayHighScores(const std::vector<int>& scores) {
    std::cout << "High Scores:" << std::endl;
    for (const int score : scores) {
        std::cout << score << std::endl; // Display each score
    }
}
